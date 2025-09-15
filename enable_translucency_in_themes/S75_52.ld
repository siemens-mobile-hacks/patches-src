SECTIONS {
    .PassThemeStructToHook 0xA05B1918 : {
        KEEP(*(.text.PassThemeStructToHook_Jump))
    }
    .HookThemeImageLoading_Jump 0xA05B191C : {
        KEEP(*(.text.HookThemeImageLoading_Jump))
    }
    .HookThemeImageLoading 0xA068FEE4 : {
        KEEP(*(.text.HookThemeImageLoading))
    }
}
