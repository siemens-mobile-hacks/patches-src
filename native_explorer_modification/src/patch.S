.global wstrlen
.global wsAppendChar

#ifdef E71_45
    .equ wstrlen, 0xA0C0CF84
    .equ wstrcmp, 0xA0FB3D74
    .equ SetCursorTab, 0xA07FA3F8
    .equ wsAppendChar, 0xA07F9F00

    .equ Send806D, 0xA0698794
    .equ Show5461, 0xA0698968
    .equ RefreshTab, 0xA069A57C
    .equ GetTabByCSM, 0xA071D770
    .equ GetExtIconSmall, 0xA05028C8
#endif

.section .data.FixFlags2
.int 0x92

.section .text.Replace_GetExtIconLarge
.arm
bl GetExtIconSmall

.section .data.FixDirIcon_1
.int 0x3C4

.section .data.FixDirIcon_2
.int 0x3C4

.section .data.FixUnkIcon
.int 0x3EA

.section .text.FixPreviewWidth_1
.arm
mov r1, #0x1A

.section .text.FixPreviewHeight_1
.arm
mov r2, #0x1A

.section .text.FixPreviewWidth_2
.arm
mov r0, #0x1A

.section .text.FixPreviewHeight_2
.arm
mov r0, #0x1A

.section .data.FixUnCheckedIcon
.int 0x53C

.section .data.FixCheckedIcon
.int 0x53A

.section .text.MergeIcons_Jump1_AddParam
.arm
mov r2, r0

.section .text.MergeIcons_Jump1
.arm
blx MergeIcons_Hook

.section .text.MergeIcons_Jump2
.arm
blx MergeIcons_Hook

.section .text.IsAllowThumbnail_Jump
.arm
blx IsAllowThumbnail


.section .text.SetItemsText_Jump
.arm
blx SetItemsText_Hook

.section .text.HideEntriesCount
.arm
b . - 0x138

.section .text.HideDateTime
.arm
b . - 0x54


.section .text.ShowHiddenFiles
.arm
mov r0, #0x01
bx lr

.section .text.ShowExtensions
.arm
cmp r0, r0


.section .text.DisableSortFavoritesDirsOnTop
.arm
cmp r0, r0

.section .text.DisableAliases_1
.arm
b . + 0x3C

.section .text.DisableAliases_2
.arm
b . + 0x3C

.section .text.GetTotalDrives_Jump
.arm
blx GetTotalDrives_Hook

.section .text.FixTabs_Part1
.arm
cmp r0, #0xFF

.section .text.FixTabs_Part2
.arm
mov r7, #0x02

.section .text.FixTabs_Part3
.arm
mov r6, #0x02

.section .text.SetSecondTabPath_Jump
.arm
blne SetSecondTabPath

.section .text.FixInitTab
.arm
blx FixInitTab_Hook
cmp r0, #0xFF
strne r0, [r4, #0x60]

.section .text.FixMMCTabIcon
.arm
cmp r4, #0x03

.section .text.ShowDrives
.arm
mov r0, #0x01
bx lr


.section .text.FixRenameFiles
.arm
bl wstrcmp

.section .text.RenameWithExt_Part1
.arm
mov r0, #0x01

.section .text.RenameWithExt_Part2
.arm
b . + 0xC4


.section .text.FixCopyFiles
.arm
mov r0, #0x01

.section .text.FixCopyMarkedDirs_Part1
.arm
mov r0, #0x00

.section .text.FixCopyMarkedDirs_Part2
.arm
mov r0, #0x00

.section .text.FixCopyMarkedDirs_Part3
.arm
mov r0, #0x00

.section .text.FixCopyDirsAttributes_Jump
.arm
blx FixCopyDirsAttributes_Hook


.section .text.FixMoveSystemDirs
.arm
b . + 0x18


.section .text.IsAllowPaste_Jump
stmdb sp!, {r4, r5, lr}
blx IsAllowPaste
ldmia sp!, {r4, r5, pc}


.section .text.FixHeader
.arm
mov r0, r4
bl wstrlen
cmp r0, #0x03
movne r0, r4
movne r1, #0x5C
blne wsAppendChar
b . + 0x138

.section .text.FixSoftkeys_Jump
.arm
blx FixSoftkeys_Hook


.section .text.FixMenu4Dirs
.arm
mov r0, #0x00

.section .text.FixMenu4MarkedDirs_Part1
.arm
mov r0, #0x00

.section .text.FixMenu4MarkedDirs_Part2
.arm
b . + 0x1A8

.section .text.FixMenuItem_Open_Part1
.arm
b . + 0x08

.section .text.FixMenuItem_Open_Part2
.arm
cmp r5, #0xFF

.section .text.FixMenuItem_Open_Part3
.arm
cmp r5, #0xFF

.section .text.FixMenuItem_Copy_Part1
.arm
mov r0, #0x00

.section .text.FixMenuItem_Copy_Part2
.arm
b . + 0x18

.section .text.FixMenuItem_Send
.arm
b . + 0x18

.section .text.HideMenuItems_Part1
.arm
b . + 0x0C

.section .text.HideMenuItems_Jump1
.arm
mov r0, r4
add r1, sp, #0x3E0
blx HideMenuItems_Hook
b . + 0x28

.section .text.HideMenuItems_Part2
.arm
b . + 0x28

.section .text.HideMenuItems_Jump2
.arm
mov r0, r6
mov r1, r4
blx HideMenuItems_Hook
nop

.section .text.HideMenuItems_Jump3
.arm
mov r0, r6
mov r1, r4
blx HideMenuItems_Hook
nop


.section .text.FixJavaDirs
.arm
nop

// .section .text.FixJavaDirs_Part2
// .arm
// cmp r0, #0xFF

.section .text.FixJavaDirIcon_Part1
.arm
ldr r0, [pc, #0x848]
add r0, r0, #0x04

.section .data.FixJavaDirIcon_Part2
.int 0x355

.section .text.FixRunJava
.thumb
b . + 0x12

.section .text.FixJavaAttributes
.arm
mov r0, #0x00


.section .text.FixDriveInfo
.arm
b . + 0x30


.section .text.FixPopupMessage
.arm
b . + 0x60

.section .data.FixPopupLgpID
.int 0x1DD4

.section .text.DisablePleaseWait
.arm
nop

.section .text.DisableCopyMoveMessage
.arm
mov r0, r4
bl GetTabByCSM
mov r1, r0
mov r0, r4
bl RefreshTab
nop

.section .data.DisableMemoryAssistantSoftkey
.short 0x0
.short 0x0
.int 0x7FFFFFFE

.section .text.FixMemoryLeak_2
.arm
mov r0, r5
mov r1, r6
bl SetCursorTab
mov r0, #0x1F
mov r1, r7
bl Send806D

.section .text.SkipFindChildren
.arm
nop

.section .text.SkipApplicationError
.arm
b . + 0x10


.section .text.ReplaceHelpMenuItem_Part1
.arm
bl Show5461

.section .data.ReplaceHelpMenuItem_Part2
.arm
.int 0xB60

.section .text.Fix5461MenuHeader
.arm
.int 0xB60

.section .text.RemoveDrivesItemFrom5461Menu_Part1
.arm
mov r1, #0x01

.section .text.RemoveDrivesItemFrom5461Menu_Part2
.arm
mov r1, #0x01

.section .text.Remove5461Combination
.arm
mov r0, #0x00

.section .text.Rename_SkipFindChildren
.arm
mov r0, #0x00
