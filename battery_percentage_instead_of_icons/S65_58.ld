SECTIONS {
    .SkipCheck 0xA169902C : {
        KEEP(*(.text.SkipCheck))
    }
    .DrawPercentage 0xA16C0500 : {
        KEEP(*(.text.DrawPercentage))
        KEEP(*(.rodata*))
    }
    .DrawPercentage_Jump 0xA169903E : {
        KEEP(*(.text.DrawPercentage_Jump))
    }
    .SkipDrawIMG 0xA1699042 : {
        KEEP(*(.text.SkipDrawIMG))
    }
}
