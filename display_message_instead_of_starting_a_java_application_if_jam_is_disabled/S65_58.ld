SECTIONS {
    .ShowErrorMessage1 0xA17E0060 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.ShowErrorMessage1))
    }
    .ShowErrorMessage1_Jump 0xA0C465E8 : {
        KEEP(*(.text.ShowErrorMessage1_Jump))
    }
    .ShowErrorMessage2 0xA17E00B0 : {
        KEEP(*(.text.ShowErrorMessage2))
    }
    .ShowErrorMessage2_Jump 0xA0C32394 : {
        KEEP(*(.text.ShowErrorMessage2_Jump));
    }
}
