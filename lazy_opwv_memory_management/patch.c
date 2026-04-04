#include <swilib.h>
#include "rb.h"
#include "data.h"
#include "opwv.h"
#ifdef E71_45
    #include "E71_45.h"
#endif

#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _mfree ((void (*)(void *))(ADDR_mfree))
#define _strcpy ((char *(*)(char *, const char *))(ADDR_strcpy))
#define _zeromem ((void (*)(void *, size_t))(ADDR_zeromem))
#define _SUBPROC(f, p2) _GBS_SendMessage(HELPER_CEPID, 0x1, p2, f, 0);
#define _NU_Sleep ((void (*)(int))(ADDR_NU_Sleep))
#define _ClearMemory ((void (*)(void *, int))(ADDR_ClearMemory))
#define _GBS_SendMessage ((void (*)(int, int, ...))(ADDR_GBS_SendMessage))
#define _ShowPleaseWaitBox ((int (*)(int))(ADDR_ShowPleaseWaitBox))
#define _GeneralFunc_flag1 ((void (*)(int, int))(ADDR_GeneralFunc_flag1))

#ifdef ELKA
    #define MSG_OPWV_INIT    0x6418
    #define MSG_OPWV_DESTROY 0x6419
#endif

#define MemHeapFreePool ((void (*)(void *, void *))(ADDR_MemHeapFreePool))
#define MemDestroyHeapPool ((void (*)(void *))(ADDR_MemDestroyHeapPool))
#define RAP_GBS_SendMessage ((void (*)(int, int, int, int))(ADDR_RAP_GBS_SendMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.DisableAutoLoad_Hook")))
void DisableAutoLoad_Hook(int rb_id, int msg, int r2, int r3) {
    if (rb_id != 1) { // opwv
        RAP_GBS_SendMessage(rb_id, msg, r2, r3);
    }
}

#define OPWV_GetData ((void *(*)(int id))(ADDR_OPWV_GetData))
#define OPWV_GetState ((int (*)())(ADDR_OPWV_GetState))
#define OPWV_SetState ((void (*)(int state))(ADDR_OPWV_SetState))

__attribute__((target("thumb")))
__attribute__((section(".text.InitData")))
void InitData() {
    if (!(*data)) {
        (*data) = _malloc(sizeof(DATA));
        _zeromem(*(data), sizeof(DATA));
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.InitOPWV")))
void InitOPWV() {
    RAP_GBS_SendMessage(1, MSG_OPWV_INIT, 0, 0);
    (*data)->please_wait_gui_id = _ShowPleaseWaitBox(0x11);
    _SUBPROC((*data)->proc, (*data)->param);
}

__attribute__((target("thumb")))
__attribute__((section(".text.InitWait")))
void InitWait() {
    int state = 0, counter = 0;
    while (counter < 15) {
        state = OPWV_GetState();
        if (state == 1) {
            break;
        }
        _NU_Sleep(50);
        counter++;
    }
    _GeneralFunc_flag1((*data)->please_wait_gui_id, 1);
    (*data)->state = (state == 1) ? 2 : 0;
}

#define OPWV_StartApp ((void (*)(const char *))(ADDR_OPWV_StartApp))
#define OPWV_Messenger_Init ((void (*)(const char *, void *))(0xa0d222e6 | 1))
#define OPWV_Messenger_SendMessage ((void (*)(const char *))(ADDR_OPWV_Messenger_SendMessage | 1))

__attribute__((target("thumb")))
__attribute__((section(".text.StartApp")))
void StartApp(char *param) {
    InitWait();
    OPWV_StartApp(param);
    if (param) {
        _mfree(param);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.StartMessenger")))
void StartMessenger(char *param) {
    InitWait();
    OPWV_Messenger_Init(param, NULL);
    OPWV_Messenger_SendMessage(param);
    if (param) {
        _mfree(param);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.OPWV_StartApp_Hook")))
int OPWV_StartApp_Hook(void *ptr, char *p) {
    InitData();
    if (OPWV_GetState() == 0) {
        if ((*data)->state == 0) {
            (*data)->state = 1;
            (*data)->proc = StartApp;
            (*data)->param = NULL;
            if (p) {
                (*data)->param = _malloc(128);
                _strcpy((*data)->param, p);
            }
            InitOPWV();
        }
    } else if ((*data)->state != 1) {
        _ClearMemory(ptr, 0x130);
        return 1;
    }
    return 0;
}

__attribute__((section(".text.OPWV_StartMessenger_Hook")))
void OPWV_StartMessenger_Hook(const char *cmd, void *p) {
    InitData();
    if (OPWV_GetState() == 0) {
        if ((*data)->state == 0) {
            (*data)->state = 1;
            (*data)->proc = StartMessenger;
            (*data)->param = _malloc(128);
            _strcpy((*data)->param, cmd);
            InitOPWV();
        }
    } else if ((*data)->state != 1) {
        OPWV_Messenger_Init(cmd, p);
        OPWV_Messenger_SendMessage(cmd);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.OPWV_Destroy_Hook")))
void OPWV_Destroy_Hook() {
    OPWV_HEAP_DATA *opwv_heap = OPWV_GetData(3);
    if (opwv_heap) {
        if (opwv_heap->opwv_framework_heap_allocated) {
            MemHeapFreePool(&opwv_heap->opwv_framework_heap, opwv_heap->opwv_framework_heap_mem);
            opwv_heap->field27_0x114 = 0;
            MemDestroyHeapPool(&opwv_heap->opwv_framework_heap);
            _mfree(opwv_heap->opwv_framework_heap_addr);
            opwv_heap->opwv_framework_heap_addr = NULL;
            opwv_heap->opwv_framework_heap_allocated = 0;
        }
        if (opwv_heap->opwv_browser_heap_allocated) {
            MemDestroyHeapPool(&opwv_heap->opwv_browser_heap);
            _mfree(opwv_heap->opwv_browser_heap_addr);
            opwv_heap->opwv_browser_heap_addr = NULL;
            opwv_heap->opwv_browser_heap_allocated = 0;
        }
    }
    OPWV_SetState(0);
    if (*data) {
        _mfree(*data);
        *data = NULL;
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.RB_OnClose_Hook")))
void RB_OnClose_Hook(const RB_CSM *csm) {
    if (csm->rb_id == 1) { // opwv
        RAP_GBS_SendMessage(1, MSG_OPWV_DESTROY, 0, 0);
    }
}
