SECTIONS {
    .Accessories 0xA1381500 : {
        KEEP(*(.data.Accesories))
    }
    .Hooks 0xA13815A0 : {
        KEEP(*(.text.Hook_1))
        KEEP(*(.text.Hook_2))
    }
    .Jump 0xA057C0EC : {
        KEEP(*(.text.Jump_1))
    }
    .Jump_2 0xA01AB7AC : {
        KEEP(*(.text.Jump_2))
    }
}
