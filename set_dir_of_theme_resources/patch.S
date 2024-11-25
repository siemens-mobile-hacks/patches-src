#if defined(THUMB_VARIANT)
    .section .text.FixThemeResourcesPath_Jump
    .thumb
    blx FixThemeResourcesPath_Trampoline

    .section .text.RemoveResources_Jump
    .thumb
    blx RemoveResources_Trampoline

    .section .text.FixThemeResourcesPath_Trampoline
    .arm
    FixThemeResourcesPath_Trampoline:
    push {lr}
    blx FixThemeResourcesPath
    pop {pc}

    .section .text.RemoveResources_Trampoline
    .arm
    RemoveResources_Trampoline:
    push {lr}
    blx RemoveResources
    pop {pc}
#else
    .section .text.FixThemeResourcesPath_Jump
    .arm
    blx FixThemeResourcesPath

    .section .text.RemoveResources_Jump
    .arm
    blx RemoveResources
#endif
