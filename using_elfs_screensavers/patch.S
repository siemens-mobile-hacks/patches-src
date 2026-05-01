#ifdef NEWSGOLD
    .section .text.Outdoor_Add_Part1
    .thumb
    cmp r1, #0x8

    .section .text.Outdoor_Add_Part2
    .thumb
    mov r1, #0x7

    .section .data.Outdoor_RemoveMissedIcon
    .int 0x0
#else
    .section .text.FixScreenSaver_1
    .thumb
    mov r1, #0x01

    .section .text.FixScreenSaver_2
    .thumb
    mov r1, #0x01
#endif

#ifdef NEWSGOLD
    .section .text.FixName_Jump_1
    .thumb
    ldr r1, [r1, r0]
    add r0, r5, #0x00
    bl FixName_Hook

    .section .text.FixName_Jump_2
    .thumb
    mov r1, r2
    bl FixName_Hook
#else
    .section .text.FixName_Jump
    .thumb
    ldr r1, [r1, r0]
    mov r2, #0x00
    add r0, r5, #0x00
    bl FixName_Hook
#endif

#ifdef NEWSGOLD
    .section .text.BaseOnRedraw_Jump
    .thumb
    bl BaseOnRedraw_Hook
#else
    .section .data.OnRedraw_Jump
    .int OnRedraw_Hook
#endif

.section .text.CreateGUI_Jump
.thumb
bl CreateGUI_Hook
