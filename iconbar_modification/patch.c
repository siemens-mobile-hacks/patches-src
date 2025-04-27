#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif


#define _DrawImg ((void (*)(int, int, int))(ADDR_DrawImg))
#define _DrawCanvas ((void (*)(void *, int, int, int, int, int))(ADDR_DrawCanvas))
#define _GetImgWidth ((int (*)(int))(ADDR_GetImgWidth))
#define _GetImgHeight ((int (*)(int))(ADDR_GetImgHeight))

__attribute__((always_inline))
inline int GetIconBarIcon(int n) {
    return *(uint16_t *)(ADDR_RamIconBarList + n * sizeof(uint16_t));
}

__attribute__((target("thumb")))
__attribute__((section(".text.DrawIconBarIcon")))
void DrawIconBarIcon(int x, int picture) {
    _DrawImg(x, (24 - _GetImgHeight(picture)) / 2, picture);
}

#define GetNetworkIcon ((int (*)())(ADDR_GetNetworkIcon))
#define GetBatteryIcon ((int (*)())(ADDR_GetBatteryIcon))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawIcons_Hook")))
void DrawIcons_Hook(int icons_n, void *data) {
    _DrawCanvas(data, 0, 0, 239, 23, 1);

    int w = 0;
    uint16_t picture;
    int network_icon = GetNetworkIcon();
    int battery_icon = GetBatteryIcon();
    for (int i = 0 ; i < icons_n; i++) {
        picture = GetIconBarIcon(i);
        w += _GetImgWidth(picture) + 8;
    }
    if (network_icon != 0xFFFF) {
        w += _GetImgWidth(network_icon) + 8;
    }
    if (battery_icon != 0xFFFF) {
        w += _GetImgWidth(battery_icon) + 8;
    }
    w -= 4;
    int x = 239 - w;
    for (int i = 0; i < icons_n; i++) {
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

