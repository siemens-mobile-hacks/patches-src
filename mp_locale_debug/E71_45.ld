SECTIONS {
    .Hook 0xA0073700 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA08D5F3C : {
        KEEP(*(.text.Jump))
    }
}
