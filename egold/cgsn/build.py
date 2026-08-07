#!/usr/bin/env python3

import argparse
import json
import os
import re
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parent
TARGET_DIR = ROOT / "target"
ASM_TEMPLATE = ROOT / "cgsn.asm.in"
KEIL_BIN = r"C:\Keil_v5\c166\bin"


def load_target(name):
    path = TARGET_DIR / f"{name}.json"
    if not path.is_file():
        names = ", ".join(sorted(item.stem for item in TARGET_DIR.glob("*.json")))
        raise SystemExit(f"Unknown target {name!r}. Available targets: {names}")

    with path.open(encoding="utf-8") as file:
        target = json.load(file)
    return target


def keil_hex(value):
    return f"0{int(value, 0):X}h"


def render_asm(target):
    values = {
        "MODEL": target["model"],
        "VERSION": target["version"],
        **{name: keil_hex(value) for name, value in target["symbols"].items()},
        **{name: keil_hex(value) for name, value in target["constants"].items()},
    }

    source = ASM_TEMPLATE.read_text(encoding="utf-8")
    for name, value in values.items():
        source = source.replace("{{" + name + "}}", value)

    unresolved = sorted(set(re.findall(r"{{([^{}]+)}}", source)))
    if unresolved:
        raise SystemExit("Unknown ASM template values: " + ", ".join(unresolved))
    return source


def windows_path(path):
    if os.name == "nt":
        return str(path.resolve())
    return subprocess.check_output(
        ["winepath", "-w", str(path.resolve())],
        text=True,
    ).strip()


def run_keil(tool, *arguments, check=True):
    executable = rf"{KEIL_BIN}\{tool}"
    if os.name == "nt":
        command = [executable, *arguments]
    else:
        command = ["wine", executable, *arguments]
    return subprocess.run(command, check=check).returncode


def assemble(target_name, target):
    build_dir = ROOT / "build" / target_name
    build_dir.mkdir(parents=True, exist_ok=True)

    base_name = f"CGSN_{target_name.upper()}"
    asm = build_dir / f"{base_name}.ASM"
    obj = build_dir / f"{base_name}.OBJ"
    listing = build_dir / f"{base_name}.LST"
    absolute = build_dir / f"{base_name}.ABS"
    h86 = build_dir / f"{base_name}.H86"

    for path in build_dir.glob(f"{base_name}.*"):
        path.unlink()
    asm.write_text(render_asm(target), encoding="ascii")

    print(f"[1/3] A166: {asm.name}", flush=True)
    status = run_keil(
        "A166.EXE",
        windows_path(asm),
        f"OBJECT({windows_path(obj)})",
        f"PRINT({windows_path(listing)})",
        "ERRORPRINT",
        check=False,
    )
    if not obj.is_file():
        raise SystemExit(f"A166 failed with status {status}")
    if status:
        print(f"A166 returned status {status}; object file was created, continuing")

    print("[2/3] L166", flush=True)
    run_keil("L166.EXE", windows_path(obj), "TO", windows_path(absolute))
    if not absolute.is_file():
        raise SystemExit("L166 did not create an ABS file")

    print("[3/3] OH166", flush=True)
    run_keil("OH166.EXE", windows_path(absolute), "H167")
    if not h86.is_file():
        raise SystemExit("OH166 did not create an H86 file")
    return h86


def read_ihex(path):
    records = []
    base = 0

    for line_number, line in enumerate(path.read_text(encoding="ascii").splitlines(), 1):
        if not line:
            continue
        try:
            raw = bytes.fromhex(line.removeprefix(":"))
        except ValueError as error:
            raise SystemExit(f"{path}:{line_number}: invalid Intel HEX") from error
        if not line.startswith(":") or len(raw) < 5 or len(raw) != raw[0] + 5:
            raise SystemExit(f"{path}:{line_number}: invalid Intel HEX record")
        if sum(raw) & 0xFF:
            raise SystemExit(f"{path}:{line_number}: checksum mismatch")

        size = raw[0]
        offset = int.from_bytes(raw[1:3], "big")
        record_type = raw[3]
        data = raw[4 : 4 + size]

        if record_type == 0x00:
            records.append((base + offset, data))
        elif record_type == 0x01:
            break
        elif record_type == 0x02:
            base = int.from_bytes(data, "big") << 4
        elif record_type == 0x04:
            base = int.from_bytes(data, "big") << 16

    return records


def read_original(firmware, offset, size):
    end = offset + size
    if offset < 0 or end > len(firmware):
        raise SystemExit(
            f"VKP range 0x{offset:X}..0x{end - 1:X} is outside the fullflash"
        )
    return firmware[offset:end]


def far_pointer(address):
    offset = address & 0xFFFF
    segment = (address >> 16) & 0xFFFF
    return offset.to_bytes(2, "little") + segment.to_bytes(2, "little")


def write_vkp(target_name, target, records, firmware_path):
    firmware_base = int(target["FirmwareBase"], 0)
    symbols = {name: int(value, 0) for name, value in target["symbols"].items()}
    table_address = symbols["AddrInTable"]
    patch_address = symbols["PatchAddress"]
    firmware = firmware_path.read_bytes()
    output = ROOT / "build" / target_name / f"cgsn_{target_name}.vkp"
    output.parent.mkdir(parents=True, exist_ok=True)

    original_hook = read_original(firmware, table_address, 4)
    expected_hook = far_pointer(symbols["OrigATHandle"])
    if original_hook != expected_hook:
        raise SystemExit(
            f"Wrong fullflash or AddrInTable: found {original_hook.hex().upper()} "
            f"at 0x{table_address:X}, expected {expected_hook.hex().upper()}"
        )

    lines = [
        f"; CGSN_Debugger patch for {target['model']} sv{target['version']}",
        ";---------------------------------",
        "",
        f";Firmware: {target['model']}v{target['version']}",
        ";Authors: KonstanT, ValeraVi, SiNgle",
        "",
    ]

    wrote_table = False
    wrote_patch_header = False
    old_equal_ff = False
    patch_end = patch_address

    for address, data in records:
        if address == table_address:
            file_offset = address
            wrote_table = True
        else:
            if address < patch_address:
                raise SystemExit(f"Unexpected H86 address 0x{address:X}")
            file_offset = address - firmware_base
            if not wrote_patch_header:
                lines.append(
                    f";---- New block. Segment address:{file_offset & 0xFF0000:06X}--------"
                )
                wrote_patch_header = True
            patch_end = max(patch_end, address + len(data))

        old_data = read_original(firmware, file_offset, len(data))
        if address == table_address:
            if old_equal_ff:
                lines.append("#pragma disable old_equal_ff")
                old_equal_ff = False
            lines.append(
                f"{file_offset:08X}: {old_data.hex().upper()} {data.hex().upper()}"
            )
        else:
            if any(byte != 0xFF for byte in old_data):
                raise SystemExit(
                    f"Patch space is not empty at fullflash offset 0x{file_offset:X}"
                )
            if not old_equal_ff:
                lines.append("#pragma enable old_equal_ff")
                old_equal_ff = True
            lines.append(f"{file_offset:08X}: {data.hex().upper()}")

    if not wrote_table or not wrote_patch_header:
        raise SystemExit("H86 does not contain both the table hook and patch code")
    if old_equal_ff:
        lines.append("#pragma disable old_equal_ff")

    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(
        f"[done] {output.relative_to(ROOT)}: "
        f"runtime 0x{patch_address:X}..0x{patch_end - 1:X}"
    )


def main():
    parser = argparse.ArgumentParser(description="Build the CGSN patch with Keil C166")
    parser.add_argument("target", help="target name, for example M55v91")
    parser.add_argument("fullflash", type=Path, help="original target fullflash")
    args = parser.parse_args()

    if not args.fullflash.is_file():
        raise SystemExit(f"Fullflash not found: {args.fullflash}")

    target = load_target(args.target)
    h86 = assemble(args.target, target)
    write_vkp(args.target, target, read_ihex(h86), args.fullflash)


if __name__ == "__main__":
    main()
