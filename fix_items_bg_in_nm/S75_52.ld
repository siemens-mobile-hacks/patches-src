SECTIONS {
    .SkipDrawRectangle 0xA0A18374 : {
        KEEP(*(.text.SkipDrawRectangle))
    }
    .DrawIconBG_Jump 0xA0A182D4 : {
        KEEP(*(.text.DrawIconBG_Jump))
    }
    .DrawIconBG 0xA0CAB3A0 : {
        KEEP(*(.text.DrawIconBG))
    }
    .SkipDrawIconBG 0xA0A1A216 : {
        KEEP(*(.text.SkipDrawIconBG))
    }
}
