SECTIONS {
    .Hook_1 0xA06EBA48 : {
        KEEP(*(.text.Hook_1))
    }
    .Jump_1 0xA0702B46 : {
        KEEP(*(.text.Jump_1))
    }
    .Hook_2 0xA06EA424 : {
        KEEP(*(.text.Hook_2))
    }
    .Jump_2 0xA05C2B36 : {
        KEEP(*(.text.Jump_2))
    }
}
