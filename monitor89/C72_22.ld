SECTIONS {
    .rodata 0xA17D4500 : {
        KEEP(*(.rodata*))
    }
    .Getters 0xA17D4750 : {
        KEEP(*(.text.GetBoolean))
        KEEP(*(.text.GetOnOff))
    }
    .AddElement 0xA17D47A0 : {
        KEEP(*(.text.AddElement))
        KEEP(*(.text.AddIntegerElement))
    }
    .Hooks 0xA17D4820 : {
        KEEP(*(.text.OnKey_Hook))
        KEEP(*(.text.GHook))
    }
    .OnKey_Jump 0xA0949FD8 : {
        KEEP(*(.data.OnKey_Jump))
    }
    .GHook_Jump 0xA0949FDC : {
        KEEP(*(.data.GHook_Jump))
    }
}
