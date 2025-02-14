SECTIONS {
    .Hook_1 0xA1380D00 : {
        KEEP(*(.text.Hook_1))
    }
    .Jump_1 0xA073D2AC : {
        KEEP(*(.text.Jump_1))
    }
    .Hook_2 0xA1380D60 : {
        KEEP(*(.text.Hook_2))
    }
    .Jump_2 0xA073D2C8 : {
        KEEP(*(.text.Jump_2))
    }

    .Fix_Get_HEADLINE_FULLSCREEN 0xA0A26AC8 : {
        KEEP(*(.text.Fix_Get_HEADLINE_FULLSCREEN))
    }
    .Fix_Get_BODY_TAB 0xA0A26AD0 : {
        KEEP(*(.text.Fix_Get_BODY_TAB))
    }
    .Fix_Get_BOTTOM_FULLSCREEN 0xA0A26AD8 : {
        KEEP(*(.text.Fix_Get_BOTTOM_FULLSCREEN))
    }
    .Fix_Get_STATUSBAR_FULLSCREEN 0xA0A26AC0 : {
        KEEP(*(.text.Fix_Get_STATUSBAR_FULLSCREEN))
    }
}
