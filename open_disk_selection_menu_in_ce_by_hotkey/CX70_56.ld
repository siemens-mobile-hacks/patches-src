SECTIONS {
    .OpenDisksMenu 0xA17E096A : {
        KEEP(*(.rodata*))
        KEEP(*(.text.OpenDisksMenu))
    }
    .OpenDisksMenu_Jump 0xA0991384 : {
        KEEP(*(.text.OpenDisksMenu_Jump))
    }
}
