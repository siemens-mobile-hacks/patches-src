SECTIONS {
    .rodata 0xA1300A60 : {
        KEEP(*(.rodata*))
    }

    .FixThemeResourcesPath_Jump 0xA06AD9D8 : {
        KEEP(*(.text.FixThemeResourcesPath_Jump))
    }
    .FixThemeResourcesPath 0xA1300AC0 : {
        KEEP(*(.text.FixThemeResourcesPath))
    }

    .RemoveResources_Jump 0xA074C718 : {
        KEEP(*(.text.RemoveResources_Jump))
    }
    .RemoveResources 0xA1300B60 : {
        KEEP(*(.text.RemoveResources))
    }
}
