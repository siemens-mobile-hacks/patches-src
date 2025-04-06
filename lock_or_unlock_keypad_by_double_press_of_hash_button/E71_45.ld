SECTIONS {
    .KbdLock_Hook 0xA0676E7C : {
        KEEP(*(.rodata*))
        KEEP(*(.text.KbdLock_Hook))
    }
    .KbdLock_Jump 0xA0663852 : {
        KEEP(*(.text.KbdLock_Jump))
    }
    .KbdUnlock_Part1 0xA0670BB4 : {
        KEEP(*(.text.KbdUnlock_Part1))
    }
    .KbdUnlock_Part2 0xA0702C8A : {
        KEEP(*(.text.KbdUnlock_Part2))
    }
    .KbdUnlock_Part3 0xA0669846 : {
        KEEP(*(.text.KbdUnlock_Part3))
    }
    .KeypadLock_DisableText 0xA0669AA0 : {
        KEEP(*(.text.KeypadLock_DisableText))
    }
    .KeypadLock_FixIconPosition 0xA084AD20 : {
        KEEP(*(.data.KeypadLock_FixIconPosition))
    }
    .KeypadLock_FixTextPosition 0xA084AC68 : {
        KEEP(*(.data.KeypadLock_FixTextPosition))
    }
    .KeypadLock_DisableInput_Part1 0xA06696B0 : {
        KEEP(*(.text.KeypadLock_DisableInput_Part1))
    }
    .KeypadLock_DisableInput_Part2 0xA06699D4 : {
        KEEP(*(.text.KeypadLock_DisableInput_Part2))
    }
}
