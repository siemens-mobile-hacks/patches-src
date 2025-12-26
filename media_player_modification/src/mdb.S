.section .text.MDB_IsAllowFile_Jump
.arm
blx MDB_IsAllowFile

.section .text.MDB_FixUI_Jump
.arm
blx MDB_FixUI_Hook

.section .text.MDB_UseSmallIcons
.arm
mov r3, #0x0

.section .text.MDB_FixPreviewSize
.arm
mov r1, #0x1A
mov r2, #0x1A

.section .text.MDB_FixSetUserPointer
.arm
mov r1, r4

.section .text.MDB_FixGetUserPointer_Jump
.arm
blx MDB_FixGetUserPointer_Hook

.section .data.MDB_GHook_Jump
.int MDB_GHook_Hook

.section .data.MDB_Options_ReplaceAttributes_Part1
.int 0x81B

.section .text.MDB_Options_ReplaceAttributes_Part2
.arm
blx Options_GoTo

.section .data.MDB_Options_RemoveHelpItem
.int 0x55C
