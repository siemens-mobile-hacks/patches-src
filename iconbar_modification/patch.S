.section .text.DisableNetworkIcon
.thumb
b . + 0x60

.section .text.DisableBatteryIcon
.thumb
b . + 0x9C


.section .text.DrawIconBar_Trampoline
.arm
DrawIconBar_Trampoline:
push {r0, r1, lr}
blx DrawIconBar_Hook
pop {r0, r1, pc}

.section .text.DrawIconBar_Jump_Part1
.thumb
mov r1, r7
blx DrawIconBar_Trampoline
b . + 0x13E

.section .text.DrawIconBar_Jump_Part2
.thumb
nop

.section .data.ChangeAutoUpdateTimer
.int 500
