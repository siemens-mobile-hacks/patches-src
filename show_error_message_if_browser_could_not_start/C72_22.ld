SECTIONS {
    .SkipGetBrowserStateCheck 0xA08F288E : {
        KEEP(*(.text.SkipGetBrowserStateCheck))
    }
    .GetBrowserState 0xA0DC0100 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetBrowserState))
    }
    .GetBrowserState_Jump 0xA0BB4EB2 : {
        KEEP(*(.text.GetBrowserState_Jump))
    }
}
