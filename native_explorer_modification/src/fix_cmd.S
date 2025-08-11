.section .text.FixCopyFile_Jump
.arm
blx FixCopyFile_Hook

.section .text.FixMoveFile_Jump
.arm
blx FixMoveFile_Hook

.section .text.FixSendFile_Jump
.arm
blx FixSendFile_Hook

.section .text.FixSortFiles_Jump
.arm
blx FixSortFiles_Hook

.section .text.FixSetAsFile_Jump
.arm
blx FixSetAsFile_Hook

.section .text.FixRenameFile_Jump
.arm
blx FixRenameFile_Hook

.section .text.FixDeleteFile_Jump
.arm
blx FixDeleteFile_Hook

.section .text.FixPaste_Part1
.arm
b . + 0x0C

.section .text.FixPaste_Part2
.arm
nop

.section .text.FixPaste_Part3
.arm
nop

.section .text.FixPaste_Jump
.arm
blx FixPaste_Hook

.section .text.FixShowFileAttributes_Jump
.arm
blx FixShowFileAttributes_Hook

// .section .text.FixShowSearch
// .arm
// b . + 0x08
