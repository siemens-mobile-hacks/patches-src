.section .data.DisableFastSearch
.int 0x40000092

.section .data.ChangeOnKey
.int 0xA1380A80 | 1

.section .data.DisabledCMD_Default
.byte 0x05
.byte 0xFF

.section .data.DisabledCMD_Mark
.byte 0x02
.byte 0x05
.byte 0x0B
.byte 0x0C
.byte 0x0E
.byte 0x1E
.byte 0xFF

.section .data.DisabledCMD_CopyMove
.byte 0x02;
.byte 0x03;
.byte 0x04;
.byte 0x06;
.byte 0x08;
.byte 0x1E;
.byte 0xFF;
