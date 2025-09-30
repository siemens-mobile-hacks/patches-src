#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef ELKA
        #include "ELKA.h"
        #ifdef E71_45
            #include "E71_45.h"
        #endif
        #ifdef EL71_45
            #include "EL71_45.h"
        #endif
    #else
        #include "NSG.h"
        #ifdef S75_52
            #include "S75_52.h"
        #endif
        #ifdef C81_51
            #include "C81_51.h"
        #endif
    #endif
#else
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

#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _mfree  ((void (*)(void *))(ADDR_mfree))
#define _SetHeaderIcon ((void (*)(void *, const int *, void *, void *))(ADDR_SetHeaderIcon))
#define _GetHeaderPointer ((void *(*)(void *))(ADDR_GetHeaderPointer))

#define OnCreate_unk ((void (*)(GUI *gui, void *r1, void *r2))(ADDR_OnCreate_unk))
#define OnChange_unk ((void (*)(GUI *gui))(ADDR_OnChange_unk))
#define OnClose_unk  ((void (*)(GUI *gui, void *r1))(ADDR_OnClose_unk))

__attribute__((target("thumb")))
__attribute__((section(".text.NativeMenu_OnCreate")))
void NativeMenu_OnCreate(GUI *gui, void *r1, void *r2) {
    int *icons = _malloc(sizeof(int) * 2);
    icons[0] = ICONS_OFFSET + ICONS_TABLE[4];
    icons[1] = 0;
#ifndef NEWSGOLD
    gui->color1 = (int)icons;
#endif
    OnCreate_unk(gui, r1, r2);
#ifdef NEWSGOLD
    _SetHeaderIcon(_GetHeaderPointer(gui), icons, ADDR_malloc, ADDR_mfree);
    gui->color1 = (int)icons;
#endif
}

__attribute__((target("thumb")))
__attribute__((section(".text.NativeMenu_OnChange")))
void NativeMenu_OnChange(GUI *gui) {
    OnChange_unk(gui);
    int cursor = gui->unk10 - 4;
#ifdef NEWSGOLD
    int *icons = (int*)(gui->color1);
    icons[0] = ICONS_TABLE[cursor] + ICONS_OFFSET;
    #ifdef E71_45
        if (cursor == 8) { //radio or alarm
            int lgp_id = *(int*)(ADDR_RADIO_ALARM_LGP_ID);
            if (lgp_id == LGP_ID_ALARM) {
                icons[0] -= 5;
            }
        }
    #endif
#else
    if (gui->definition == ADDR_NATIVE_MENU_DEFINITION) {
        int *icons = (int*)(gui->color1);
        icons[0] = ICONS_TABLE[cursor] + ICONS_OFFSET;
        _SetHeaderIcon(_GetHeaderPointer(gui), icons, ADDR_malloc, ADDR_mfree);
    }
#endif
}

__attribute__((target("thumb")))
__attribute__((section(".text.NativeMenu_OnClose")))
void NativeMenu_OnClose(GUI *gui, void *r1) {
    _mfree((int*)(gui->color1));
    gui->color1 = 0;
    OnClose_unk(gui, r1);
}
