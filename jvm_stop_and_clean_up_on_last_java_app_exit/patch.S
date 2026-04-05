.section .text.JVM_Stop_Jump
.arm
blx JVM_Stop_Hook

.section .text.JVM_Free_Jump
.arm
blx JVM_Free_Hook
