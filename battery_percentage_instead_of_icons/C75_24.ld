SECTIONS {
    .SkipCheck 0xA02A8CBE : {
        KEEP(*(.text.SkipCheck))
    }
    .DrawPercentage 0xA01C0500 : {
        KEEP(*(.text.DrawPercentage))
        KEEP(*(.rodata*))
    }
    .DrawPercentage_Jump 0xA02A8CD0 : {
        KEEP(*(.text.DrawPercentage_Jump))
    }
    .SkipDrawIMG 0xA02A8CD4 : {
        KEEP(*(.text.SkipDrawIMG))
    }
}
