#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif

#define OnKey ((int (*)(GUI *gui, GUI_MSG *msg))(ADDR_OnKey))
#define SendCMD ((void (*)(int cmd, void *gui))(ADDR_SendCMD))

__attribute__((target("thumb")))
__attribute__((section(".text.KeyHook")))
int KeyHook(GUI *gui, GUI_MSG *msg) {
    int submess = msg->gbsmsg->submess;
    if (msg->gbsmsg->msg == KEY_DOWN) {
        uint8_t cmd;
        uint8_t *keymap = KEYMAP;
        while ((cmd = keymap[0]) != 0xFF) {
            int scancode = keymap[1];
            if (submess == scancode) {
                SendCMD(cmd, gui);
                return -1;
            }
            keymap += 2;
        }
    }
    return OnKey(gui, msg);
}
