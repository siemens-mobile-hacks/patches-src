SECTIONS {
    .rodata 0xA11D4500 : {
        KEEP(*(.rodata*))
    }
    .Getters 0xA11D4750 : {
        KEEP(*(.text.GetBoolean))
        KEEP(*(.text.GetOnOff))
    }
    .AddElement 0xA11D47A0 : {
        KEEP(*(.text.AddElement))
        KEEP(*(.text.AddIntegerElement))
    }
    .Hooks 0xA11D4820 : {
        KEEP(*(.text.OnKey_Hook))
        KEEP(*(.text.GHook))
    }
    .OnKey_Jump 0xA04AA95C : {
        KEEP(*(.data.OnKey_Jump))
    }
    .GHook_Jump 0xA04AA960 : {
        KEEP(*(.data.GHook_Jump))
    }
}
