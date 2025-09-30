SECTIONS {
    .OpenDisksMenu 0xA01E096A : {
        KEEP(*(.rodata*))
        KEEP(*(.text.OpenDisksMenu))
    }
    .OpenDisksMenu_Jump 0xA03568F0 : {
        KEEP(*(.text.OpenDisksMenu_Jump))
    }
}
