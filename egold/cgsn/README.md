# CGSN Debugger patch

## Requirements

- Python 3
- Wine (Linux only)
- [Keil C166](https://www.keil.com/demo/eval/c166.htm) installed at
  `C:\Keil_v5\c166\bin`
- [ptr89](https://github.com/siemens-mobile-hacks/ptr89) in `PATH`
- Original target fullflash

## Build an existing target

Available targets are stored in `target/`.

```bash
./build.py M55v91 /path/to/M55_v91.bin
```

Output:

```text
build/M55v91/cgsn_M55v91.vkp
```

The fullflash version must match the selected target.

## Add a new target

First choose `PatchAddress`: an even runtime address of a safe `0xFF`-filled
area large enough for the patch (currently about `0x4E2` bytes plus headroom).

```bash
./port.py M55v91 /path/to/M55_v91.bin --base 0x200000 --set PatchAddress=0x506FEE
```

This creates `target/M55v91.json`. If a pattern is missing or ambiguous, pass
the requested address explicitly:

```bash
./port.py M55v91 /path/to/M55_v91.bin --base 0x200000 --set PatchAddress=0x506FEE --set AT_AddAnsw=0xC3C484
```

Then build it with `build.py`.

## Address spaces

```text
CPU address     = VKP file offset + FirmwareBase
VKP file offset = CPU address - FirmwareBase
```

Function addresses and `PatchAddress` are CPU addresses. `AddrInTable` is a
VKP file offset. `FirmwareBase` is stored in the target JSON and can be found
with [Smelter](https://web.archive.org/web/20090414122112/http://avkiev.kiev.ua/Siemens/Smelter/Smelter.htm).
Old VKP bytes are always read from the supplied fullflash.
