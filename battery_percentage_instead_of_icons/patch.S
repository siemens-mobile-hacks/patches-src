.section .text.SkipCheck
.thumb
nop

.section .text.DrawPercentage_Jump
.thumb
bl DrawPercentage

.section .text.SkipDrawIMG
.thumb
cmp r6,r6
