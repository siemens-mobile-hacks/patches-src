#include <swilib.h>
#include "csm.h"
#include "functions.h"

#define IsThumbnailEnabled ((int (*)())(ADDR_IsThumbnailEnabled))
#define SetThumbnailEnable ((void (*)(int))(ADDR_SetThumbnailEnable))

__attribute__((target("thumb")))
__attribute__((section(".text.5461_OnKey")))
int _5461_OnKey(void *gui, GUI_MSG *msg) {
    if (msg->keys == 0x18 || msg->keys == 0x3D) {
        const int item_n = _GetCurMenuItem(gui);
        NATIVE_EXPLORER_CSM *csm = _GUI_GetUserPointer(gui);
        if (item_n == 0) {
            const int flag = IsThumbnailEnabled();
            SetThumbnailEnable(!flag);
            csm->disable_thumbnail = flag;
            _RefreshGUI();
        }
    }
    return 0;
}

__attribute__((target("thumb")))
__attribute__((section(".text.5461_GHook")))
void _5461_GHook(void *gui, enum UIDialogCmdID cmd) {
    if (cmd == UI_CMD_DESTROY) {
        NATIVE_EXPLORER_CSM *csm = _GUI_GetUserPointer(gui);
        const int tab_n = GetTabByCSM(csm);
        RefreshTab(csm, tab_n);
    }
}
