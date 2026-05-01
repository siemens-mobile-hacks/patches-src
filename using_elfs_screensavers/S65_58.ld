SECTIONS {
    .rodata 0xA17200A0 : {
        KEEP(*(.rodata*))
    }

    .FixScreenSaver_1 0xA16A2934 : {
        KEEP(*(.text.FixScreenSaver_1))
    }
    .FixScreenSaver_2 0xA16A295E : {
        KEEP(*(.text.FixScreenSaver_2))
    }
    .FixName_Hook 0xA1720140 : {
        KEEP(*(.text.FixName_Hook))
    }
    .FixName_Jump 0xA16A825E : {
        KEEP(*(.text.FixName_Jump))
    }

    .OnRedraw_Jump 0xA16BA1A0 : {
        KEEP(*(.data.OnRedraw_Jump))
    }
    .OnRedraw_Hook 0xA1720100 : {
        KEEP(*(.text.OnRedraw_Hook))
    }

    .CreateGUI_Hook 0xA17200C0 : {
        KEEP(*(.text.CreateGUI_Hook))
    }
    .CreateGUI_Jump 0xA16A2B3C : {
        KEEP(*(.text.CreateGUI_Jump))
    }
}
