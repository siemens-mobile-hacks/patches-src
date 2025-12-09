SECTIONS {
    .Hook 0xA1482A00 : {
        KEEP(*(.text.Hook))
    }
    .Trampoline 0xA05329B4 : {
        KEEP(*(.text.Trampoline))
    }
    .Jump 0xA05328AE : {
        KEEP(*(.text.Jump))
    }
}
