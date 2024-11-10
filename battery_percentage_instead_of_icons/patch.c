#include <swilib.h>

#ifdef SGOLD
    #ifdef S65_58
        #include "S65_58.h"
    #endif

    #define HEADER_H 18
#endif

#define _CreateLocalWS ((void (*)(WSHDR *ws, uint16_t *wsbody, int len))(ADDR_CreateLocalWS))
#define _wsprintf ((void (*)(WSHDR *ws, const char *format, ...))(ADDR_wsprintf))
#define _GetPaletteAdrByColorIndex ((void* (*)(int index))(ADDR_GetPaletteAdrByColorIndex))
#define _Get_WS_width ((int (*)(WSHDR *ws, int font))(ADDR_Get_WS_width))
#define _GetFontYSIZE ((int (*)(int font))(ADDR_GetFontYSIZE))
#define _DrawCanvas ((void (*)(void *data, int x1, int y1, int x2, int y2, int flag_one))(ADDR_DrawCanvas))
#define _DrawString ((void (*)(WSHDR *ws, int x1, int y1, int x2, int y2, int font, int text_attr, const char *pen, const char *brush))(ADDR_DrawString))

#define GetCap() (*ADDR_RamCap)

#define FONT FONT_SMALL_BOLD

__attribute__((target("thumb")))
__attribute__((section(".text.DrawPercentage")))
void DrawPercentage(void *canvas_data, int x1, int y1, int x2, int y2, int flag_one) {
    WSHDR ws;
    uint16_t wsbody[8];
    _CreateLocalWS(&ws, wsbody, 16);
    _wsprintf(&ws, "%d%", GetCap());

    const int h = _GetFontYSIZE(FONT);
    const int _x1 = 132 - _Get_WS_width(&ws, FONT) - 2;
    const int _x2 = 132 - 2;
    const int _y1 = (HEADER_H - h) / 2;
    const int _y2 = _y1 + h;

    _DrawCanvas(canvas_data, _x1, _y1, _x2, _y2, flag_one);
    _DrawString(&ws, _x1, _y1, _x2, _y2, FONT, 0,
                _GetPaletteAdrByColorIndex(PC_HEADERFOREGROUND), _GetPaletteAdrByColorIndex(23));
}
