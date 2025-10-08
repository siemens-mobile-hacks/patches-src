#include <swilib.h>

#ifdef SGOLD
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef CF75_23
        #include "CF75_23.h"
    #endif
#endif

#define _GBS_SendMessage ((void (*)(int cepid_to, int msg, int submess))(ADDR_GBS_SendMessage))

#define CardExplorer_Unk ((int (*)(void *r0, int cur, void *r2, void *r3))(ADDR_CardExplorer_Unk))

__attribute__((target("thumb")))
__attribute__((section(".text.FixNavigationInCardExplorer_Hook")))
int FixNavigationInCardExplorer_Hook(void *r0, int cur, void *r2, void *r3) {
    register int prev asm("r5");
    register int total asm("r4");
    register int size asm("r10");
    total += 1;

    if (prev == total - 1) {
        cur = 0;
    } else {
        if (prev == 0) {
            cur = size - 1;
        } else if (prev == 1) {
            cur = size - 3;
        } else if (prev == 2) {
            cur = size - 2;
        }
        if (prev == size - 1) {
            cur = 0;
        } else if (prev == size - 2) {
            cur = 2;
        } else if (prev == size - 3) {
            cur = 1;
        }
        if (cur >= total - 1) {
            cur = total - 1;
        }
    }
    return CardExplorer_Unk(r0, cur, r2, r3);
}

#define OnKey ((int (*)(GUI *gui, GUI_MSG *msg, void *r2))(ADDR_OnKey))

__attribute__((target("thumb")))
__attribute__((section(".text.FixLongPress_Hook")))
int FixLongPress_Hook(GUI *gui, GUI_MSG *msg, void *r2) {
    int button = 0;
    if (msg->keys == 0x2D) {
        button = LEFT_BUTTON;
    }
    else if (msg->keys == 0x2C) {
        button = RIGHT_BUTTON;
    }
    else if (msg->keys == 0x2B) {
        button = UP_BUTTON;
    }
    else if (msg->keys == 0x2A) {
        button = DOWN_BUTTON;
    }
    if (button) {
        _GBS_SendMessage(MMI_CEPID, KEY_DOWN, button);
        return -1;
    }
    else {
        return OnKey(gui, msg, r2);
    }
}
