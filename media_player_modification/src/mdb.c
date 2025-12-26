#include <swilib.h>
#include "functions.h"

#define MDB_GetFileState ((int (*)(const WSHDR *))(ADDR_MDB_GetFileState))

__attribute__((target("thumb")))
__attribute__((section(".text.MDB_IsAllowFile")))
int MDB_IsAllowFile(const WSHDR *path) {
    WSHDR ws;
    uint16_t wsbody[32];
    _CreateLocalWS(&ws, wsbody, 31);
    _str_2ws(&ws, "zbin\\", 31);
    int uid = _GetExtUidByFileName_ws(path);
    if (uid == 0x27 && _wstriwstr(path, &ws, 3) == 4) { // ignore all png files in X:\\zbin
        return -1;
    }
    return MDB_GetFileState(path);
}

__attribute__((target("thumb")))
__attribute__((section(".text.MDB_FixUI_Hook")))
void MDB_FixUI_Hook(void *gui, ML_MENU_DESC *menu) {
    menu->flags2 = 0x90;
    _SetMenuToGUI(gui, menu);
}

__attribute__((target("thumb")))
__attribute__((section(".text.MDB_FixGetUserPointer_Hook")))
void *MDB_FixGetUserPointer_Hook(void *gui) {
    MDB_CSM *csm = (MDB_CSM*)_MenuGetUserPointer(gui);
    return &(csm->field6_0x30);
}

#define MDB_GHook ((void (*)(void *, int))(ADDR_MDB_GHook))

__attribute__((target("thumb")))
__attribute__((section(".text.MDB_GHook_Hook")))
void MDB_GHook_Hook(void *gui, enum UIDialogCmdID cmd) {
    if (cmd == UI_CMD_FOCUS) {
        MDB_CSM *csm = (MDB_CSM*)_MenuGetUserPointer(gui);

        CSM_RAM *csm_options = _FindCSMbyID(csm->options_csm_id);
        if (csm_options) {
            _MsgBoxError(0x1, LGP_ID_NOT_POSSIBLE_AT_PRESENT);
            return;
        }
        CSM_RAM *mp_csm = _FindCSMbyID(csm->mp_csm_id);
        if (mp_csm) {
            _MsgBoxError(0x1, LGP_ID_NOT_POSSIBLE_AT_PRESENT);
            return;
        }
    } else {
        MDB_GHook(gui, cmd);
    }
}
