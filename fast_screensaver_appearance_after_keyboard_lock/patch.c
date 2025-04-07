#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _CreatePopupGUI ((int (*)(int, void *, POPUP_DESC *, int))(ADDR_CreatePopupGUI))
#define _DrawScreenSaver ((int (*)())(ADDR_DrawScreenSaver))

#define GetScreenSaverType ((int (*)())(ADDR_GetScreenSaverType))

__attribute__((target("thumb")))
__attribute__((section(".text.ShowScreenSaver_Hook")))
int ShowScreenSaver_Hook(int flags, void *user_pointer, POPUP_DESC *desc, int lgp_id) {
    return (GetScreenSaverType() == 0xFF) ? _CreatePopupGUI(flags, user_pointer, desc, lgp_id) : _DrawScreenSaver();
}
