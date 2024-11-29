.section .text.DrawMenuItemScrollText_Jump
.thumb
bl DrawMenuItemScrollText

.section .text.FixR0
.thumb
movs r0, r4

.section .text.GrabBGFromLCD_Jump
.thumb
bl GrabBGFromLCD
