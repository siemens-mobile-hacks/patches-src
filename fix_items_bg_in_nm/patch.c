#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef ELKA
        #ifdef E71_45
            #include "E71_45.h"
        #endif
        #define Y_OFFSET (-(24 + 32))
    #endif
#endif


#define _GetIMGHDRFromThemeCache ((IMGHDR *(*)(int))(ADDR_GetIMGHDRFromThemeCache))
#define _DrawCroppedIMGHDR ((void (*)(int, int, int, int, int, int, int, const IMGHDR *))(ADDR_DrawCroppedIMGHDR))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawIconBG")))
void DrawIconBG(void *param) {
    const RECT *rc = *(RECT **)param;
    const IMGHDR *bg = _GetIMGHDRFromThemeCache(BODY_STANDART);
    _DrawCroppedIMGHDR(rc->x, rc->y, rc->x, rc->y + Y_OFFSET, rc->x2 - rc->x + 1, rc->y2 - rc->y + 1, 0, bg);
}
