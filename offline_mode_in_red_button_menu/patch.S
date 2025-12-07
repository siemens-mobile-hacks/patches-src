.global GetNetworkState

#ifdef E71_45
    .equ GetNetworkState, (0xA063E8E2 | 1)
#endif
#ifdef S75_52
    .equ GetNetworkState, (0xA02D046E | 1)
#endif

.section .text.CheckNetworkState
.thumb
bl GetNetworkState
cmp r0, #0x02

.section .data.ReplaceLgpID_1
.int 0xEF0

.section .data.ReplaceLgpID_2
.int 0xEF1

.section .data.ReplaceItemProc
.int ItemProc

.section .text.SwitchOfflineMode_Jump
.thumb
bl SwitchOfflineMode
