.section .data.IDLE_OnKey_Jump
.int IDLE_OnKey_Hook

#if defined(C72_22)
    .equ SOFTKEYS, 0xA0A62578
    .equ SOFTKEYS_TAB, 0xA12241E4
#endif

.section .data.MENU_DESC
.int 0 // flag
.int OnKey
.int 0 // GHook
.int 0 // Locret
.int SOFTKEYS
.int SOFTKEYS_TAB
.int 0x10 // flags2
.int ItemProc // ItemProc
.int 0 // Items
.int 0 // Procs
.int 2 // n_items
