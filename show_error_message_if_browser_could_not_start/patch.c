#ifdef SGOLD
    #ifdef S65_58
        #include "S65_58.h"
    #endif
#endif

#define _MsgBoxError ((int (*)(int flag, int lgp_id))(ADDR_MsgBoxError))

__attribute__((target("thumb")))
__attribute__((section(".text.GetBrowserState")))
int GetBrowserState() {
    uint8_t state = *RamBrowserState;
    if (state == 0) {
        _MsgBoxError(1, (int)"Browser is disabled!");
    } if (state == 2) {
        _MsgBoxError(1, (int)"Browser is already running!");
    } else if (state == 3) {
        state = 0;
    }
    return state;
}
