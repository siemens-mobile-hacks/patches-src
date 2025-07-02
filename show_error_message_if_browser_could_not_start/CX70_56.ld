SECTIONS {
    .SkipGetBrowserStateCheck 0xA08EF92E : {
        KEEP(*(.text.SkipGetBrowserStateCheck))
    }
    .GetBrowserState 0xA0F20100 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetBrowserState))
    }
    .GetBrowserState_Jump 0xA0B95C44 : {
        KEEP(*(.text.GetBrowserState_Jump))
    }
}
