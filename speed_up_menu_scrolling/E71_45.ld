SECTIONS {
    .DrawMenuItemScrollText 0xA0A39604 : {
        KEEP(*(.text.DrawMenuItemScrollText))
    }
    .DrawMenuItemScrollText_Jump 0xA0A28C3C : {
        KEEP(*(.text.DrawMenuItemScrollText_Jump))
    }
    .FixR0 0xA0A2B7FE : {
        KEEP(*(.text.FixR0))
    }
    .GrabBGFromLCD 0xA08D2B70 : {
        KEEP(*(.text.GrabBGFromLCD))
    }
    .GrabBGFromLCD_Jump 0xA0A2B804 : {
        KEEP(*(.text.GrabBGFromLCD_Jump))
    }
}
