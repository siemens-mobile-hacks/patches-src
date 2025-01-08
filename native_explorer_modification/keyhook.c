#include <swilib.h>
#include "csm.h"
#include "functions.h"

#ifdef E71_45
    #include "E71_45.h"
#endif

#define OnKey ((int (*)(GUI *gui, GUI_MSG *msg))(ADDR_OnKey))
#define SendCMD ((void (*)(int cmd, void *gui))(ADDR_SendCMD))

__attribute__((target("thumb")))
__attribute__((section(".text.KeyHook")))
int KeyHook(GUI *gui, GUI_MSG *msg) {
    NATIVE_EXPLORER_CSM *csm = GetCSM(gui);
    int submess = msg->gbsmsg->submess;
    if (msg->gbsmsg->msg == KEY_DOWN) {
        uint8_t cmd;
        uint8_t *keymap = KEYMAP;
        while ((cmd = keymap[0]) != 0xFF) {
            int scancode = keymap[1];
            if (submess == scancode) {
                if (csm->mode == NATIVE_EXPLORER_MODE_DEFAULT) {
                    SEND_CMD:
                        SendCMD(cmd, gui);
                        return -1;
                } else if (csm->mode == NATIVE_EXPLORER_MODE_COPY || csm->mode == NATIVE_EXPLORER_MODE_MOVE) {
                    if (cmd == 0x05) {
                        goto SEND_CMD;
                    }
                }
            }
            keymap += 2;
        }
    }
    return OnKey(gui, msg);
}
