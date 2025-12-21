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
