#!/usr/bin/env python3

import argparse
import json
import re
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parent
PATTERNS_FILE = ROOT / "patterns" / "cgsn.json"
TARGET_DIR = ROOT / "target"
STACK_SIZE = 0x46

SYMBOLS = (
    "GetArgPointer",
    "ATEmptyBuffer",
    "AT_AddAnsw",
    "ATSendBufferToSerialPort",
    "AT_SayResult",
    "IPCopyStringZ",
    "OrigATHandle",
    "AddrInTable",
    "PatchAddress",
)


def parse_overrides(items):
    values = {}
    for item in items:
        if "=" not in item:
            raise SystemExit(f"Invalid --set {item!r}; expected NAME=0xADDRESS")
        name, value = item.split("=", 1)
        if name not in SYMBOLS:
            raise SystemExit(f"Unknown target symbol {name!r}")
        if name in values:
            raise SystemExit(f"Duplicate --set for {name}")
        try:
            values[name] = int(value, 0)
        except ValueError as error:
            raise SystemExit(f"Invalid address for {name}: {value}") from error
    return values


def parse_target(name):
    match = re.fullmatch(r"(.+)v([0-9]+)", name, re.IGNORECASE)
    if not match:
        raise SystemExit(f"Invalid target {name!r}; expected a name like M55v91")
    return match.groups()


def run_patterns(fullflash, patterns, firmware_base):
    command = [
        "ptr89",
        "-f",
        str(fullflash),
        "-b",
        f"{firmware_base:X}",
        "-a",
        "2",
        "-n",
        "20",
        "-J",
    ]
    for pattern in patterns.values():
        command.extend(("-p", pattern))

    try:
        result = subprocess.run(command, check=True, text=True, capture_output=True)
    except FileNotFoundError as error:
        raise SystemExit("ptr89 was not found in PATH") from error
    except subprocess.CalledProcessError as error:
        message = error.stderr.strip() or error.stdout.strip()
        raise SystemExit(f"ptr89 failed: {message}") from error

    report = json.loads(result.stdout)
    reported = report.get("patterns", [])
    if len(reported) != len(patterns):
        raise SystemExit("ptr89 returned an incomplete pattern report")

    found = {}
    for name, item in zip(patterns, reported, strict=True):
        found[name] = [entry["address"] for entry in item.get("results", [])]
    return found


def decode_far_pointer(data):
    offset = int.from_bytes(data[:2], "little")
    segment = int.from_bytes(data[2:4], "little")
    return (segment << 16) | offset


def read_bytes(fullflash, offset, size, description):
    if offset < 0:
        raise SystemExit(f"Invalid negative file offset for {description}")
    with fullflash.open("rb") as file:
        file.seek(offset)
        data = file.read(size)
    if len(data) != size:
        raise SystemExit(f"Fullflash is too short to read {description} at 0x{offset:X}")
    return data


def resolve_symbols(fullflash, matches, overrides, firmware_base):
    values = dict(overrides)
    unresolved = []

    for name, value in overrides.items():
        print(f"supplied {name:<28} 0x{value:X}")

    for name in SYMBOLS:
        if name in values or name in ("OrigATHandle", "AddrInTable", "PatchAddress"):
            continue
        results = matches.get(name, [])
        if len(results) == 1:
            values[name] = results[0]
            print(f"found    {name:<28} 0x{results[0]:X}")
        else:
            print(f"unresolved {name:<25} matches={len(results)}")
            unresolved.append(name)

    if "AddrInTable" not in values:
        table_matches = matches.get("_GSNTable", [])
        if len(table_matches) == 1:
            gsn_file_offset = table_matches[0] - firmware_base
            values["AddrInTable"] = gsn_file_offset + 0x0C
            print(f"found    {'AddrInTable':<28} 0x{values['AddrInTable']:X}")
        else:
            print(f"unresolved {'AddrInTable':<25} matches={len(table_matches)}")
            unresolved.append("AddrInTable")

    if "OrigATHandle" not in values and "AddrInTable" in values:
        pointer = read_bytes(
            fullflash,
            values["AddrInTable"],
            4,
            "original CGSN handler",
        )
        values["OrigATHandle"] = decode_far_pointer(pointer)
        print(f"decoded  {'OrigATHandle':<28} 0x{values['OrigATHandle']:X}")

    if "PatchAddress" not in values:
        unresolved.append("PatchAddress")

    unresolved = sorted(set(name for name in unresolved if name not in values))
    if unresolved:
        arguments = " ".join(f"--set {name}=0x..." for name in unresolved)
        raise SystemExit(f"Missing or ambiguous addresses; provide: {arguments}")
    return values


def write_target(model, version, firmware_base, values, force):
    output = TARGET_DIR / f"{model}v{version}.json"
    if output.exists() and not force:
        raise SystemExit(f"Target already exists: {output}; use --force to replace it")

    target = {
        "model": model,
        "version": version,
        "FirmwareBase": f"0x{firmware_base:X}",
        "symbols": {name: f"0x{values[name]:X}" for name in SYMBOLS},
        "constants": {"StkSize": f"0x{STACK_SIZE:X}"},
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(target, indent=2) + "\n", encoding="utf-8")
    print(f"written  {output.relative_to(ROOT)}")


def main():
    parser = argparse.ArgumentParser(description="Generate a CGSN target JSON")
    parser.add_argument("target", help="target name, for example M55v91")
    parser.add_argument("fullflash", type=Path, help="original fullflash")
    parser.add_argument(
        "--base",
        type=lambda value: int(value, 0),
        required=True,
        help="CPU address corresponding to fullflash offset 0",
    )
    parser.add_argument(
        "--set",
        action="append",
        default=[],
        metavar="NAME=ADDRESS",
        help=(
            "supply or override a symbol; function and PatchAddress values are "
            "runtime addresses, AddrInTable is a VKP file offset"
        ),
    )
    parser.add_argument("--force", action="store_true")
    args = parser.parse_args()

    if not args.fullflash.is_file():
        raise SystemExit(f"Fullflash not found: {args.fullflash}")

    model, version = parse_target(args.target)
    patterns = json.loads(PATTERNS_FILE.read_text(encoding="utf-8"))
    overrides = parse_overrides(args.set)
    matches = run_patterns(args.fullflash, patterns, args.base)
    values = resolve_symbols(args.fullflash, matches, overrides, args.base)

    write_target(model, version, args.base, values, args.force)


if __name__ == "__main__":
    main()
