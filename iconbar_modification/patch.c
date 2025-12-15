#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif


#define _DrawImg ((void (*)(int, int, int))(ADDR_DrawImg))
#define _DrawCanvas ((void (*)(void *, int, int, int, int, int))(ADDR_DrawCanvas))
#define _DrawString ((void (*)(const WSHDR *, int, int, int, int, int, int, const char *, const char *))(ADDR_DrawString))
#define _GetTime_ws ((void (*)(WSHDR *, TTime,
#define _GetImgWidth ((int (*)(int))(ADDR_GetImgWidth))
#define _GetImgHeight ((int (*)(int))(ADDR_GetImgHeight))
#define _Get_WS_width ((int (*)(const WSHDR *, int))(ADDR_Get_WS_width))
#define _GetFontYSIZE ((int (*)(int))(ADDR_GetFontYSIZE))
#define _CreateLocalWS ((void (*)(WSHDR *, uint16_t *, int))(ADDR_CreateLocalWS))
#define _GetPaletteAdrByColorIndex ((const char *(*)(int))(ADDR_GetPaletteAdrByColorIndex))

__attribute__((always_inline))
inline int GetIconBarIcon(int n) {
    return *(uint16_t *)(ADDR_RamIconBarList + n * sizeof(uint16_t));
}

__attribute__((target("thumb")))
__attribute__((section(".text.DrawIconBarIcon")))
void DrawIconBarIcon(int x, int picture) {
    _DrawImg(x, (24 - _GetImgHeight(picture)) / 2, picture);
}

#define PutTimeIntoWS ((void (*)(WSHDR *))(ADDR_PutTimeIntoWS))
#define GetNetworkIcon ((int (*)())(ADDR_GetNetworkIcon))
#define GetBatteryIcon ((int (*)())(ADDR_GetBatteryIcon))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawIconBar_Hook")))
void DrawIconBar_Hook(int icons_n, void *data) {
    int x = 0; int y = 0; int x2 = 0; int y2 = 0;
    _DrawCanvas(data, 0, 0, 239, 23, 1);

    WSHDR ws;
    uint16_t wsbody[16];
    _CreateLocalWS(&ws, wsbody, 16);
    PutTimeIntoWS(&ws);
    x = 1;
    y = (24 - _GetFontYSIZE(FONT_SMALL)) / 2;
    x2 = x + _Get_WS_width(&ws, FONT_SMALL);
    _DrawString(&ws, x, y, x2, y + _GetFontYSIZE(FONT_SMALL), FONT_SMALL, 0,
                _GetPaletteAdrByColorIndex(PC_FOREGROUND), _GetPaletteAdrByColorIndex(0x17));

    int w = 0;
    uint16_t picture;
    int network_icon = GetNetworkIcon();
    int battery_icon = GetBatteryIcon();
    if (network_icon != 0xFFFF) {
        w += _GetImgWidth(network_icon) + 8;
    }
    if (battery_icon != 0xFFFF) {
        w += _GetImgWidth(battery_icon) + 8;
    }

    int max_icons = 0;
    for (int i = 0 ; i < icons_n; i++) {
        const int width = _GetImgWidth(GetIconBarIcon(i)) + 8;
        w += width;
        if (239 - w <= x2 + 4) {
            w -= width;
            break;
        }
        max_icons++;
    }
    // w -= 4;
    x = 239 - w;
    for (int i = 0; i < max_icons; i++) {
        picture = GetIconBarIcon(i);
        x += 4;
        DrawIconBarIcon(x, picture);
        x += _GetImgWidth(picture) + 4;
    }
    if (network_icon != 0xFFFF) {
        x += 4;
        DrawIconBarIcon(x, network_icon);
        x += _GetImgWidth(network_icon) + 4;
    }
    if (battery_icon != 0xFFFF) {
        DrawIconBarIcon(x + 4, battery_icon);
    }
}
