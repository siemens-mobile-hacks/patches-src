SECTIONS {
    .rodata 0xA12F56A0 : {
        KEEP(*(.rodata*))
    }

    .FixThemeResourcesPath_Jump 0xA06A8318 : {
        KEEP(*(.text.FixThemeResourcesPath_Jump))
    }
    .FixThemeResourcesPath 0xA12F5700 : {
        KEEP(*(.text.FixThemeResourcesPath))
    }

    .RemoveResources_Jump 0xA073E154 : {
        KEEP(*(.text.RemoveResources_Jump))
    }
    .RemoveResources 0xA12F57A0 : {
        KEEP(*(.text.RemoveResources))
    }
}
