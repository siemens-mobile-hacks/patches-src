#include <swilib.h>

#ifdef SGOLD
    #define CEPID_RAP_BEARER_1 0x4403
    #define MESSAGE "Java is disabled!"
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
#endif

#define _GetGBSProcAddress ((void *(*)(short cepid))(ADDR_GetGBSProcAddress))
#define _MsgBoxError ((int (*)(int flag, int lgp_id))(ADDR_MsgBoxError))
#define _ws_2str ((void (*)(const WSHDR *ws, char *str, size_t size))(ADDR_ws_2str))

#define Alloc ((void *(*)(void *, void *))(ADDR_Alloc))

__attribute__((target("thumb")))
__attribute__((section(".text.ShowErrorMessage1")))
void *ShowErrorMessage1(void *r0, void *r1) {
    if (_GetGBSProcAddress(CEPID_RAP_BEARER_1)) {
        return Alloc(r0, r1);
    } else {
        _MsgBoxError(1, (int)MESSAGE);
        return NULL;
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.ShowErrorMessage2")))
int ShowErrorMessage2(const WSHDR *ws, char *str, size_t size) {
    if (_GetGBSProcAddress(CEPID_RAP_BEARER_1)) {
        _ws_2str(ws, str, size);
        return 1;
    } else {
        _MsgBoxError(1, (int)MESSAGE);
        return 0;
    }
}
