.section .data.CPU_LOW_FREQ_DELAY_TICKS
.int 758

.section .text.KeyPressOn_Trampoline
.arm
KeyPressOn_Trampoline:
push {lr}
blx KeyPressOn_Hook
pop {pc}

.section .text.KeyPressOn_Jump
.thumb
blx KeyPressOn_Trampoline
