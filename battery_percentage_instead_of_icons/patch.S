.section .text.SkipCheck
.thumb
#if defined(NEWSGOLD)
    b . + 0x2C
#else
    nop
#endif

#if defined (NEWSGOLD)
    .section .text.DrawPercentage_Trampoline
    .arm
    DrawPercentage_Trampoline:
    push {lr}
    blx DrawPercentage
    pop {pc}
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
cmp r6,r6
