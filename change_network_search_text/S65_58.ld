SECTIONS {
    .IDLE_SetLangMesIntoWS 0xA17E0300 : {
        KEEP(*(.text.IDLE_SetLangMesIntoWS))
    }
    .IDLE_SetLangMesIntoWS_Jump 0xA16A4F90 : {
        KEEP(*(.text.IDLE_SetLangMesIntoWS_Jump))
    }

    .ScreenSaver_SetLangMesIntoWS 0xA17E0350 : {
        KEEP(*(.text.ScreenSaver_SetLangMesIntoWS))
    }
    .ScreenSaver_SetLangMesIntoWS_Jump 0xA16A8C56 : {
        KEEP(*(.text.ScreenSaver_SetLangMesIntoWS_Jump))
    }
}
