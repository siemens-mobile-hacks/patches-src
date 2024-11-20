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
    .FixR1_1 0xA16A2934 : {
        KEEP(*(.text.FixR1_1))
    }
    .FixR1_2 0xA16A295E : {
        KEEP(*(.text.FixR1_2))
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
