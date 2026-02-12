#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef S75_52
        #include "S75_52.h"
    #endif
#endif

#define _GetHeaderPointer ((void* (*)(const GUI *gui))(ADDR_GetHeaderPointer))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
int Hook(const GUI *gui) {
    const int flag30 = gui->flag30;
    const void *header = _GetHeaderPointer(gui);
    if ((flag30 << 0x1E < 0) && (flag30 << 0x1D < 0 || (header != 0x0))) {
        return 0;
    }
    return flag30;
}
