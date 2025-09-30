SECTIONS {
    .NativeMenu_OnCreate 0xA0811098 : {
        KEEP(*(.text.NativeMenu_OnCreate))
    }
    .NativeMenu_OnCreate_Jump 0xA08EBA08 : {
        KEEP(*(.text.NativeMenu_OnCreate_Jump))
    }

    .NativeMenu_OnChange 0xA0756E2C : {
        KEEP(*(.text.NativeMenu_OnChange))
        KEEP(*(.rodata*))
    }
    .NativeMenu_OnChange_Jump 0xA08EB66A : {
        KEEP(*(.text.NativeMenu_OnChange_Jump))
    }

    .NativeMenu_OnClose 0xA081C218 : {
        KEEP(*(.text.NativeMenu_OnClose))
    }
    .NativeMenu_OnClose_Jump 0xA08EBA48 : {
        KEEP(*(.text.NativeMenu_OnClose_Jump))
    }
}
