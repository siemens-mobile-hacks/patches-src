.section .text.Insert_Jump_1
.thumb
bl Insert_Hook

.section .text.Insert_Jump_2_Part_1
.thumb
b . + 0xA

.section .text.Insert_Jump_2_Part_2
.thumb
bl Insert_Hook
