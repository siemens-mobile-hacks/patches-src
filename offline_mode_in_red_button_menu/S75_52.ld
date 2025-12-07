SECTIONS {
    .CheckNetworkState 0xA0345878 : {
        KEEP(*(.text.CheckNetworkState))
    }
    .ReplaceLgpID_1 0xA0345A3C : {
        KEEP(*(.data.ReplaceLgpID_1))
    }
    .ReplaceLgpID_2 0xA0345A40 : {
        KEEP(*(.data.ReplaceLgpID_2))
    }
    .SwitchOfflineMode 0xA033F054 : {
        KEEP(*(.text.SwitchOfflineMode))
    }
    .SwitchOfflineMode_Jump 0xA03459CE : {
        KEEP(*(.text.SwitchOfflineMode_Jump))
    }
    .ReplaceItemProc 0xA043A4D0 : {
        KEEP(*(.data.ReplaceItemProc))
    }
    .ItemProc 0xA1480DA0 : {
        KEEP(*(.text.ItemProc))
    }
}
