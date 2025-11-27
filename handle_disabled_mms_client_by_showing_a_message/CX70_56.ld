SECTIONS {
    .rodata 0xA17D4D00 : {
        KEEP(*(.rodata*))
    }
    .CreateOrClose 0xA17D4D20 : {
        KEEP(*(.text.CreateOrClose))
    }
    .Hooks 0xA17D4D60 : {
        KEEP(*(.text.Hook_1))
        KEEP(*(.text.Hook_2))
    }
    .Jump_1 0xA0A5E08C : {
        KEEP(*(.data.Jump_1))
    }
    .Jump_2 0xA0A5627C : {
        KEEP(*(.data.Jump_2))
    }
}
