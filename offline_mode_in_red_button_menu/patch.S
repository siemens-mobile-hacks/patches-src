.global GetNetworkState

#ifdef E71_45
    .equ GetNetworkState, (0xA063E8E2 | 1)
#endif

.section .text.CheckNetworkState
.thumb
bl GetNetworkState
cmp r0, #0x04

.section .data.ReplaceLgpID_1
.int 0xEF1

.section .data.ReplaceLgpID_2
.int 0xEF0

.section .data.ReplaceItemProc
.int 0xA1380DA1

.section .text.SwitchOfflineMode_Jump
.thumb
bl SwitchOfflineMode
