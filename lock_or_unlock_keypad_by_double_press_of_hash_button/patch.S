.global KeypadLock_OnKeyAddr

.equ KeypadLock_OnKeyAddr, 0xA1381600

.section .text.KbdLock_Jump
.thumb
bl KbdLock_Hook

.section .text.KbdUnlock_Part1
.thumb
#if defined(NEWSGOLD)
    #if defined(ELKA)
        bne . + 0xA4
    #else
        bne . + 0x9C
    #endif
#endif
b . + 0x12

.section .text.KbdUnlock_Part2
.thumb
b . + 0x8
nop

.section .text.KbdUnlock_Part3
.thumb
beq . + 0x12
b . + 0x34

.section .text.KbdUnlock_Part4
.thumb
sub r0, #0x94

.section .text.KbdUnlock_Part5
.thumb
cmp r1, #0x23
beq . + 0x1A

.section .text.KeypadLock_DisableText
.thumb
b . + 0x44

#if defined(NEWSGOLD)
    #if defined(ELKA)
        .equ Y_OFFSET, 0x20

        .section .data.KeypadLock_FixIconPosition
        .short 0x02
        .short 0x2D + Y_OFFSET

        .section .data.KeypadLock_FixTextPosition
        .short 0x30
        .short 0x50 + Y_OFFSET + 0x20
        .short 0xEF
        .short 0x8F + Y_OFFSET + 0x20
    #else
        .equ Y_OFFSET, 10
        .section .data.KeypadLock_FixIconPosition
        .short 0x0C
        .short 0x19 + Y_OFFSET

        .section .data.KeypadLock_FixTextPosition
        .short 0x1A
        .short 0x2D + Y_OFFSET + 0xC
        .short 0x83
        .short 0x4B + Y_OFFSET + 0xC
    #endif
#else
    nop
#endif

.section .text.KeypadLock_DisableInput_Part1
.thumb
mov r0, #0x01
bx lr

.section .text.KeypadLock_DisableInput_Part2
.thumb
mov r1, #0x00
