SECTIONS {
    .NativeMenu_OnCreate 0xA0CD2070 : {
        KEEP(*(.text.NativeMenu_OnCreate))
    }
    .NativeMenu_OnCreate_Jump 0xA08EBA08 : {
        KEEP(*(.text.NativeMenu_OnCreate_Jump))
    }

    .NativeMenu_OnChange 0xA1227F90 : {
        KEEP(*(.text.NativeMenu_OnChange))
        KEEP(*(.rodata*))
    }
    .NativeMenu_OnChange_Jump 0xA11A72F6 : {
        KEEP(*(.text.NativeMenu_OnChange_Jump))
    }

    .NativeMenu_OnClose 0xA11B6E80 : {
        KEEP(*(.text.NativeMenu_OnClose))
    }
    .NativeMenu_OnClose_Jump 0xA11A76D4 : {
        KEEP(*(.text.NativeMenu_OnClose_Jump))
    }
}
