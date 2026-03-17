SECTIONS {
    .rodata 0xA11D4D00 : {
        KEEP(*(.rodata*))
    }
    .CreateOrClose 0xA11D4D20 : {
        KEEP(*(.text.CreateOrClose))
    }
    .Hooks 0xA11D4D60 : {
        KEEP(*(.text.Hook_1))
        KEEP(*(.text.Hook_2))
    }
    .Jump_1 0xA04BAC80 : {
        KEEP(*(.data.Jump_1))
    }
    .Jump_2 0xA04AC064 : {
        KEEP(*(.data.Jump_2))
    }
}
