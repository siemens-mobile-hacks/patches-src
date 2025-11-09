#include <swilib.h>

#ifdef SGOLD
    #ifdef CF75_23
        #include "CF75_23.h"
    #endif
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

#define _PrepareEditControl ((EDITCONTROL *(*)(EDITCONTROL *))(ADDR_PrepareEditControl))
#define TemporaryLightOn ((void (*)(int, int))(ADDR_TemporaryLightOn))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
EDITCONTROL *Hook(EDITCONTROL *ec) {
    TemporaryLightOn(SET_LIGHT_DISPLAY | SET_LIGHT_KEYBOARD, 0x7FFF);
    return _PrepareEditControl(ec);
}

#ifdef SECONDARY_DISPLAY

#define _IsScreenSaver ((int (*)())(ADDR_IsScreenSaver))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_2")))
int Hook_2() {
    TemporaryLightOn(SET_LIGHT_DISPLAY, 0x7FFF);
    return _IsScreenSaver();
}

#endif
