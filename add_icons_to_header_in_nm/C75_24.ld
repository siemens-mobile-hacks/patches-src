SECTIONS {
    .NativeMenu_OnCreate 0xA08080A0 : {
        KEEP(*(.text.NativeMenu_OnCreate))
    }
    .NativeMenu_OnCreate_Jump 0xA08E53C4 : {
        KEEP(*(.text.NativeMenu_OnCreate_Jump))
    }

    .NativeMenu_OnChange 0xA0750F0C : {
        KEEP(*(.text.NativeMenu_OnChange))
        KEEP(*(.rodata*))
    }
    .NativeMenu_OnChange_Jump 0xA08E5026 : {
        KEEP(*(.text.NativeMenu_OnChange_Jump))
    }

    .NativeMenu_OnClose 0xA0813220 : {
        KEEP(*(.text.NativeMenu_OnClose))
    }
    .NativeMenu_OnClose_Jump 0xA08E5404 : {
        KEEP(*(.text.NativeMenu_OnClose_Jump))
    }
}
