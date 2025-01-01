#ifdef E71_45
    .equ wstrcmp, 0xA0FB3D74
    .equ GetMenuGUI, 0xA0950125
    .equ SetCursorTab, 0xA07FA3F8
    .equ AllocMenuItem, 0xA0954585
    .equ GetExtIconSmall, 0xA05028C8
    .equ Send806D, 0xA0698794
    .equ Show5461, 0xA0698968
#endif

.section .text.Replace_GetMultiLinesMenuGUI
.arm
blx GetMenuGUI

.section .text.Replace_AllocMLMenuItem
.arm
blx AllocMenuItem

.section .text.FixMemoryLeak_1
.arm
cmp r6,r6

.section .text.Replace_GetExtIconLarge_1
.arm
bl GetExtIconSmall

.section .text.Replace_GetExtIconLarge_2
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

.section .text.MergeIconsHook_AddParam
.arm
mov r2, r0

.section .text.MergeIconsHook_Jump
.arm
blx MergeIconsHook

.section .text.SetPreviewHook_Jump
.arm
bl SetPreviewHook

.section .text.ShowHiddenFiles_Part1
.arm
cmp r0, #0xFF

.section .text.ShowHiddenFiles_Part2
.arm
cmp r0, #0xFF

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


.section .text.FixTabs_Part1
.arm
cmp r1, #0x04

.section .text.FixTabs_Part2
.arm
cmp r0, #0xFF

.section .text.FixTabs_Part3
.arm
mov r7, #0x02

.section .text.FixTabs_Part4
.arm
mov r6, #0x02

.section .text.Set2ndTabPath_Jump
.arm
blne Set2ndTabPath

.section .text.FixInitTab
.arm
blx FixInitTabHook
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

.section .text.FixCopyMarkedDirs
.arm
mov r0, #0x00

.section .text.FixDeleteROFiles_Part1
.arm
movne r0, #0x00

.section .text.FixDeleteROFiles_Part2
.arm
b . + 0x24


.section .text.FixHeader
.arm
b . + 0x150


.section .text.FixMenu4Dirs
.arm
mov r0, #0x00

.section .text.FixMenu4MarkedDirs_Part1
.arm
mov r0, #0x00

.section .text.FixMenu4MarkedDirs_Part2
.arm
b . + 0x1A8

.section .text.FixMenuItem_Copy
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
