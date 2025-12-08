SECTIONS {
    .DrawMenuItemScrollText_Hook 0xA0B51D6C : {
        KEEP(*(.text.DrawMenuItemScrollText_Hook))
    }
    .DrawMenuItemScrollText_Jump 0xA0A1E98C : {
        KEEP(*(.text.DrawMenuItemScrollText_Jump))
    }
    .FixR0 0xA0A21516 : {
        KEEP(*(.text.FixR0))
    }
    .GrabBGFromLCD_Hook 0xA08E8810 : {
        KEEP(*(.text.GrabBGFromLCD_Hook))
    }
    .GrabBGFromLCD_Jump 0xA0A2151C : {
        KEEP(*(.text.GrabBGFromLCD_Jump))
    }
}
