.section .text.DrawMenuItemScrollText_Jump
.thumb
bl DrawMenuItemScrollText_Hook

.section .text.FixR0
.thumb
movs r0, r4

.section .text.GrabBGFromLCD_Jump
.thumb
bl GrabBGFromLCD_Hook
