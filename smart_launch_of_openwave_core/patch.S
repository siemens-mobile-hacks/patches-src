.section .text.OPWV_Launch_Jump
.thumb
bl OPWV_Launch_Hook


.section .text.Trampoline_1
.arm
Trampoline_1:
push {lr}
blx Hook_1
pop {pc}

.section .text.Jump_1
.thumb
blx Trampoline_1
pop {r4, pc}


.section .text.Trampoline_2
.arm
Trampoline_2:
push {lr}
blx Hook_2
pop {pc}

.section .text.Jump_2
.thumb
blx Trampoline_2

.section .text.DisableErrorMessage
.thumb
nop
nop
