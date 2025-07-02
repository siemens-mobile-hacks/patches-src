.section .text.ShowScreenSaver_Jump
.thumb
bl ShowScreenSaver_Hook
#if defined(SGOLD)
    mov r0, #0x00
    pop {r4, pc}
#endif
