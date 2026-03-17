SECTIONS {
    .Hook 0xA032AE38 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA033EE1A : {
        KEEP(*(.text.Jump))
    }
}
