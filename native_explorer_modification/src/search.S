.section .data.Search_OnMessage_Jump
.int Search_OnMessage_Hook

.section .data.Search_OnKey_Jump
.int Search_OnKey_Hook

.section .data.Search_GHook_Jump
.int Search_GHook_Hook

.section .text.Search_FixCSMState
.arm
mov r7, #0x4

.section .data.Search_FixHeaderIcon
.int 0x35A

.section .data.Search_ChangeHeader_Part1
.int 0xdae
.int 0x7FFFC091

.section .data.Search_ChangeHeader_Part2
.byte 'd'
.byte 0

.section .text.Search_ChangeHeader_Part3
.arm
ldrh r2, [r5, #0x82]

.section .text.Search_Everywhere_Part1
nop
mov r0, r5

.section .text.Search_Everywhere_Part2
cmp r5, #0x05

.section .text.Search_Everywhere_Part3
cmp r4, #0x05

.section .text.Search_Everywhere_Part4
mov r0, #0xFF

.section .text.Search_SetItemIcon_Jump
blx Search_SetItemIcon_Hook

.section .text.Search_FixJavaAttributes
.arm
b . + 0x2C

.section .text.Search_FixGoTo_Part1
.arm
b . + 0x20

.section .text.Search_FixGoTo_Part2
.arm
b . + 0x24

.section .data.Search_Options_FixMenu
.int 0x9

.section .text.Search_Options_FixMenu_Jump
.arm
blx Search_Options_FixMenu_Hook

.section .text.Search_Options_HideItems_Jump
.arm
blx Search_Options_HideItems_Hook

.section .text.Search_Options_FixItemOpen_Part1
.arm
cmp r5, #0xFF

.section .text.Search_Options_FixItemOpen_Part2
.arm
cmp r5, #0xFF
