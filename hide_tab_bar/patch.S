.section .text.HideTabs
.thumb
nop
nop

.section .text.FixBodyBG
.thumb
mov r0, #0x02

.section .text.FixBodyPosition
.thumb
nop
nop

.section .text.CallOnCreateHandlers_Jump
.thumb
bl CallOnCreateHandlers_Hook
