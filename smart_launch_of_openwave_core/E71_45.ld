SECTIONS {
    .OPWV_Launch_Hook 0xA0944724 : {
        KEEP(*(.text.OPWV_Launch_Hook))
    }
    .OPWV_Launch_Jump 0xA094619E : {
        KEEP(*(.text.OPWV_Launch_Jump))
    }

    .Proc_1 0xA1380400 : {
        KEEP(*(.text.Proc_1))
    }
    .Hook_1 0xA1380460 : {
        KEEP(*(.text.Hook_1))
    }
    .Jump_1 0xA0CD6676 : {
        KEEP(*(.text.Jump_1))
    }
    .Trampoline_1 0xA0CD1314 : {
        KEEP(*(.text.Trampoline_1))
    }

    .Proc_2 0xA13804F0 : {
        KEEP(*(.text.Proc_2))
    }
    .Hook_2 0xA1380540 : {
        KEEP(*(.text.Hook_2))
    }
    .Trampoline_2 0xA05F551C : {
        KEEP(*(.text.Trampoline_2))
    }
    .Jump_2 0xA05FB070 : {
        KEEP(*(.text.Jump_2))
    }

    .DisableErrorMessage 0xA05FB08E : {
        KEEP(*(.text.DisableErrorMessage))
    }
}
