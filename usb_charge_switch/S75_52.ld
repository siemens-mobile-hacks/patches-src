SECTIONS {
    .Accessories 0xA1482300 : {
        KEEP(*(.data.Accesories))
    }
    .Hooks 0xA14823A0 : {
        KEEP(*(.text.Hook_1))
        KEEP(*(.text.Hook_2))
    }
    .Jump_1 0xA026193C : {
        KEEP(*(.text.Jump_1))
    }
    .Jump_2 0xA01FD850 : {
        KEEP(*(.text.Jump_2))
    }
}
