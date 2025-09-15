SECTIONS {
    .PassThemeStructToHook 0xA073D37C : {
        KEEP(*(.text.PassThemeStructToHook_Jump))
    }
    .HookThemeImageLoading_Jump 0xA073D384 : {
        KEEP(*(.text.HookThemeImageLoading_Jump))
    }
    .HookThemeImageLoading 0xA12F5600 : {
        KEEP(*(.text.HookThemeImageLoading))
    }
}
