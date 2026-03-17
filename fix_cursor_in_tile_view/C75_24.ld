SECTIONS {
    .FixArg 0xA08E560C : {
        KEEP(*(.text.FixArg))
    }
    .DrawRoundedFrame_Jump_Part1 0xA08E561A : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part1))
    }
    .DrawRoundedFrame_Jump_Part2 0xA08E5676 : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part2))
    }
    .DrawRoundedFrame_Jump_Part3 0xA08E56B0 : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part3))
    }

    .DrawRoundedFrame_Hook 0xA0751E2A : {
        KEEP(*(.rodata*))
        KEEP(*(.text.DrawRoundedFrame_Hook))
    }
}
