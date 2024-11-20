.section .text.CreateGUI_Jump
.thumb
bl CreateGUI_SS

.section .text.FixR1_1
.thumb
mov r1,#0x01

.section .text.FixR1_2
.thumb
mov r1,#0x01

.section .data.OnRedraw_Addr
.int 0xA1720101

.section .text.GetLangMessageIntoWS_Jump
.thumb
bl GetLangMessageIntoWS
