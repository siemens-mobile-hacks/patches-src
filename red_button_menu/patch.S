#if defined(C72_22)
    .equ SOFTKEYS, 0xA0A62578
    .equ SOFTKEYS_TAB, 0xA12241E4
#endif
#if defined(CX70_56)
    .equ SOFTKEYS, 0xA0A56C40
    .equ SOFTKEYS_TAB, 0xA1227DF4
#endif
#if defined(S65_58)
    .equ SOFTKEYS, 0xA0A2D300
    .equ SOFTKEYS_TAB, 0xA12135D4
#endif

.section .data.IDLE_OnKey_Jump
.int IDLE_OnKey_Hook

.section .data.MENU_DESC
.int 0 // flag
.int OnKey
.int 0 // GHook
.int 0 // Locret
.int SOFTKEYS
.int SOFTKEYS_TAB
.int 0x10 // flags2
.int ItemProc
.int 0 // Items
.int 0 // Procs
.int 2 // n_items
