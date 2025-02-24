.section .text.SkipCheck_1
.thumb
mov r0, #0x01
nop

.section .text.SkipCheck_2
.thumb
mov r0, #0x01
nop

.section .text.SkipCheck_3
.thumb
mov r0, #0x01
nop

.section .data.FixLgpID
.int 0x2469

.section .text.IsEnableFeature_Jump
.thumb
bl IsEnableFeature_Hook


.section .text.SetVLType_Jump
.arm
blx SetVLType_Hook

.section .text.SkipCheck
.thumb
mov r0, #0x00
nop

.section .text.SetVibration_Trampoline
.arm
SetVibration_Trampoline:
push {lr}
blx SetVibration_Hook
pop {pc}

.section .text.SetVibration_Jump
.thumb
blx SetVibration_Trampoline


.section .text.StopVibration_Jump
.thumb
bl StopVibration_Hook
