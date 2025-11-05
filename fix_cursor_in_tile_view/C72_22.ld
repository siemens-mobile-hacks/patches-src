SECTIONS {
    .FixArg 0xA11A78DC : {
        KEEP(*(.text.FixArg))
    }
    .DrawRoundedFrame_Jump_Part1 0xA11A78EA : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part1))
    }
    .DrawRoundedFrame_Jump_Part2 0xA11A7946 : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part2))
    }
    .DrawRoundedFrame_Jump_Part3 0xA11A7980 : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part3))
    }

    .DrawRoundedFrame_Hook 0xA0F821A0 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.DrawRoundedFrame_Hook))
    }
}
