#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif
#ifdef S75_52
    #include "S75_52.h"
#endif

#define _mfree ((void (*)(void *))(ADDR_mfree))
#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _strcpy ((char *(*)(char *, const char*))(ADDR_strcpy))
#define _SUBPROC(f, p2) _GBS_SendMessage(HELPER_CEPID, MSG_HELPER_RUN, p2, f, 0);
#define _NU_Sleep ((void (*)(int))(ADDR_NU_Sleep))
#define _MsgBoxErorr ((int (*)(int, int))(ADDR_MsgBoxError))
#define _GBS_SendMessage ((void (*)(int, int, ...))(ADDR_GBS_SendMessage))

#ifdef ELKA
    #define RAP_SUBMESS 0x6418
#else
    #define RAP_SUBMESS 0x6417
#endif

#define HELPER_CEPID 0x440A
#define MSG_HELPER_RUN 0x0001
#define MSG_ALREADY_RUNNING "OPWV client is already running!"

#define OPWV_GetState ((int (*)())(ADDR_OPWV_GetState))
#define RAP_GBS_SendMessage ((void (*)(int, int, int, int))(ADDR_RAP_GBS_SendMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.OPWV_Launch_Hook")))
void OPWV_Launch_Hook(int msg, int r1, int r2, int r3) {
    if (msg != 1) {
        RAP_GBS_SendMessage(msg, r1, r2, r3);
    }
}


#define OPWV_Messenger_Init ((void (*)(const char *))(ADDR_OPWV_Messenger_Init))
#define OPWV_Messenger_SendMessage ((void (*)(const char *))(ADDR_OPWV_Messenger_SendMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.Proc_1")))
void Proc_1(char *cmd) {
    while (1) {
        if (OPWV_GetState() != 0) {
            break;
        }
        _NU_Sleep(100);
    }
    OPWV_Messenger_Init(cmd);
    OPWV_Messenger_SendMessage(cmd);
    _mfree(cmd);
}

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_1")))
void Hook_1(const char *command) {
    int state = OPWV_GetState();
    if (state == 0) {
        char *cmd = _malloc(128);
        _strcpy(cmd, command);
        RAP_GBS_SendMessage(1, RAP_SUBMESS, 0, 0);
        _SUBPROC(Proc_1, cmd);
    } else if (state == 2) {
        _MsgBoxErorr(1, (int)MSG_ALREADY_RUNNING);
    }
    else {
        OPWV_Messenger_Init(command);
        OPWV_Messenger_SendMessage(command);
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
        RAP_GBS_SendMessage(1, RAP_SUBMESS, 0, 0);
        _SUBPROC(Proc_2, cmd);
    } else if (state == 2) {
        _MsgBoxErorr(1, (int)MSG_ALREADY_RUNNING);
    }
    return state;
}
