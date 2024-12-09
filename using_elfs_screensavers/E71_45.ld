SECTIONS {
    .rodata 0xA07CCED4 : {
        KEEP(*(.rodata*))
    }
    .CreateGUI 0xA06730FC : {
        KEEP(*(.text.CreateGUI))
    }
    .CreateGUI_Jump 0xA070335C : {
        KEEP(*(.text.CreateGUI_Jump))
    }
    .FixScreenSaver_1 0xA0702962 : {
        KEEP(*(.text.FixScreenSaver_1))
    }
    .FixScreenSaver_2 0xA07029B6 : {
        KEEP(*(.text.FixScreenSaver_2))
    }
    .GetLangMessageIntoWS 0xA0673058 : {
        KEEP(*(.text.GetLangMessageIntoWS))
    }
    .GetLangMessageIntoWS_Jump_1 0xA07CA9A6 : {
        KEEP(*(.text.GetLangMessageIntoWS_Jump_1))
    }
    .GetLangMessageIntoWS_Jump_2 0xA093E86C : {
        KEEP(*(.text.GetLangMessageIntoWS_Jump_2))
    }
}
