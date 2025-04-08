.global DESC_ADDR
.global VIBRA_CLICK_LGP_ID

.equ KEY_TONES_COUNT, 5
.equ MENU_ITEMS, KEY_TONES_COUNT - 1 // remove Tone
.equ DESC_ADDR, 0xA1381500

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
//.int 0x02
//.int 0x1D4
//.int 0x7FFFFFFF
//.int 0x00
//.int 0x00
// Viration
.int 0x03
.int 0x17B
.int 0x7FFFFFFF
.int 0x00
.int 0x00
// Vibration + Click
.int 0x04
.int 0x7FFFD000
.int 0x7FFFFFFF
.int 0x00
.int 0x00

.section .data.ReplaceMenuDescAddr
.int DESC_ADDR - 0x8 // adds 0x10 by firmware

.section .text.FixMenuHeader
.thumb
add r0, #0x08

.section .text.ChangeMenuItemsCount_Part1
.thumb
mov r1, #MENU_ITEMS

.section .text.ChangeMenuItemsCount_Part2
.thumb
mov r1, #MENU_ITEMS

.section .text.AddLgpMessage_Trampoline
.arm
AddLgpMessage_Trampoline:
push {lr}
blx AddLgpMessage_Hook
pop {pc}

.section .text.AddLgpMessage_Jump
.thumb
blx AddLgpMessage_Trampoline

.section .text.ChangeKeyTonesCount_Part1
.thumb
cmp r0, #KEY_TONES_COUNT - 1

.section .text.ChangeKeyTonesCount_Part2
.thumb
cmp r4, #KEY_TONES_COUNT - 1

.section .text.PlayKeySound_Jump
.arm
blx PlayKeySound_Hook
