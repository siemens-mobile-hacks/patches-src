.section .text.HookThemeImageLoading_Jump
.arm
bl HookThemeImageLoading

.section .text.PassThemeStructToHook_Jump
.arm
mov r1, r8
