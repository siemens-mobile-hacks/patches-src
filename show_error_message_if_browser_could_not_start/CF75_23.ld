SECTIONS {
    .SkipGetBrowserStateCheck 0xA032E7CE : {
        KEEP(*(.text.SkipGetBrowserStateCheck))
    }
    .GetBrowserState 0xA01C0100 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetBrowserState))
    }
    .GetBrowserState_Jump 0xA050A2DE : {
        KEEP(*(.text.GetBrowserState_Jump))
    }
}
