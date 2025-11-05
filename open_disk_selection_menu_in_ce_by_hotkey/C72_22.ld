SECTIONS {
    .OpenDisksMenu 0xA17E096A : {
        KEEP(*(.rodata*))
        KEEP(*(.text.OpenDisksMenu))
    }
    .OpenDisksMenu_Jump 0xA09A0158 : {
        KEEP(*(.text.OpenDisksMenu_Jump))
    }
}
