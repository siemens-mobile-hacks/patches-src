.section .text.FixHeader
.arm
b . + 0x150

.section .text.SetHeaderExtraLgpID
.arm
.int 0x7FFFC092

.section .text.SetHeaderExtra_Jump
.arm
blx SetHeaderExtra_Hook
