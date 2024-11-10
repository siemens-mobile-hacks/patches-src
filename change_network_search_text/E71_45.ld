SECTIONS {
    .IDLE_SetLangMesIntoWS 0xA086A638 : {
        KEEP(*(.text.IDLE_SetLangMesIntoWS))
    }
    .IDLE_SetLangMesIntoWS_Jump 0xA066ECE4 : {
        KEEP(*(.text.IDLE_SetLangMesIntoWS_Jump))
    }

    .ScreenSaver_SetLangMesIntoWS 0xA086A5D4 : {
        KEEP(*(.text.ScreenSaver_SetLangMesIntoWS))
    }
    .ScreenSaver_SetLangMesIntoWS_Jump 0xA0781D90 : {
        KEEP(*(.text.ScreenSaver_SetLangMesIntoWS_Jump))
    }
}
