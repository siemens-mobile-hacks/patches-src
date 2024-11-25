SECTIONS {
    .rodata 0xA1093EE0 : {
        KEEP(*(.rodata*))
    }

    .FixThemeResourcesPath_Jump 0xA02F3140 : {
        KEEP(*(.text.FixThemeResourcesPath_Jump))
    }
    .FixThemeResourcesPath_Trampoline 0xA02F3408 : {
        KEEP(*(.text.FixThemeResourcesPath_Trampoline))
    }
    .FixThemeResourcesPath 0xA1093F40 : {
        KEEP(*(.text.FixThemeResourcesPath))
    }

    .RemoveResources_Jump 0xA034F472 : {
        KEEP(*(.text.RemoveResources_Jump))
    }
    .RemoveResources_Trampoline 0xA034F57C : {
        KEEP(*(.text.RemoveResources_Trampoline))
    }
    .RemoveResources 0xA1093FE0 : {
        KEEP(*(.text.RemoveResources))
    }
}
