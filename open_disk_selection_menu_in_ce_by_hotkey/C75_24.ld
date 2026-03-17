SECTIONS {
    .OpenDisksMenu 0xA01E096A : {
        KEEP(*(.rodata*))
        KEEP(*(.text.OpenDisksMenu))
    }
    .OpenDisksMenu_Jump 0xA034C0A8 : {
        KEEP(*(.text.OpenDisksMenu_Jump))
    }
}
