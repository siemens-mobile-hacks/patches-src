#include <swilib.h>

#ifdef SGOLD
    #ifdef S65_58
        #include "S65_58.h"
    #endif
#endif

#define _MenuGetUserPointer ((void* (*)(void *gui))(ADDR_MenuGetUserPointer))
#define CreateDisksMenu ((void (*)(void *r0))(ADDR_CreateDisksMenu))

__attribute__((target("thumb")))
__attribute__((section(".text.OpenDisksMenu")))
void *OpenDisksMenu(GUI *gui, GUI_MSG *msg) {
    if (msg->gbsmsg->submess == GREEN_BUTTON) {
        CreateDisksMenu((void*)*((int*)(*((int*)(gui) + 13)) + 2));
    }
    return _MenuGetUserPointer(gui);
}
