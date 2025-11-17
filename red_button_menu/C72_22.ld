SECTIONS {
    .IDLE_OnKey_Jump 0xA0944190 : {
        KEEP(*(.data.IDLE_OnKey_Jump))
    }
    .IDLE_OnKey_Hook 0xA17B2000 : {
        KEEP(*(.text.IDLE_OnKey_Hook))
    }
    .MENU_DESC 0xA17B2080 : {
        KEEP(*(.data.MENU_DESC))
    }
    .ItemProc 0xA17B20B0 : {
        KEEP(*(.text.ItemProc))
    }
    .OnKey 0xA17B2150 : {
        KEEP(*(.text.OnKey))
    }
}
