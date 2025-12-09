#if defined(SGOLD)
    .section .text.Jump
    .thumb
    bl Hook
    #if defined(SECONDARY_DISPLAY)
        .section .text.Jump_2
        .thumb
        bl Hook_2
    #endif
#else
    .section .text.Jump_1
    .thumb
    bl Hook_1

    .section .text.Jump_2
    .thumb
    bl Hook_2
#endif
