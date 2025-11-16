SECTIONS {
    .SkipCheck 0xA08C508E : {
        KEEP(*(.text.SkipCheck))
    }
    .DrawPercentage 0xA0800500 : {
        KEEP(*(.text.DrawPercentage))
        KEEP(*(.rodata*))
    }
    .DrawPercentage_Jump 0xA08C50A0 : {
        KEEP(*(.text.DrawPercentage_Jump))
    }
    .SkipDrawIMG 0xA08C50A4 : {
        KEEP(*(.text.SkipDrawIMG))
    }
}
