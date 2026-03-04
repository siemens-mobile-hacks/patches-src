.section .text.Jump
.thumb
add r1, sp, #0x14
bl Hook
b . + 0x6
