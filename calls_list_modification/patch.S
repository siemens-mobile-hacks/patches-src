#ifdef E71_45
    .equ MENU_ICON_EMPTY, 0xA0C3608C
#endif

.section .text.CallRecords_Fix_Part1
.thumb
nop

.section .text.CallRecords_Fix_Part2
.thumb
nop

.section .text.CallRecords_Delete_DisableMessage_AllEntriesDelete
.thumb
mov r0, #0x00
nop

.section .text.CallRecords_Delete_DisableMessage_EntryDeleted
.thumb
mov r0, #0x00
nop

.section .text.CallRecords_Delete_DisableMessage_CannotBeDeleted
.thumb
mov r0, #0x00
nop

.section .text.CallRecords_Delete_FixClose
.thumb
ldr r1, [r4, #0x3C]

.section .data.CallsList_OnCreate_Jump
.int CallsList_OnCreate_Hook

.section .data.CallsList_OnClose_Jump
.int CallsList_OnClose_Hook

.section .data.CallsList_GHook_Jump
.int CallsList_GHook_Hook

.section .text.CallsList_DisablePleaseWait
.thumb
pop {r4, pc}

.section .data.CallsList_View_OnClose_Jump
.int CallsList_View_OnClose_Hook

.section .data.CallsList_View_GHook_Jump
.int CallsList_View_GHook_Hook

.section .text.CallsList_View_FixClose
.thumb
b . + 0xF

.section .data.CallsList_Options_OnCreate_Jump
.int CallsList_Options_OnCreate_Hook

.section .data.CallsList_Options_OnClose_Jump
.int CallsList_Options_OnClose_Hook

.section .text.CallsList_Options_SendMsg_FixClose
.thumb
nop
nop

.section .data.CallsList_Options_FixIndents_Part1
.int 0x19

.section .data.CallsList_Options_FixIndents_Part2
.int MENU_ICON_EMPTY

.section .data.CallsList_Options_FixIndents_Part3
.int MENU_ICON_EMPTY
