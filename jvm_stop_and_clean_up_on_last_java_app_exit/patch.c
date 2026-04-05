#include <swilib.h>
#include "jvm_heap.h"
#ifdef E71_45
    #include "E71_45.h"
#endif

#define _mfree ((void (*)(void *))(ADDR_mfree))

#define MSG_STOP_JVM 0x6201

#define MM_EnableJavaBoost ((void (*)(int))(ADDR_MM_EnableJavaBoost))
#define RAP_GBS_SendMessage ((void (*)(int, int))(ADDR_RAP_GBS_SendMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.JVM_Stop_Hook")))
void JVM_Stop_Hook(int disable) {
    MM_EnableJavaBoost(disable);
    if (*RamIsRunJava == 0) {
        RAP_GBS_SendMessage(3, MSG_STOP_JVM);
    }
}

#define HandleMsg ((int (*)(const GBS_MSG *))(ADDR_HandleMsg))

__attribute__((target("thumb")))
__attribute__((section(".text.JVM_Free_Hook")))
int JVM_Free_Hook(const GBS_MSG *msg) {
    int result = HandleMsg(msg);
    if (msg->msg == MSG_STOP_JVM) {
        if (JVM_Heap->slot1) {
            if (JVM_Heap->slot1_heap) {
                _mfree(JVM_Heap->slot1_heap);
                JVM_Heap->slot1_heap = NULL;
            }
            JVM_Heap->slot1 = NULL;
            JVM_Heap->slot1_heap_size = 0;
            *JVM_Slot1_P = 0;
        }
        if (JVM_Heap->slot2) {
            if (JVM_Heap->slot2_heap) {
                _mfree(JVM_Heap->slot2_heap);
                JVM_Heap->slot2_heap = NULL;
            }
            JVM_Heap->slot2 = NULL;
            JVM_Heap->slot2_heap_size = 0;
            *JVM_Slot2_P = 0;
        }
    }
    return result;
}
