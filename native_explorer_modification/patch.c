#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif

#define _wsprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wsprintf))
#define _GetPITaddr ((IMGHDR *(*)(int num))(ADDR_GetPITaddr))
#define _CreateLocalWS ((void (*)(WSHDR *, uint16_t *, int))(ADDR_CreateLocalWS))
#define _GBS_SendMessage ((void (*)(int, int , ...))(ADDR_GBS_SendMessage))
#define _GetHeaderPointer ((void *(*)(void *))(ADDR_GetHeaderPointer))
#define _GetFileAttrib_ws ((int (*)(const WSHDR *, uint8_t *, unsigned int *))(ADDR_GetFileAttrib_ws))
#define _GetMenuItemCount ((int (*)(void *))(ADDR_GetMenuItemCount))
#define _MenuGetUserPointer ((void *(*)(void *))(ADDR_MenuGetUserPointer))

#define MergeIMGHDR ((void (*)(IMGHDR *src, IMGHDR *dest))(ADDR_MergeIMGHDR))
#define MergeIcons_Unk ((void (*)(void *, void *))(ADDR_MergeIcons_Unk))

__attribute__((target("thumb")))
__attribute__((section(".text.MergeIconsHook")))
void MergeIconsHook(void *r0, void *r1, IMGHDR *src) {
    if (((char*)r0)[0x84]) { // enabled mark mode
        src = _GetPITaddr(1336);
    }
    IMGHDR *dest = (IMGHDR*)((char*)r1 + 8);
    MergeIMGHDR(src, dest);
    MergeIcons_Unk(r0, r1);
}

#define SetPreview ((void (*)(void *))(ADDR_SetPreview))

__attribute__((section(".text.SetPreviewHook")))
void SetPreviewHook(void *r0) {
    if (!((char*)r0)[0x84]) { // disabled mark mode
        SetPreview(r0);
    }
}

__attribute__((section(".text.Set2ndTabPath")))
void Set2ndTabPath(void *r0, WSHDR *ws) {
    _wsprintf(ws, "1:\\");
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixInitTabHook")))
int FixInitTabHook(int r0, const WSHDR *ws) {
    int id = ws->wsbody[1] & 0xFF - '0';
    if (id >= 4) {
        id = 3;
    }
    return id;
}

#define LGP_ID_EXTRA_HEADER 0x7FFFC092

#define ClearLgp     ((void (*)(int))(ADDR_ClearLgp))
#define SetLgpText ((void (*)(int, const WSHDR *))(ADDR_SetLgpText))
#define SetHeaderExtraLgp ((void (*)(void *, int, void *, void *))(ADDR_SetHeaderExtraLgp))
#define SetHeaderLgp ((void (*)(void *, int, void *, void *))(0xa0a28138 | 1))
#define GetCurrentItemPath ((void (*)(void *, int, WSHDR *))(ADDR_GetCurrentItemPath))

inline uint8_t GetFileAttr(uint8_t file_attr, uint8_t attr, uint8_t c) {
    return (file_attr & attr) ? c : '-';
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetHeader")))
void SetHeader(int cepid, int msg, int r2, int item_n, void *tab_gui) {
    _GBS_SendMessage(cepid, msg, r2, item_n, tab_gui);

    uint8_t attr = 0;
    if (_GetMenuItemCount(tab_gui)) {
        WSHDR ws_path;
        unsigned int err;
        uint16_t wsbody_path[128];
        register void *gui asm("r4");

        void *data = _MenuGetUserPointer(gui);
        void *csm = (void*)(*(int*)((int)data + 8));

        _CreateLocalWS(&ws_path, wsbody_path, 128);
        GetCurrentItemPath(csm, item_n, &ws_path);
        _GetFileAttrib_ws(&ws_path, &attr, &err);
        WSHDR ws;
        uint16_t wsbody[16];
        _CreateLocalWS(&ws, wsbody, 16);
        _wsprintf(&ws, "[%c%c%c%c]",
                  GetFileAttr(attr, FA_READONLY, 'r'), GetFileAttr(attr, FA_HIDDEN, 'h'),
                  GetFileAttr(attr, FA_SYSTEM, 's'), GetFileAttr(attr, FA_DIRECTORY, 'd'));
        SetLgpText(LGP_ID_EXTRA_HEADER, &ws);
        SetHeaderExtraLgp(_GetHeaderPointer(tab_gui), LGP_ID_EXTRA_HEADER, ADDR_malloc, ADDR_mfree);
        ClearLgp(LGP_ID_EXTRA_HEADER);
    }
}
