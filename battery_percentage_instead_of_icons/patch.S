.section .text.SkipCheck
.thumb
#if defined(NEWSGOLD)
    #if defined(ELKA)
        b . + 0x2C
    #else
        b . + 0x18
    #endif
#else
    nop
#endif

.section .text.DrawPercentage_Jump
.thumb
#if defined (NEWSGOLD)
    blx DrawPercentage_Trampoline
#else
    bl DrawPercentage
#endif

.section .text.SkipDrawIMG
.thumb
cmp r6, r6

#if defined (SECONDARY_DISPLAY)
    .section .text.SkipCheck_2
    .thumb
    nop

    .section .text.DrawPercentage_2_Jump
    .thumb
    bl DrawPercentage

    .section .text.SkipDrawIMG_2
    .thumb
    cmp r6, r6
#endif
