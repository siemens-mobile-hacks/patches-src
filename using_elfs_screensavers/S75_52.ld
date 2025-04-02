SECTIONS {
    .rodata 0xA0610618 : {
        KEEP(*(.rodata*))
    }
    .CreateGUI 0xA034E6D0 : {
        KEEP(*(.text.CreateGUI))
    }
    .CreateGUI_Jump 0xA0346B82 : {
        KEEP(*(.text.CreateGUI_Jump))
    }
    .FixScreenSaver_1 0xA03461B8 : {
        KEEP(*(.text.FixScreenSaver_1))
    }
    .FixScreenSaver_2 0xA0346200 : {
        KEEP(*(.text.FixScreenSaver_2))
    }
    .GetLangMessageIntoWS 0xA0610644 : {
        KEEP(*(.text.GetLangMessageIntoWS))
    }
    .GetLangMessageIntoWS_Jump_1 0xA03A84B4 : {
        KEEP(*(.text.GetLangMessageIntoWS_Jump_1))
    }
    .GetLangMessageIntoWS_Jump_2 0xA0968A94 : {
        KEEP(*(.text.GetLangMessageIntoWS_Jump_2))
    }
}
