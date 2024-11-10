SECTIONS {
    .NativeMenu_OnCreate 0xA0F0F600 : {
        KEEP(*(.text.NativeMenu_OnCreate))
    }
    .NativeMenu_OnCreate_Jump 0xA0D25880 : {
        KEEP(*(.text.NativeMenu_OnCreate_Jump))
    }

    .NativeMenu_OnChange 0xA0F0F660 : {
        KEEP(*(.text.NativeMenu_OnChange))
        KEEP(*(.rodata*))
    }
    .NativeMenu_OnChange_Jump 0xA0D254E2 : {
        KEEP(*(.text.NativeMenu_OnChange_Jump))
    }

    .NativeMenu_OnClose 0xA0F0F6D0 : {
        KEEP(*(.text.NativeMenu_OnClose))
    }
    .NativeMenu_OnClose_Jump 0xA0D258C0 : {
        KEEP(*(.text.NativeMenu_OnClose_Jump))
    }
}
