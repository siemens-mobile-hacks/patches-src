SECTIONS {
    .SkipDrawRectangle 0xA0A22468 : {
        KEEP(*(.text.SkipDrawRectangle))
    }
    .DrawIconBG_Jump 0xa0a223c8 : {
        KEEP(*(.text.DrawIconBG_Jump))
    }
    .DrawIconBG 0xA0C63324 : {
        KEEP(*(.text.DrawIconBG))
    }
    .SkipDrawIconBG 0xA0A2445A : {
        KEEP(*(.text.SkipDrawIconBG))
    }
}
