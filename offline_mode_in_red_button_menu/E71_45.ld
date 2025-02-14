SECTIONS {
    .CheckNetworkState 0xA070242C : {
        KEEP(*(.text.CheckNetworkState))
    }
    .ReplaceLgpID_1 0xA07025F0 : {
        KEEP(*(.data.ReplaceLgpID_1))
    }
    .ReplaceLgpID_2 0xA07025F4 : {
        KEEP(*(.data.ReplaceLgpID_2))
    }
    .SwitchOfflineMode 0xA06FBCBC : {
        KEEP(*(.text.SwitchOfflineMode))
    }
    .SwitchOfflineMode_Jump 0xA0702582 : {
        KEEP(*(.text.SwitchOfflineMode_Jump))
    }
    .ReplaceItemProc 0xA086DC88 : {
        KEEP(*(.data.ReplaceItemProc))
    }
    .ItemProc 0xA1380DA0 : {
        KEEP(*(.text.ItemProc))
    }
}
