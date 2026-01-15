.section .text.ShowFullPath_Part1
.arm
b . + 0x198

.section .text.ShowFullPath_Part2
.arm
mov r0, #0x00

.section .text.ShowFullPath_Part3
.arm
mov r2, r11

.section .text.ShowFullPath_Part4
.arm
ldr r1, [pc, #0x474]

.section .text.ShowFullPath_Part5
.arm
mov r0, #0x00

.section .text.ShowFullPath_Part6
.arm
b . + 0x3C


.section .text.Init_Jump
.arm
blx Init_Hook

.section .text.AddUID_Jump
.arm
blx AddUID_Hook

.section .text.AllocWS_Jump
.arm
blx AllocWS_Hook

.section .text.OnKey_Jump_Part1
.arm
bne . + 0x8

.section .text.OnKey_Jump_Part2
.arm
blx OnKey_Hook
nop


.section .data.FixSoftkeysMapping_Part1
.int 0x05

.section .data.FixSoftkeysMapping_Part2
.int 0x00

.section .data.FixLgpID
.int 0x7FFFC10D
