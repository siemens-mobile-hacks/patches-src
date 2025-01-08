#include <swilib.h>
#include "csm.h"
#include "functions.h"

#define MergeIMGHDR ((void (*)(IMGHDR *src, IMGHDR *dest))(ADDR_MergeIMGHDR))
#define MergeIcons_Unk ((void (*)(void *, void *))(ADDR_MergeIcons_Unk))

__attribute__((target("thumb")))
__attribute__((section(".text.MergeIconsHook")))
void MergeIconsHook(NATIVE_EXPLORER_CSM *csm, void *r1, IMGHDR *src) {
    register int r3 asm("r3");
    if (r3 != 3) {
        if (csm->mark_mode) {
            src = _GetPITaddr(1336);
        }
        IMGHDR *dest = (IMGHDR*)((char*)r1 + 8);
        MergeIMGHDR(src, dest);
    }
    MergeIcons_Unk(csm, r1);
}

__attribute__((target("thumb")))
__attribute__((section(".text.IsAllowThumbnail")))
int IsAllowThumbnail(void *r0) {
    register NATIVE_EXPLORER_CSM *csm asm("r6");
    return *(int*)(r0 + 0x1A8) && !csm->disable_thumbnail && !csm->mark_mode;
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

inline uint8_t GetFileAttr(uint8_t file_attr, uint8_t attr, uint8_t c) {
    return (file_attr & attr) ? c : '-';
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetHeaderExtra_Hook")))
void SetHeaderExtra_Hook(int cepid, int msg, int r2, int item_n, void *tab_gui) {
    _GBS_SendMessage(cepid, msg, r2, item_n, tab_gui);

    uint8_t attr = 0;
    if (_GetMenuItemCount(tab_gui)) {
        WSHDR ws_path;
        unsigned int err;
        uint16_t wsbody_path[128];
        register void *gui asm("r4");

        NATIVE_EXPLORER_CSM *csm = GetCSM(gui);

        _CreateLocalWS(&ws_path, wsbody_path, 128);
        GetItemPath(csm, item_n, &ws_path);
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

__attribute__((target("thumb")))
__attribute__((section(".text.FixPaste_Hook")))
void FixPaste_Hook(NATIVE_EXPLORER_CSM *csm, int item_n, WSHDR *ws) {
    GetItemPath(csm, item_n, ws);
    if (!_wstrlen(ws)) {
        GetCurrentDir(csm, ws);
    }
}

#define IsRootDir ((int (*)(NATIVE_EXPLORER_CSM *csm))(ADDR_IsRootDir))

__attribute__((target("thumb")))
__attribute__((section(".text.FixSoftkeys_Hook")))
int FixSoftkeys_Hook(NATIVE_EXPLORER_CSM *csm) {
    if (_wstrlen(csm->root_dir)) {
        WSHDR current_dir;
        uint16_t wsbody_path[128];
        _CreateLocalWS(&current_dir, wsbody_path, 128);
        GetCurrentDir(csm, &current_dir);
        return _wstrcmp(csm->root_dir, &current_dir) == 0;
    }
    return IsRootDir(csm);
}
