SECTIONS {
    .ShowErrorMessage1 0xA17C0060 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.ShowErrorMessage1))
    }
    .ShowErrorMessage1_Jump 0xA0CB8590 : {
        KEEP(*(.text.ShowErrorMessage1_Jump))
    }
    .ShowErrorMessage2 0xA17C00B0 : {
        KEEP(*(.text.ShowErrorMessage2))
    }
    .ShowErrorMessage2_Jump 0xA0C9AE00 : {
        KEEP(*(.text.ShowErrorMessage2_Jump));
    }
}
