SECTIONS {
    .Jump 0xA029D1F0 : {
        KEEP(*(.text.Jump))
    }
    .Hook 0xA0209270 : {
        KEEP(*(.text.Hook))
    }
}
