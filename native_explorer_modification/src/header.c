#include <swilib.h>
#include "csm.h"
#include "functions.h"

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
