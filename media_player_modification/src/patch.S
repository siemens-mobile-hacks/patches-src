.section .text.DisableBacklightFadeHandler
.arm
sub r12, r5, #0xFE

.section .text.DisableHideWhenKbdIsLocked
.arm
b . + 0x20

.section .text.FixSelectPlaylist
.arm
nop

.section .text.DisableMessage_AddTracksToPlaylist
.arm
nop

.section .text.InitData_Jump
.arm
mov r0, r4
blx InitData

.section .text.DestroyData_Jump
.arm
mov r0, r4
blx DestroyData

.section .data.OnKey_Jump
.int OnKey

.section .data.GHook_Jump
.int GHook

.section .text.BaseOnRedraw_Jump
blx BaseOnRedraw_Hook

.section .data.Options_ReplaceAttributes_Part1
.int 0x81B

.section .text.Options_ReplaceAttributes_Part2
.arm
blx Options_GoTo

.section .data.Options_RemoveHelpItem
.int 0x55C
