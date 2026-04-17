.section .text.JVM_StartApplication_Jump
.arm
blx JVM_StartApplication_Hook

.section .data.RB_OnCreate_Jump
.int RB_OnCreate_Hook

.section .data.RB_OnMessage_Jump
.int RB_OnMessage_Hook
