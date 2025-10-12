SECTIONS {
    .ShowErrorMessage1 0xA17E0870 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.ShowErrorMessage1))
    }
    .ShowErrorMessage1_Jump 0xA0CA6A10 : {
        KEEP(*(.text.ShowErrorMessage1_Jump))
    }
    .ShowErrorMessage2 0xA17E08C0 : {
        KEEP(*(.text.ShowErrorMessage2))
    }
    .ShowErrorMessage2_Jump 0xA0C8E6E4 : {
        KEEP(*(.text.ShowErrorMessage2_Jump));
    }
}
