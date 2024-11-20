SECTIONS {
    .PassThemeStructToHook 0xA074B940 : {
        KEEP(*(.text.PassThemeStructToHook_Jump))
    }
    .HookThemeImageLoading_Jump 0xA074B948 : {
        KEEP(*(.text.HookThemeImageLoading_Jump))
    }
    .HookThemeImageLoading 0xA1301B60 : {
        KEEP(*(.text.HookThemeImageLoading))
    }
}
