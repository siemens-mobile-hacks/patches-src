SECTIONS {
    .rodata 0xA13BFDD0 : {
        KEEP(*(.rodata*))
    }

    .FixThemeResourcesPath_Jump 0xA0531F20 : {
        KEEP(*(.text.FixThemeResourcesPath_Jump))
    }
    .FixThemeResourcesPath_Trampoline 0xA05321E8 : {
        KEEP(*(.text.FixThemeResourcesPath_Trampoline))
    }
    .FixThemeResourcesPath 0xA13BFE30 : {
        KEEP(*(.text.FixThemeResourcesPath))
    }

    .RemoveResources_Jump 0xA05B1E18 : {
        KEEP(*(.text.RemoveResources_Jump))
    }
    .RemoveResources_Trampoline 0xA05B1F24 : {
        KEEP(*(.text.RemoveResources_Trampoline))
    }
    .RemoveResources 0xA13BFED0 : {
        KEEP(*(.text.RemoveResources))
    }
}
