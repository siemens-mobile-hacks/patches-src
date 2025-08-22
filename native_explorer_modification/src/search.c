#include <swilib.h>
#include "functions.h"
#include "search_csm.h"

#define OnMessage ((int (*)(NATIVE_EXPLORER_SEARCH_CSM *, GBS_MSG *))(ADDR_Search_OnMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.Search_OnMessage_Hook")))
int Search_OnMessage_Hook(NATIVE_EXPLORER_SEARCH_CSM *csm, GBS_MSG *msg) {
    OnMessage(csm, msg);
    return 1;
}

#define OnKey ((int (*)(void *gui, GUI_MSG *msg))(ADDR_Search_OnKey))
#define SendFile ((void (*)(NATIVE_EXPLORER_SEARCH_CSM *))(ADDR_Search_SendFile))
#define ExecuteFile ((void (*)(NATIVE_EXPLORER_SEARCH_CSM *))(ADDR_Search_ExecuteFile))
#define IsFileExists ((int (*)(NATIVE_EXPLORER_SEARCH_CSM *))(ADDR_Search_IsFileExists))
#define CreateOptionsMenu ((int (*)(NATIVE_EXPLORER_SEARCH_CSM *))(ADDR_Search_CreateOptionsMenu))

__attribute__((target("thumb")))
__attribute__((section(".text.Search_OnKey_Hook")))
int Search_OnKey_Hook(void *gui, GUI_MSG *msg) {
    NATIVE_EXPLORER_SEARCH_CSM *csm = _MenuGetUserPointer(gui);
    csm->cursor = _GetCurMenuItem(gui);
    if (msg->keys == 0x3D) { // ENTER_BUTTON
        if (IsFileExists(csm)) {
            ExecuteFile(csm);
            csm->csm.state = 3;
        }
        return -1;
    } else if (msg->keys == 0x36) { // LEFT_SOFT
        if (IsFileExists(csm)) {
            csm->gui_id = CreateOptionsMenu(csm);
            csm->csm.state = 4;
        }
        return -1;
    } else if (msg->keys == 0x05) { // GREEN_BUTTON
        if (IsFileExists(csm)) {
            SendFile(csm);
        }
        return -1;
    }
    return OnKey(gui, msg);
}

#define GHook ((void (*)(void *gui, int cmd))(ADDR_Search_GHook))

__attribute__((target("thumb")))
__attribute__((section(".text.Search_GHook_Hook")))
void Search_GHook_Hook(void *gui, enum UIDialogCmdID cmd) {
    NATIVE_EXPLORER_SEARCH_CSM *csm = _MenuGetUserPointer(gui);
    if (cmd == UI_CMD_CREATE) {
        if (_wstrlen(csm->search_keyword)) {
            WSHDR *ws = _AllocWS(128);
            void *header = _GetHeaderPointer(gui);
            _wsprintf(ws, "%t: \"%w\"", LGP_ID_SEARCH, csm->search_keyword);
            _SetHeaderScrollText(header, ws, ADDR_malloc, ADDR_mfree);
        }
    }
    GHook(gui, cmd);
}

#define GetExtIconSmall ((int *(*)(int uid, int *icon))(ADDR_GetExtIconSmall))

__attribute__((target("thumb")))
__attribute__((section(".text.Search_SetItemIcon_Hook")))
void Search_SetItemIcon_Hook(void *gui, void *item, WSHDR *file_name, int item_n) {
    int uid = _GetExtUidByFileName_ws(file_name);
    if (uid) {
        int *icon = GetExtIconSmall(uid, NULL);
        if (icon) {
            IMGHDR *img = _GetPITaddr(*icon);
            if (img) {
                _SetMenuItemIconIMGHDR(gui, item, img);
                goto END;
            }
        }
    }
    _SetMenuItemIconIMGHDR(gui, item, _GetPITaddr(ICON_UNK));
    END:
        _SetMenuItemText(gui, item, file_name, item_n);
}

__attribute__((target("thumb")))
__attribute__((section(".text.Search_FixGoTo_Hook")))
void Search_FixGoTo_Hook(NativeExplorerData *data) {
    _zeromem(data, sizeof(NativeExplorerData));
    data->dir_enum = 0x26;
    data->is_exact_dir = 1;
}

__attribute__((target("thumb")))
__attribute__((section(".text.Search_Options_FixMenu_Hook")))
void *Search_Options_FixMenu_Hook(void *gui) {
    void *item = _AllocMenuItem(gui);
    _SetMenuItemIconArray(gui, item, ADDR_MENU_ICON_EMPTY);
    return item;
}

#define CreateOptionsGUI ((int (*)(const MENU_DESC *, int, int, void *, int *, int *))(ADDR_Search_CreateOptionsGUI))

__attribute__((target("thumb")))
__attribute__((section(".text.Search_Options_HideItems_Hook")))
int Search_Options_HideItems_Hook(const MENU_DESC *menu, int unk, int n_items, void *unk2, int *hidden_items, int *disabled_items) {
    int count = hidden_items[0];
    hidden_items[++count] = 0xA; //Manage licence
    hidden_items[++count] = 0xB; //Drive info
    hidden_items[++count] = 0xE; //Help
    hidden_items[0] = count;
    return CreateOptionsGUI(menu, unk, n_items, unk2, hidden_items, disabled_items);
}
