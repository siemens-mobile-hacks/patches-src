SECTIONS {
    .text.GrubBGFromLCD_Jump 0xA0A21BA6 : {
        KEEP(*(.text.GrubBGFromLCD_Jump))
    }
    .text.GrubBGFromLCD 0xA0A368B4 : {
        KEEP(*(.text.GrubBGFromLCD))
    }
}
