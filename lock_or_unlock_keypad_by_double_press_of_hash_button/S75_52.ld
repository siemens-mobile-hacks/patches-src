SECTIONS {
    .KbdLock_Hook 0xA02F4130 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.KbdLock_Hook))
    }
    .KbdLock_Jump 0xA02F65C2 : {
        KEEP(*(.text.KbdLock_Jump))
    }
    .KbdUnlock_Part1 0xA0303C24 : {
        KEEP(*(.text.KbdUnlock_Part1))
    }
    .KbdUnlock_Part2 0xA034649E : {
        KEEP(*(.text.KbdUnlock_Part2))
    }
    .KbdUnlock_Part3 0xA03464B4 : {
        KEEP(*(.text.KbdUnlock_Part3))
    }
    .KbdUnlock_Part4 0xA0342CCA : {
        KEEP(*(.text.KbdUnlock_Part4))
    }
    .KbdUnlock_Part5 0xA0302266 : {
        KEEP(*(.text.KbdUnlock_Part5))
    }
    .KeypadLock_DisableText 0xA0342F12 : {
        KEEP(*(.text.KeypadLock_DisableText))
    }
    .KeypadLock_FixIconPosition 0xA0439B94 : {
        KEEP(*(.data.KeypadLock_FixIconPosition))
    }
    .KeypadLock_FixTextPosition 0xA0C0049C : {
        KEEP(*(.data.KeypadLock_FixTextPosition))
    }
    .KeypadLock_DisableInput_Part1 0xA0342B28 : {
        KEEP(*(.text.KeypadLock_DisableInput_Part1))
    }
    .KeypadLock_DisableInput_Part2 0xA0342E58 : {
        KEEP(*(.text.KeypadLock_DisableInput_Part2))
    }
}
