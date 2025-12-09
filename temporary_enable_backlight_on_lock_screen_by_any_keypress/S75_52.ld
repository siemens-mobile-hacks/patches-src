SECTIONS {
    .Hook_1 0xA03319A4 : {
        KEEP(*(.text.Hook_1))
    }
    .Jump_1 0xA0346372 : {
        KEEP(*(.text.Jump_1))
    }
    .Hook_2 0xA0330414 : {
        KEEP(*(.text.Hook_2))
    }
    .Jump_2 0xA03021F0 : {
        KEEP(*(.text.Jump_2))
    }
}
