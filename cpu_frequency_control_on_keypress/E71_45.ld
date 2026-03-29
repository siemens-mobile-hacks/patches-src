SECTIONS {
    .CPU_LOW_FREQ_DELAY_TICKS 0xA1383800 : {
        KEEP(*(.data.CPU_LOW_FREQ_DELAY_TICKS))
    }
    .Common 0xA1383806 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.SetCPUClockLow))
    }
    .Hooks 0xA13838A0 : {
        KEEP(*(.text.KeyPressOn_Hook))
        KEEP(*(.text.KeyPressOff_Hook))
    }
    .KeyPressOn_Trampoline 0xA08CF628 : {
        KEEP(*(.text.KeyPressOn_Trampoline))
    }
    .KeyPressOn_Jump 0xA08D3764 : {
        KEEP(*(.text.KeyPressOn_Jump))
    }
}
