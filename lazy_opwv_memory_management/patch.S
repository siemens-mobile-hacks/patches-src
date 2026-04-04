.equ BROWSER_DEVICE_LAYER_HEAP, 0xA8F93000

.section .text.DisableAutoLoad_Jump
.thumb
bl DisableAutoLoad_Hook

.section .text.MoveBrowserDeviceLayerHeap
.thumb
.balign 4
ldr r0, [pc, #0xC8]
nop

.section .data.BrowserDeviceLayerHeapAddr
.int BROWSER_DEVICE_LAYER_HEAP

.section .text.SkipStateCheck
mov r0, #0xFF
nop

.section .text.OPWV_StartApp_Jump
.thumb
add r0, sp, #0x264
blx OPWV_StartApp_Trampoline
cmp r0, #0x00
beq . + 0x56

.section .text.OPWV_StartApp_Trampoline
.arm
OPWV_StartApp_Trampoline:
    push {r4, lr}
    mov r1, r4
    blx OPWV_StartApp_Hook
    pop {r4, pc}


.section .text.OPWV_StartMessenger_Jump
.thumb
.balign 4
push {r4, lr}
ldr r4, [pc, #0x4]
blx r4
pop {r4, pc}
.int OPWV_StartMessenger_Hook

.section .text.OPWV_Destroy_Jump
.thumb
blx OPWV_Destroy_Trampoline

.section .text.OPWV_Destroy_Trampoline
.arm
OPWV_Destroy_Trampoline:
    push {lr}
    blx OPWV_Destroy_Hook
    pop {pc}

.section .text.SkipMemHeapFreePools
.thumb
nop
nop

.section .data.RB_OnClose_Jump
.int RB_OnClose_Hook