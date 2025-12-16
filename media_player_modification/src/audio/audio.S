.equ MP_StoreLastPlayedMelody, 0xA079647C

.section .text.StoreLastPlayMelodyOnChangeTrack
.arm
ldrsb r0, [r4, #0x7c]
cmp r0, #0x01
moveq r0, r4
bleq MP_StoreLastPlayedMelody
b . + 0xC

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

.section .text.ChangeVolumeWhenKbdIsLocked
.arm
mov r0, #0x00

.section .text.ChangeTrackName_Jump
mov r1, r5
mov r0, r6
blx ChangeTrackName
b . + 0xC

.section .text.DrawCover_Jump_1
bl DrawCover

.section .text.DrawCover_Jump_2
blne DrawCover

.section .text.DisableVisualizerBG
.arm
b . + 0xCC

.section .text.DrawVisualizer_Jump
.arm
blx DrawVisualizer_Hook
