#include <swilib.h>

#ifdef C72_22
    #include "C72_22.h"
    #define GetNetworkState() (*ADDR_RamNetworkState)
#endif

#define _IsUnlocked ((int (*)())(ADDR_IsUnlocked))
#define _CreateMenu ((int (*)(int, int, MENU_DESC *, HEADER_DESC *, int, int, int, int))(ADDR_CreateMenu))
#define _RebootPhone ((void (*)())(ADDR_RebootPhone))
#define _AllocMenuWS ((WSHDR *(*)(void *, size_t))(ADDR_AllocMenuWS))
#define _AllocMenuItem ((void *(*)(void *))(ADDR_AllocMenuItem))
#define _wstrcapitalize ((void (*)(WSHDR *))(ADDR_wstrcapitalize))
#define _wsRemoveChars ((void (*)(WSHDR *, int, int))(ADDR_wsRemoveChars))
#define _SwitchPhoneOff ((void (*)())(ADDR_SwitchPhoneOff))
#define _GetCurMenuItem ((int (*)(void *))(ADDR_GetCurMenuItem))
#define _SetMenuItemText ((void (*)(void *, void *, WSHDR *, int))(ADDR_SetMenuItemText))
#define _GetLangMesIntoWS ((void (*)(int, WSHDR *))(ADDR_GetLangMesIntoWS))
#define _IsDirectCallActive ((int (*)())(ADDR_IsDirectCallActive))

#define IDLE_OnKey ((int (*)(void *, GUI_MSG *))(ADDR_IDLE_OnKey))
#define IsSIMAvailable ((int (*)())(ADDR_IsSIMAvailable))

__attribute__((target("thumb")))
__attribute__((section(".text.IDLE_OnKey_Hook")))
int IDLE_OnKey_Hook(void *gui, GUI_MSG *msg) {
    if (!_IsDirectCallActive() && _IsUnlocked()) {
        if (msg->gbsmsg->submess == RED_BUTTON) {
            int items = IsSIMAvailable() ? 3 : 2;
            _CreateMenu(1, 0, (MENU_DESC*)0xA17B2080, 0, 0, items, 0, 0);
            return -1;
        }
    }
    return IDLE_OnKey(gui, msg);
}

__attribute__((target("thumb")))
__attribute__((section(".text.ItemProc")))
void ItemProc(void *gui, int item_n, void *user_pointer) {
    void *item = _AllocMenuItem(gui);
    WSHDR *ws = _AllocMenuWS(gui, 128);

    int lgp_id = 0;
    if (item_n == 0) {
        lgp_id = LGP_ID_SHUTDOWN;
    } else if (item_n == 1) {
        lgp_id = LGP_ID_REBOOT;
    } else if (item_n == 2) {
        if (GetNetworkState() == 4) {
            lgp_id = LGP_ID_ONLINE;
        } else {
            lgp_id = LGP_ID_OFFLINE;
        }
    }
    _GetLangMesIntoWS(lgp_id, ws);
    if (item_n == 2) {
        _wsRemoveChars(ws, 1, 1);
        _wstrcapitalize(ws);
    }
    _SetMenuItemText(gui, item, ws, item_n);
}

#define EnableNetwork ((void (*)())(ADDR_EnableNetwork))
#define DisableNetwork ((void (*)())(ADDR_DisableNetwork))

__attribute__((target("thumb")))
__attribute__((section(".text.OnKey")))
int OnKey(void *gui, GUI_MSG *msg) {
    if (msg->gbsmsg->msg == KEY_DOWN) {
        if (msg->gbsmsg->submess == RIGHT_SOFT || msg->gbsmsg->submess == ENTER_BUTTON) {
            int item_n = _GetCurMenuItem(gui);
            if (item_n == 0) {
                _SwitchPhoneOff();
            } else if (item_n == 1) {
                _RebootPhone();
            } else if (item_n == 2) {
                if (GetNetworkState() == 4) {
                    EnableNetwork();
                } else {
                    DisableNetwork();
                }
            }
            return 1;
        }
    }
    return 0;
}
