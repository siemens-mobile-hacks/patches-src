#if defined(ELKA)
    .section .text.Jump
    .arm
    bl Hook
#else
    .section .text.Jump
    .thumb
    blx Trampoline

    .section .text.Trampoline
    .arm
    Trampoline:
        push {lr}
        blx Hook
        pop {pc}
#endif
