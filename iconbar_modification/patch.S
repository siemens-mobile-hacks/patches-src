.section .text.DisableNetworkIcon
.thumb
b . + 0x60

.section .text.DisableBatteryIcon
.thumb
b . + 0x9C


.section .text.DrawIcons_Trampoline
.arm
DrawIcons_Trampoline:
push {r0, r1, lr}
blx DrawIcons_Hook
pop {r0, r1, pc}

.section .text.DrawIcons_Jump_Part1
.thumb
mov r1, r7
blx DrawIcons_Trampoline
b . + 0x13E

.section .text.DrawIcons_Jump_Part2
.thumb
nop

.section .data.ChangeAutoUpdateTimer
.int 500
