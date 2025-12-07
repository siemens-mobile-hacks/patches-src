SECTIONS {
    .SkipCheck 0xA029D726 : {
        KEEP(*(.text.SkipCheck))
    }
    .DrawPercentage 0xA1BC00A0 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.DrawPercentage))
    }
    .DrawPercentage_Trampoline 0xA0293890 : {
        KEEP(*(.text.DrawPercentage_Trampoline))
    }
    .DrawPercentage_Jump 0xA029D74E : {
        KEEP(*(.text.DrawPercentage_Jump))
    }
    .SkipDrawIMG 0xA029D752 : {
        KEEP(*(.text.SkipDrawIMG))
    }
}
