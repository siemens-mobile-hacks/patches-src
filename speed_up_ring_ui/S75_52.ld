SECTIONS {
    .GrubBGFromLCD_Hook 0xA0B3F1F8 : {
        KEEP(*(.text.GrubBGFromLCD_Hook))
    }
    .GrubBGFromLCD_Jump 0xA0A17A94 : {
        KEEP(*(.text.GrubBGFromLCD_Jump))
    }
}
