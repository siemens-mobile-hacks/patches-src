SECTIONS {
    .Hook 0xA1382A00 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA06A9724 : {
        KEEP(*(.text.Jump))
    }
}
