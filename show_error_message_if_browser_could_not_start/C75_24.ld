SECTIONS {
    .SkipGetBrowserStateCheck 0xA03288EA : {
        KEEP(*(.text.SkipGetBrowserStateCheck))
    }
    .GetBrowserState 0xA01C0100 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetBrowserState))
    }
    .GetBrowserState_Jump 0xA0506586 : {
        KEEP(*(.text.GetBrowserState_Jump))
    }
}
