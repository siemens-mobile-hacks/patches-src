#ifdef S75_52
    .equ DirectRedrawGUI, 0xA0661C6C

    .equ SendCMD_Save, 0xA062D08F
#endif

.section .data.List_OnClose_Jump
.int List_OnClose_Hook

.section .data.List_GHook_Jump
.int List_GHook_Hook


.section .data.Recording_FixPBarPosition
.short 0x27
.short 0x87
.short 0x5D
.short 0x90

.section .text.Recording_FixAnimationPosition
.thumb
mov r2, #0x34

.section .data.Recording_FixFinishedTextPosition
.short 0x0
.short 0x42
.short 0x83
.short 0x51

.section .text.Recording_ChangeAnimationSpeed
.thumb
mov r1, #0x50

.section .text.Recording_FixRedraw_Trampoline
.arm
Recording_FixRedraw_Trampoline:
push {lr}
blx Recording_FixRedraw_Hook
pop {pc}

.section .text.Recording_FixRedraw_Jump
.thumb
blx Recording_FixRedraw_Trampoline

.section .text.Recording_FixRedraw_Part2
.thumb
nop
nop

.section .text.Recording_FixRedraw_Part3
.thumb
blx DirectRedrawGUI

.section .data.Recording_FixRedraw_Part4
.int 0x30

.section .data.Recording_FixRedraw_Part5
.int 0x10

.section .text.Recording_FixClose
.thumb
mov r0, #0x01

.section .text.Recording_SaveOnClose_Part1
.thumb
bl SendCMD_Save

.section .text.Recording_SaveOnClose_Part2
.thumb
bl SendCMD_Save

.section .text.Recording_ChangeText_Part1
.thumb
mov r0, #0x80

.section .text.Recording_ChangeText_Jump
.thumb
mov r0, r4
blx Recording_ChangeText_Hook
nop

.section .text.Options_ReplaceRename_Part1_Trampoline
.arm
Options_ReplaceRename_Part1_Trampoline:
push {lr}
blx Options_GoTo
pop {pc}

.section .text.Options_ReplaceRename_Part1_Jump
.thumb
blx Options_ReplaceRename_Part1_Trampoline

.section .data.Options_ReplaceRename_Part2
.int 0x81B
.int 0x81B
