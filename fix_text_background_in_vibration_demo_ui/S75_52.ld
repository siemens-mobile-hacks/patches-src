SECTIONS {
    .Hook 0xA0A746D0 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA0A18EBA : {
        KEEP(*(.text.Jump))
    }
}
