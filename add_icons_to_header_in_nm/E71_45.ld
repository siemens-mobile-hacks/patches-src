SECTIONS {
    .NativeMenu_OnCreate 0xA0C9EDF4 : {
        KEEP(*(.text.NativeMenu_OnCreate))
    }
    .NativeMenu_OnCreate_Jump 0xA0A2420E : {
        KEEP(*(.text.NativeMenu_OnCreate_Jump))
    }

    .NativeMenu_OnChange 0xA0C9EE78 : {
        KEEP(*(.text.NativeMenu_OnChange))
        KEEP(*(.rodata*))
    }
    .NativeMenu_OnChange_Jump 0xA0A23E52 : {
        KEEP(*(.text.NativeMenu_OnChange_Jump))
    }

    .NativeMenu_OnClose 0xA0C9EF38 : {
        KEEP(*(.text.NativeMenu_OnClose))
    }
    .NativeMenu_OnClose_Jump 0xA0A2424E : {
        KEEP(*(.text.NativeMenu_OnClose_Jump))
    }
}
