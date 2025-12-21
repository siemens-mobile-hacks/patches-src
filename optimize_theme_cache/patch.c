#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif


#define _wstrlen ((size_t (*)(const WSHDR *))(ADDR_wstrlen))
#define _GetIMGHDRFromThemeCache ((IMGHDR *(*)(int index))(ADDR_GetIMGHDRFromThemeCache))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_1")))
int Hook_1(const WSHDR *ws) {
    register const unsigned int ***p asm ("r8");
    const unsigned int *addr = **p;
    if (addr == ADDR_background_picture_headline_fullscreen || addr == ADDR_background_picture_body_tab ||
        addr == ADDR_background_picture_bottom_fullscreen || addr == ADDR_statusbar_fullscreen) {
        return 0;
    }
    return _wstrlen(ws);
}

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_2")))
IMGHDR *Hook_2(int index) {
    if (index == HEADLINE_FULLSCREEN || index == BODY_TAB ||
        index == BOTTOM_FULLSCREEN || index == STATUSBAR_FULLSCREEN) {
        return NULL;
    }
    return _GetIMGHDRFromThemeCache(index);
}
