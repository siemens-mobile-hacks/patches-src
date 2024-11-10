SECTIONS {
    .OpenDisksMenu 0xA17E03A0 : {
        KEEP(*(.text.OpenDisksMenu))
        KEEP(*(.rodata*))
    }
    .OpenDisksMenu_Jump 0xA0985080 : {
        KEEP(*(.text.OpenDisksMenu_Jump))
    }
}
