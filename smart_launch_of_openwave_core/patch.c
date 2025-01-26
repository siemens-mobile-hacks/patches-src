#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #define HELPER_CEPID 0x440A
#endif

#define MSG_HELPER_RUN 0x0001

#define _mfree ((void (*)(void *))(ADDR_mfree))
#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _strcpy ((char *(*)(char *, const char*))(ADDR_strcpy))
#define _SUBPROC(f, p2) _GBS_SendMessage(HELPER_CEPID, MSG_HELPER_RUN, p2, f, 0);
#define _NU_Sleep ((void (*)(int))(ADDR_NU_Sleep))
#define _GBS_SendMessage ((void (*)(int, int, ...))(ADDR_GBS_SendMessage))

#define OPWV_GetState ((int (*)())(ADDR_OPWV_GetState))
#define RAP_GBS_SendMessage ((void (*)(int, int, int, int))(ADDR_RAP_GBS_SendMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.OPWV_Launch_Hook")))
void OPWV_Launch_Hook(int r0, int r1, int r2, int r3) {
    if (r0 != 1) {
        RAP_GBS_SendMessage(r0, r1, r2, r3);
    }
}


#define OPWV_StartMessenger_Init ((void (*)(const char *))(ADDR_OPWV_StartMessenger_Init))
#define OPWV_StartMessenger_SendMessage ((void (*)(const char *))(ADDR_OPWV_StartMessenger_SendMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.Proc_1")))
void Proc_1(char *cmd) {
    while (1) {
        if (OPWV_GetState() != 0) {
            break;
        }
        _NU_Sleep(100);
    }
    OPWV_StartMessenger_Init(cmd);
    OPWV_StartMessenger_SendMessage(cmd);
    _mfree(cmd);
}

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_1")))
void Hook_1(const char *command) {
    if (OPWV_GetState() == 0) {
        char *cmd = _malloc(128);
        _strcpy(cmd, command);
        RAP_GBS_SendMessage(1, 0x6418, 0, 0);
        _SUBPROC(Proc_1, cmd);
    } else {
        OPWV_StartMessenger_Init(command);
        OPWV_StartMessenger_SendMessage(command);
    }
}


#define OPWV_StartBrowser ((int (*)(const char *))(ADDR_OPWV_StartBrowser))

__attribute__((target("thumb")))
__attribute__((section(".text.Proc_2")))
void Proc_2(char *cmd) {
    while (1) {
        if (OPWV_GetState() != 0) {
            break;
        }
        _NU_Sleep(100);
    }
    OPWV_StartBrowser(cmd);
    _mfree(cmd);
}

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_2")))
int Hook_2(const char *command) {
    const int state = OPWV_GetState();
    if (state == 0) {
        char *cmd = _malloc(128);
        _strcpy(cmd, command);
        RAP_GBS_SendMessage(1, 0x6418, 0, 0);
        _SUBPROC(Proc_2, cmd);
    }
    return state;
}
