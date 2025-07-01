.section .text.FixNavigationInTileView_Part1
.thumb
blt . + 0x80

.section .text.FixNavigationInTileView_Part2
.thumb
mov r8, r8

.section .text.FixNavigationInTileView_Part3
.thumb
mov r8, r8

.section .text.FixNavigationInTileView_Part4
.thumb
beq . - 0x94

.section .text.FixNavigationInCardExplorer_Jump
.arm
blx FixNavigationInCardExplorer_Hook

.section .text.FixLongPress_Jump
.thumb
bl FixLongPress_Hook

.section .text.FixCursorPosition
.thumb
mov r1, #0xFF
