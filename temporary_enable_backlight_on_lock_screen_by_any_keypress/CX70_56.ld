SECTIONS {
    .Hook 0xA17E0A00 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA172297E : {
        KEEP(*(.text.Jump))
    }
}
