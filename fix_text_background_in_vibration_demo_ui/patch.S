.section .text.Jump
.thumb
mov r0, r4
bl Hook
cmp r0, #0x00
bne . + 0x6

