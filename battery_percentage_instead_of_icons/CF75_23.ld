SECTIONS {
    .SkipCheck 0xA02A9B32 : {
        KEEP(*(.text.SkipCheck))
    }
    .DrawPercentage 0xA01C0500 : {
        KEEP(*(.text.DrawPercentage))
        KEEP(*(.rodata*))
    }
    .DrawPercentage_Jump 0xA02A9B44 : {
        KEEP(*(.text.DrawPercentage_Jump))
    }
    .SkipDrawIMG 0xA02A9B48 : {
        KEEP(*(.text.SkipDrawIMG))
    }

    .SkipCheck_2 0xA02D637C : {
        KEEP(*(.text.SkipCheck_2))
    }
    .DrawPercentage_2_Jump 0xA02D638C : {
        KEEP(*(.text.DrawPercentage_2_Jump))
    }
    .SkipDrawIMG_2 0xA02D6390 : {
        KEEP(*(.text.SkipDrawIMG_2))
    }
}
