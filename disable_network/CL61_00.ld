SECTIONS {
    .DisableNetwork 0xA0658854 : {
        KEEP(*(.text.DisableNetwork))
    }
    .EnableNetwork 0xA065889C : {
        KEEP(*(.text.EnableNetwork))
    }
    .Hook 0xA023CEC0 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.Hook))
    }
    .Jump 0xA0E4828C : {
        KEEP(*(.data.Jump))
    }
}
