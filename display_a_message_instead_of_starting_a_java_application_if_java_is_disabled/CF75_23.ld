SECTIONS {
    .ShowErrorMessage1 0xA11E0870 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.ShowErrorMessage1))
    }
    .ShowErrorMessage1_Jump 0xA07A705C : {
        KEEP(*(.text.ShowErrorMessage1_Jump))
    }
    .ShowErrorMessage2 0xA11E08C0 : {
        KEEP(*(.text.ShowErrorMessage2))
    }
    .ShowErrorMessage2_Jump 0xA0778F90 : {
        KEEP(*(.text.ShowErrorMessage2_Jump));
    }
}
