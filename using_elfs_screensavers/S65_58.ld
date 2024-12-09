SECTIONS {
    .rodata 0xA17200A0 : {
        KEEP(*(.rodata*))
    }
    .CreateGUI 0xA17200C0 : {
        KEEP(*(.text.CreateGUI))
    }
    .CreateGUI_Jump 0xA16A2B3C : {
        KEEP(*(.text.CreateGUI_Jump))
    }
    .FixScreenSaver_1 0xA16A2934 : {
        KEEP(*(.text.FixScreenSaver_1))
    }
    .FixScreenSaver_2 0xA16A295E : {
        KEEP(*(.text.FixScreenSaver_2))
    }
    .OnRedraw_Addr 0xA16BA1A0 : {
        KEEP(*(.data.OnRedraw_Addr))
    }
    .OnRedraw 0xA1720100 : {
        KEEP(*(.text.OnRedraw))
    }
    .GetLangMessageIntoWS 0xA1720140 : {
        KEEP(*(.text.GetLangMessageIntoWS))
    }
    .GetLangMessageIntoWS_Jump 0xA16A8264 : {
        KEEP(*(.text.GetLangMessageIntoWS_Jump))
    }
}
