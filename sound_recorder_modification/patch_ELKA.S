#ifdef E71_45
    .equ DirectRedrawGUI, 0xA0FB3B78

    .equ SendCMD_Save, 0xA07D14FC
#endif

.section .data.List_OnClose_Jump
.int List_OnClose_Hook

.section .data.List_GHook_Jump
.int List_GHook_Hook


.section .data.Recording_FixPBarPosition
.short 0x5A
.short 0xFC
.short 0x96
.short 0x10B

.section .data.Recording_FixElapsedTimePosition
.short 0x52

.section .data.Recording_FixTotalTimePosition
.short 0x9E

.section .text.Recording_ChangeAnimationSpeed
.arm
mov r1, #0x80

.section .text.Recording_FixRedraw_Jump
.arm
blx Recording_FixRedraw_Hook

.section .text.Recording_FixRedraw_Part2
.arm
nop

.section .data.Recording_FixRedraw_Part3
.int DirectRedrawGUI

.section .data.Recording_FixRedraw_Part4
.int 0x145

.section .data.Recording_FixRedraw_Part5
.int 0xFA

.section .text.Recording_FixClose
.arm
moveq r0, #0x01

.section .text.Recording_SaveOnClose_Part1
.arm
bl SendCMD_Save

.section .text.Recording_SaveOnClose_Part2
.arm
bl SendCMD_Save

.section .text.Recording_ChangeText_Part1
.arm
mov r0, #0x80

.section .text.Recording_ChangeText_Jump
.arm
mov r0, r4
blx Recording_ChangeText_Hook

.section .text.Options_ReplaceRename_Part1
.arm
blx Options_GoTo

.section .data.Options_ReplaceRename_Part2
.int 0x81B
.int 0x81B
