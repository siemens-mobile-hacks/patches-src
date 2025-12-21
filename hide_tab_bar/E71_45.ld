SECTIONS {
    .HideTabs 0xA0AF7D6A : {
        KEEP(*(.text.HideTabs))
    }
    .FixBodyBG 0xA0A25596 : {
        KEEP(*(.text.FixBodyBG))
    }
    .FixBodyPosition 0xA0A2514A : {
        KEEP(*(.text.FixBodyPosition))
    }

    .CallOnCreateHandlers_Hook 0xA0A4DAD4 : {
        KEEP(*(.text.CallOnCreateHandlers_Hook))
    }
    .CallOnCreateHandlers_Jump 0xA0A256CE : {
        KEEP(*(.text.CallOnCreateHandlers_Jump))
    }
}
