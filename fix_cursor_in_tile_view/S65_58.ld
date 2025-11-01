SECTIONS {
    .FixArg 0xA119E4D8 : {
        KEEP(*(.text.FixArg))
    }
    .DrawRoundedFrame_Jump_Part1 0xA119E4E6 : {
            KEEP(*(.text.DrawRoundedFrame_Jump_Part1))
        }
    .DrawRoundedFrame_Jump_Part2 0xA119E542 : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part2))
    }
    .DrawRoundedFrame_Jump_Part3 0xA119E57C : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part3))
    }

    .DrawRoundedFrame_Hook 0xA0F221A0 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.DrawRoundedFrame_Hook))
    }
}
