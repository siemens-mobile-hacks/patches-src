#include <swilib.h>

#ifdef SGOLD
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
#endif

#define _MenuGetUserPointer ((void* (*)(void *gui))(ADDR_MenuGetUserPointer))
#define CreateDiskSelectionMenu ((void (*)(void *r0))(ADDR_CreateDiskSelectionMenu))

__attribute__((target("thumb")))
__attribute__((section(".text.OpenDisksMenu")))
void *OpenDisksMenu(GUI *gui, GUI_MSG *msg) {
    if (msg->gbsmsg->submess == GREEN_BUTTON) {
        CreateDiskSelectionMenu((void*)*((int*)(*((int*)(gui) + 13)) + 2));
    }
    return _MenuGetUserPointer(gui);
}
