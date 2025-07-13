.global SOFTKEYS_D

.section .text.DisableBacklightFadeHandler
.arm
sub r12, r5, #0xFE

.section .text.DisableAutoPlayInMenu_Part1
.arm
movne r0, r0

.section .text.DisableAutoPlayInMenu_Part2
.arm
mov r0, r0

.section .text.SetAnimationViewMode
.arm
mov r0, #0x00

.section .text.FastSwitch_Part1
.arm
mov r1, #0x03

.section .text.FastSwitch_Part2
.arm
mov r1, #0x03

.section .text.FastSwitch_Part3
.arm
nop

.section .text.FastSwitch_Part4
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

.section .text.ChangeTrackName_Jump
mov r1, r5
mov r0, r6
blx ChangeTrackName
b . + 0xC

.section .text.DrawCover_Jump_1
bl DrawCover

.section .text.DrawCover_Jump_2
blne DrawCover
