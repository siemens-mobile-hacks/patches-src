.section .text.SkipDrawRectangle
.thumb
nop
nop

.section .text.DrawIconBG_Jump
.thumb
bl DrawIconBG

.section .text.SkipDrawIconBG
.thumb
cmp r0, #0xFF
