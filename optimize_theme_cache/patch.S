.section .text.Jump_1
.arm
blx Hook_1

.section .text.Jump_2
.arm
blx Hook_2

.section .text.Fix_Get_HEADLINE_FULLSCREEN
.thumb
b . - 0x04

.section .text.Fix_Get_BODY_TAB
.thumb
b . - 0x04

.section .text.Fix_Get_BOTTOM_FULLSCREEN
.thumb
b . - 0x04

.section .text.Fix_Get_STATUSBAR_FULLSCREEN
.thumb
b . - 0x04
