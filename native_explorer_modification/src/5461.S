#ifdef E71_45
    .equ _5461_CreateUI, 0xA0698968
#endif

.section .text.ReplaceHelpMenuItem
.arm
bl _5461_CreateUI

.section .data.RenameHelpMenuItem
.arm
.int 0xB60

.section .text.5461_FixHeader
.arm
.int 0xB60

.section .text.5461_ChangeItemsCount
.arm
mov r1, #0x01

.section .text.5461_RemoveCombination
.arm
mov r0, #0x00

.section .text.5461_SetUserPointer
.arm
mov r2, r0

.section .data.5461_OnKey_Jump
.int _5461_OnKey

.section .data.5461_GHook_Jump
.int _5461_GHook
