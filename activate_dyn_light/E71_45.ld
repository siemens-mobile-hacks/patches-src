SECTIONS {
    .SkipCheck_1 0xA05AEBF2 : {
        KEEP(*(.text.SkipCheck_1))
    }
    .SkipCheck_2 0xA05AEC18 : {
        KEEP(*(.text.SkipCheck_2))
    }
    .SkipCheck_3 0xA05AE83C : {
        KEEP(*(.text.SkipCheck_3))
    }
    .FixLgpID 0xA05AEA74 : {
        KEEP(*(.data.FixLgpID))
    }
    .EnableMenuItem 0xA088A24C : {
        KEEP(*(.data.EnableMenuItem))
    }

    .SetVLType_Hook 0xA1381000 : {
        KEEP(*(.text.SetVLType_Hook))
    }
    .SetVLType_Jump 0xA0599BE0 : {
        KEEP(*(.text.SetVLType_Jump))
    }

    .SkipCheck 0xA06D939E : {
        KEEP(*(.text.SkipCheck))
    }
    .SetVibration_Hook 0xA1381020 : {
        KEEP(*(.text.SetVibration_Hook))
    }
    .SetVibration_Trampoline 0xA06D9558 : {
        KEEP(*(.text.SetVibration_Trampoline))
    }
    .SetVibration_Jump 0xA06D93B4 : {
        KEEP(*(.text.SetVibration_Jump))
    }

    .StopVibration_Hook 0xA06D960C : {
        KEEP(*(.text.StopVibration_Hook))
    }
    .StopVibration_Jump 0xA06D9274 : {
        KEEP(*(.text.StopVibration_Jump))
    }
}
