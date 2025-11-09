SECTIONS {
    .Hook 0xA08CB3A0 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA08E17A4 : {
        KEEP(*(.text.Jump))
    }
}
