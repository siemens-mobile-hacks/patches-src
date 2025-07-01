.section .text.DrawRoundedFrame_Jump_Part1
.thumb
mov r2, #0xFF

.section .text.DrawRoundedFrame_Jump_Part2
.thumb
add r6, r7, #0x00

.section .text.DrawRoundedFrame_Jump_Part3
.thumb
bl DrawRoundedFrame_Hook
