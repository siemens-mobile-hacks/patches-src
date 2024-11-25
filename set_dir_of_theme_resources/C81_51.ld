SECTIONS {
    .rodata 0xA13BFDD0 : {
        KEEP(*(.rodata*))
    }

    .FixThemeResourcesPath_Jump 0xA0550CD0 : {
        KEEP(*(.text.FixThemeResourcesPath_Jump))
    }
    .FixThemeResourcesPath_Trampoline 0xA0550F98 : {
        KEEP(*(.text.FixThemeResourcesPath_Trampoline))
    }
    .FixThemeResourcesPath 0xA13BFE30 : {
        KEEP(*(.text.FixThemeResourcesPath))
    }

    .RemoveResources_Jump 0xA05C7214 : {
        KEEP(*(.text.RemoveResources_Jump))
    }
    .RemoveResources_Trampoline 0xA05C7320 : {
        KEEP(*(.text.RemoveResources_Trampoline))
    }
    .RemoveResources 0xA13BFED0 : {
        KEEP(*(.text.RemoveResources))
    }
}
