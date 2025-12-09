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
    #define _PrepareEditControl ((EDITCONTROL *(*)(EDITCONTROL *))(ADDR_PrepareEditControl))
#else
    #ifdef S75_52
        #include "S75_52.h"
    #endif
#endif

#define _TempLightOn ((void (*)(int, int))(ADDR_TempLightOn))
#define _IsScreenSaver ((int (*)())(ADDR_IsScreenSaver))
#define _IsUnlocked ((int (*)())(ADDR_IsUnlocked))

#ifdef SGOLD
__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
EDITCONTROL *Hook(EDITCONTROL *ec) {
    _TempLightOn(SET_LIGHT_DISPLAY | SET_LIGHT_KEYBOARD, 0x7FFF);
    return _PrepareEditControl(ec);
}

#ifdef SECONDARY_DISPLAY
__attribute__((target("thumb")))
__attribute__((section(".text.Hook_2")))
int Hook_2() {
    _TempLightOn(SET_LIGHT_DISPLAY, 0x7FFF);
    return _IsScreenSaver();
}
#endif
#else
__attribute__((target("thumb")))
__attribute__((section(".text.Hook_1")))
int Hook_1() {
    int result = _IsScreenSaver();
    if (result != 0) {
        _TempLightOn(SET_LIGHT_DISPLAY | SET_LIGHT_KEYBOARD, 0x7FFF);
    }
    return result;
}

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_2")))
int Hook_2() {
    int result = _IsUnlocked();
    if (!result) { // locked
        _TempLightOn(SET_LIGHT_DISPLAY | SET_LIGHT_KEYBOARD, 0x7FFF);
    }
    return result;
}
#endif
