#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #ifdef EL71_45
        #include "EL71_45.h"
    #endif
    #ifdef S75_52
        #include "S75_52.h"
    #endif
    #ifdef S68_52
        #include "S68_52.h"
    #endif
    #ifdef C81_51
        #include "C81_51.h"
    #endif
#endif

#define _wstrcmp ((int (*)(WSHDR *ws1, WSHDR *ws2))(ADDR_wstrcmp))
#define _wsprintf ((void (*)(WSHDR *ws, const char *, ...))(ADDR_wsprintf))
#define _CreateLocalWS ((WSHDR *(*)(WSHDR *header, uint16_t *body, int size))(ADDR_CreateLocalWS))
#define _Registry_SetResourcePath ((unsigned int (*)(int hmi_key_id, int prio, WSHDR *path))(ADDR_Registry_SetResourcePath))

#define DIR "1:\\ThemeResources"

__attribute__((target("thumb")))
__attribute__((section(".text.FixThemeResourcesPath")))
void FixThemeResourcesPath(WSHDR *ws, const char *format, WSHDR *dir, WSHDR *file_name) {
    uint16_t dir1_body[16];
    uint16_t dir2_body[16];
    WSHDR dir1;
    WSHDR dir2;
    _CreateLocalWS(&dir1, dir1_body, 16);
    _CreateLocalWS(&dir2, dir2_body, 16);
    _wsprintf(&dir1, "0:\\Sounds");
    _wsprintf(&dir2, "0:\\Pictures");
    if (_wstrcmp(dir, &dir1) == 0 || _wstrcmp(dir, &dir2) == 0) {
        _wsprintf(ws, "%s\\%w", DIR, file_name);
    } else {
        _wsprintf(ws, "%w\\%w", dir, file_name);
    }
}

#define PphAE_Fs_Remove ((int (*)(WSHDR *path, unsigned int recursive))(ADDR_PphAE_Fs_Remove))

__attribute__((target("thumb")))
__attribute__((section(".text.RemoveResources")))
void RemoveResources() {
    uint16_t ws_body[32];
    WSHDR ws;
    _CreateLocalWS(&ws, ws_body, 32);
    _wsprintf(&ws, "%s", DIR);
    _Registry_SetResourcePath(0x65, 3, NULL); // turnoff wallpaper
    PphAE_Fs_Remove(&ws, 1);
}
