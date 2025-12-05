#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #ifdef S75_52
        #include "S75_52.h"
    #endif
#else
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef C72_22
        #include "C72_22.h"
    #endif
#endif

#define _CreatePopupGUI ((int (*)(int, void *, POPUP_DESC *, int))(ADDR_CreatePopupGUI))

#ifdef NEWSGOLD
    #define GetScreenSaverType ((int (*)())(ADDR_GetScreenSaverType))
    #define IsScreenSaverEnabled() (GetScreenSaverType() == 0xFF)
    #define _DrawScreenSaver ((int (*)())(ADDR_DrawScreenSaver))
#else
    #define IsScreenSaverDisabled ((int (*)())(ADDR_IsScreenSaverDisabled))
    #define IsScreenSaverEnabled() (IsScreenSaverDisabled() == 0)
    #define _DrawScreenSaver ((int (*)())(ADDR_DrawScreenSaver))
#endif


__attribute__((target("thumb")))
__attribute__((section(".text.ShowScreenSaver_Hook")))
int ShowScreenSaver_Hook(int flags, void *user_pointer, POPUP_DESC *desc, int lgp_id) {
    return (IsScreenSaverEnabled()) ? _CreatePopupGUI(flags, user_pointer, desc, lgp_id) : _DrawScreenSaver();
}
