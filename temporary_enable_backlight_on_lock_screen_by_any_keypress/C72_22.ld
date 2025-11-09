SECTIONS {
    .Hook 0xA0924E2C : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA090298A : {
        KEEP(*(.text.Jump))
    }
}
