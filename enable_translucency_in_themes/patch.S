#if defined(THUMB_VARIANT)
    .section .text.PassThemeStructToHook_Jump
    .thumb
    mov r1, r7

    .section .text.HookThemeImageLoading_Jump
    .thumb
    bl HookThemeImageLoading
#else
    .section .text.PassThemeStructToHook_Jump
    .arm
    mov r1, r8

    .section .text.HookThemeImageLoading_Jump
    .arm
    bl HookThemeImageLoading
#endif
