SECTIONS {
    .Hook 0xA17E0A00 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA16A2AD2 : {
        KEEP(*(.text.Jump))
    }
}
