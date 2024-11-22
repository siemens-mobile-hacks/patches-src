SECTIONS {
    .SkipGetBrowserStateCheck 0xA08D9C26 : {
        KEEP(*(.text.SkipGetBrowserStateCheck))
    }
    .GetBrowserState 0xA0D402A0 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetBrowserState))
    }
    .GetBrowserState_Jump 0xA0B6E2A4 : {
        KEEP(*(.text.GetBrowserState_Jump))
    }
}
