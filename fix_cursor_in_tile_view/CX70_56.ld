SECTIONS {
    .DrawRoundedFrame_Jump_Part1 0xA0D25AC8 : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part1))
    }
    .DrawRoundedFrame_Jump_Part2 0xA0D25B32 : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part2))
    }
    .DrawRoundedFrame_Jump_Part3 0xA0D25B6C : {
        KEEP(*(.text.DrawRoundedFrame_Jump_Part3))
    }

    .DrawRoundedFrame_Hook 0xA0F22222 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.DrawRoundedFrame_Hook))
    }
}
