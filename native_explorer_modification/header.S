.section .text.FixHeader
.arm
mov r0, r4
bl wstrlen
cmp r0, #0x03
movne r0, r4
movne r1, #0x5C
blne wsAppendChar
b . + 0x138

.section .text.SetHeaderExtraLgpID
.arm
.int 0x7FFFC092

.section .text.SetHeaderExtra_Jump
.arm
blx SetHeaderExtra_Hook
