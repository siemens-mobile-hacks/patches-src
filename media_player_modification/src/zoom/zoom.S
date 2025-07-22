.section .text.Zoom_DisableSoftKeys_Part_1
.arm
b . + 0xE0

.section .data.Zoom_DisableSoftKeys_Part_2
.short 0x0
.short 0x0
.int 0x7FFFFFFF

.section .data.Zoom_DisableSoftKeys_Part_3
.int 0x7FFFFFFF
