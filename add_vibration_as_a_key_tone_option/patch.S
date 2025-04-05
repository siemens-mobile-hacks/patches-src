.global DescAddr

.equ MaxItems, 4
.equ DescAddr, 0xA1381500

.section .data.MenuDesc
// Header
.int 0x5DE
.int 0x0
// Off
.int 0x0
.int 0xBB4
.int 0x7FFFFFFF
.int 0x0
.int 0x0
// Click
.int 0x01
.int 0x1D2
.int 0x7FFFFFFF
.int 0x00
.int 0x00
// Tone
.int 0x02
.int 0x1D4
.int 0x7FFFFFFF
.int 0x00
.int 0x00
// Viration
.int 0x03
.int 0x17B
.int 0x7FFFFFFF
.int 0x00
.int 0x00

.section .data.ReplaceMenuDescAddr
.int DescAddr - 0x8 // adds 0x10 by firmware

.section .text.FixMenuHeader
.thumb
add r0, #0x08

.section .text.ChangeMenuItemsCount_Part1
.thumb
mov r1, #MaxItems

.section .text.ChangeMenuItemsCount_Part2
.thumb
mov r1, #MaxItems

.section .text.ChangeKeyTonesCount_Part1
.thumb
cmp r0, #MaxItems - 1

.section .text.ChangeKeyTonesCount_Part2
.thumb
cmp r4, #MaxItems - 1

.section .text.PlayKeySound_Jump
.arm
blx PlayKeySound_Hook
