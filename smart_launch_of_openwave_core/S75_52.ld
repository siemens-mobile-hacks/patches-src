SECTIONS {
    .OPWV_Launch_Hook 0xA0BFC5C0 : {
        KEEP(*(.text.OPWV_Launch_Hook))
    }
    .OPWV_Launch_Jump 0xA096F7CE : {
        KEEP(*(.text.OPWV_Launch_Jump))
    }

    .Proc_1 0xA3330000 : {
        KEEP(*(.text.Proc_1))
    }
    .Hook_1 0xA3330050 : {
        KEEP(*(.text.Hook_1))
    }
    .Jump_1 0xA0D09D9E : {
        KEEP(*(.text.Jump_1))
    }
    .Trampoline_1 0xA0BB1030 : {
        KEEP(*(.text.Trampoline_1))
    }

    .Proc_2 0xA33300D0 : {
        KEEP(*(.text.Proc_2))
    }
    .Hook_2 0xA3330110 : {
        KEEP(*(.text.Hook_2))
    }
    .Trampoline_2 0xA04F6368 : {
        KEEP(*(.text.Trampoline_2))
    }
    .Jump_2 0xA04FBEFC : {
        KEEP(*(.text.Jump_2))
    }

    .SkipStateCheck 0xA032DBD0 : {
        KEEP(*(.text.SkipStateCheck))
    }
    .DisableErrorMessage 0xA04FBF1A : {
        KEEP(*(.text.DisableErrorMessage))
    }
}
