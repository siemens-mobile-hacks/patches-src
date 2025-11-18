SECTIONS {
    .IDLE_OnKey_Jump 0xA049F044 : {
        KEEP(*(.data.IDLE_OnKey_Jump))
    }
    .IDLE_OnKey_Hook 0xA11E2000 : {
        KEEP(*(.text.IDLE_OnKey_Hook))
    }
    .MENU_DESC 0xA11E2080 : {
        KEEP(*(.data.MENU_DESC))
    }
    .ItemProc 0xA11E20B0 : {
        KEEP(*(.text.ItemProc))
    }
    .OnKey 0xA11E2150 : {
        KEEP(*(.text.OnKey))
    }
}
