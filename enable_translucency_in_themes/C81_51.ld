SECTIONS {
    .PassThemeStructToHook 0xA05C6D14 : {
        KEEP(*(.text.PassThemeStructToHook_Jump))
    }
    .HookThemeImageLoading_Jump 0xA05C6D18 : {
        KEEP(*(.text.HookThemeImageLoading_Jump))
    }
    .HookThemeImageLoading 0xA06A8050 : {
        KEEP(*(.text.HookThemeImageLoading))
    }
}
