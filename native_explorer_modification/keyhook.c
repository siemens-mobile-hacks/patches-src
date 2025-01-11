#include <swilib.h>
#include "csm.h"
#include "functions.h"

#ifdef E71_45
    #include "E71_45.h"
#endif

#define OnKey ((int (*)(GUI *gui, GUI_MSG *msg))(ADDR_OnKey))
#define SendCMD ((void (*)(int cmd, void *gui))(ADDR_SendCMD))

#define IsAllowKeyHook() (csm->mode == NATIVE_EXPLORER_MODE_DEFAULT || csm->mode == NATIVE_EXPLORER_MODE_COPY || csm->mode == NATIVE_EXPLORER_MODE_MOVE)

__attribute__((target("thumb")))
__attribute__((section(".text.KeyHook")))
int KeyHook(GUI *gui, GUI_MSG *msg) {
    NATIVE_EXPLORER_CSM *csm = GetCSM(gui);
    if (IsAllowKeyHook()) {
        int submess = msg->gbsmsg->submess;
        if (msg->gbsmsg->msg == KEY_DOWN) {
            uint8_t cmd;
            uint8_t *keymap = KEYMAP;
            uint8_t *disabled_cmd = NULL;
            if (csm->mode == NATIVE_EXPLORER_MODE_DEFAULT) {
                disabled_cmd = (csm->mark_mode != 0x01) ? DISABLED_CMD_DEFAULT : DISABLED_CMD_MARK;
            } else if (csm->mode == NATIVE_EXPLORER_MODE_COPY || csm->mode == NATIVE_EXPLORER_MODE_MOVE) {
                disabled_cmd = DISABLED_CMD_CM;
            }
            while ((cmd = keymap[0]) != 0xFF) {
                uint8_t d_cmd = 0xFF;
                uint8_t *p = disabled_cmd;
                if (p) {
                    while (*p != 0xFF) {
                        if (cmd == *p) {
                            d_cmd = cmd;
                            break;
                        }
                        p++;
                    }
                }
                if (d_cmd == 0xFF) {
                    int scancode = keymap[1];
                    if (submess == scancode) {
                        SendCMD(cmd, gui);
                        return -1;
                    }
                }
                keymap += 2;
            }
        }
    }
    return OnKey(gui, msg);
}
