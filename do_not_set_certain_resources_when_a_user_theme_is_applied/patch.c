#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _CreateLocalWS ((void (*)(WSHDR *, uint16_t *, int))(ADDR_CreateLocalWS))
#define _Registry_SetResourcePath ((int (*)(int, int, WSHDR *))(ADDR_Registry_SetResourcePath))
#define _Registry_GetResourcePathFromLevel ((int (*)(int, int, int *, WSHDR *))(ADDR_Registry_GetResourcePathFromLevel))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
int Hook(int hmi_key_id, int prio, WSHDR *path) {
    if (hmi_key_id == 0xC9 || hmi_key_id == 0xD5) { //calls, messages
        return 0;
    }
    if (hmi_key_id == 0x67 || hmi_key_id == 0x68) { //startup animation, shutdown animation
        int prio;
        WSHDR ws;
        uint16_t wsbody[128];

        _CreateLocalWS(&ws, wsbody, 127);
        int result = _Registry_GetResourcePathFromLevel(hmi_key_id, -1, &prio, &ws);
        if (result) {
            return 0;
        }
    }
    return _Registry_SetResourcePath(hmi_key_id, prio, path);
}
