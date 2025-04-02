.section .text.CreateGUI_Jump
.thumb
bl CreateGUI_SS

#ifdef ELKA
    .section .text.FixScreenSaver_1
    .thumb
    cmp r5, #0xFF

    .section .text.FixScreenSaver_2
    .thumb
    cmp r5, #0xFF
#else
    .section .text.FixScreenSaver_1
    .thumb
    mov r1, #0x01

    .section .text.FixScreenSaver_2
    .thumb
    mov r1, #0x01
#endif

#ifdef NEWSGOLD
    .section .text.GetLangMessageIntoWS_Jump_1
    .thumb
    bl GetLangMessageIntoWS

    .section .text.GetLangMessageIntoWS_Jump_2
    .thumb
    bl GetLangMessageIntoWS
#else
    .section .data.OnRedraw_Addr
    .int OnRedraw

    .section .text.GetLangMessageIntoWS_Jump
    .thumb
    bl GetLangMessageIntoWS
#endif
