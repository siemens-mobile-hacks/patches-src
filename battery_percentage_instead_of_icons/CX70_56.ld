SECTIONS {
    .SkipCheck 0xA1715A9E : {
        KEEP(*(.text.SkipCheck))
    }
    .DrawPercentage 0xA1750500 : {
        KEEP(*(.text.DrawPercentage))
        KEEP(*(.rodata*))
    }
    .DrawPercentage_Jump 0xA1715AB0 : {
        KEEP(*(.text.DrawPercentage_Jump))
    }
    .SkipDrawIMG 0xA1715AB4 : {
        KEEP(*(.text.SkipDrawIMG))
    }
}
