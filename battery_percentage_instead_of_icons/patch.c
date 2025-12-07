#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef ELKA
        #ifdef E71_45
            #include "E71_45.h"
        #endif
        #define ICONBAR_H 24
    #else
        #ifdef S75_52
            #include "S75_52.h"
        #endif
        #define ICONBAR_H 20
    #endif
#else
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef C72_22
        #include "C72_22.h"
    #endif
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
    #ifdef CF75_23
        #include "CF75_23.h"
    #endif
    #define ICONBAR_H 18
#endif

#define _wsprintf ((void (*)(WSHDR *ws, const char *format, ...))(ADDR_wsprintf))
#define _DrawCanvas ((void (*)(void *data, int x1, int y1, int x2, int y2, int flag_one))(ADDR_DrawCanvas))
#define _DrawString ((void (*)(WSHDR *ws, int x1, int y1, int x2, int y2, int font, int text_attr, const char *pen, const char *brush))(ADDR_DrawString))
#define _Get_WS_width ((int (*)(WSHDR *ws, int font))(ADDR_Get_WS_width))
#define _GetFontYSIZE ((int (*)(int font))(ADDR_GetFontYSIZE))
#define _CreateLocalWS ((void (*)(WSHDR *ws, uint16_t *wsbody, int len))(ADDR_CreateLocalWS))
#define _GetPaletteAdrByColorIndex ((void* (*)(int index))(ADDR_GetPaletteAdrByColorIndex))

#define GetCap() (*ADDR_RamCap)

#ifdef SECONDARY_DISPLAY
    #define _DrawCanvas_2 ((void (*)(void *data, int x1, int y1, int x2, int y2))(ADDR_DrawCanvas_2))

    #define ICONBAR_2_H 14
#endif

#ifdef ELKA
    #define FONT FONT_SMALL
#else
    #define FONT FONT_SMALL_BOLD
#endif

__attribute__((target("thumb")))
__attribute__((section(".text.DrawPercentage")))
void DrawPercentage(void *canvas_data, int x1, int y1, int x2, int y2, int flag_one) {
    WSHDR ws;
    uint16_t wsbody[8];
    _CreateLocalWS(&ws, wsbody, 16);
    _wsprintf(&ws, "%d%", GetCap());

    const int h = _GetFontYSIZE(FONT);
    const int _x1 = x2 - _Get_WS_width(&ws, FONT);
    const int _x2 = x2;

#ifndef SECONDARY_DISPLAY
    const int _y1 = (ICONBAR_H - h) / 2;
    _DrawCanvas(canvas_data, x1, y1, x2, y2, flag_one);
#else
    int _y1;
    if (y1 != 0) {
        _y1 = (ICONBAR_H - h) / 2;
        _DrawCanvas(canvas_data, x1, y1, x2, y2, flag_one);
    } else {
        _y1 = (ICONBAR_2_H - h) / 2;
        _DrawCanvas_2(canvas_data, x1, y1, x2, y2);
    }
#endif

    const int _y2 = _y1 + h;
    _DrawString(&ws, _x1, _y1, _x2, _y2, FONT, 0,
                _GetPaletteAdrByColorIndex(PC_HEADERFOREGROUND), _GetPaletteAdrByColorIndex(23));
}

#ifdef NEWSGOLD
__attribute__((section(".text.DrawPercentage_Trampoline")))
void DrawPercentage_Trampoline(void *canvas_data, int x1, int y1, int x2, int y2, int flag_one) {
    DrawPercentage(canvas_data, x1, y1, x2, y2, flag_one);
}
#endif
