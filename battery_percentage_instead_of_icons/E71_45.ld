SECTIONS {
    .SkipCheck 0xA05C1584 : {
        KEEP(*(.text.SkipCheck))
    }
    .DrawPercentage 0xA1FC00A0 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.DrawPercentage))
    }
    .DrawPercentage_Trampoline 0xA05C7118 : {
        KEEP(*(.text.DrawPercentage_Trampoline))
    }
    .DrawPercentage_Jump 0xA05C15C0 : {
        KEEP(*(.text.DrawPercentage_Jump))
    }
    .SkipDrawIMG 0xA05C15C4 : {
        KEEP(*(.text.SkipDrawIMG))
    }
}
