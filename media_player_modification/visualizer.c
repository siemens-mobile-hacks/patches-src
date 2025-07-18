#include "functions.h"

#define ROWS    8
#define COLUMNS 14
#define ITEM_W  12
#define ITEM_H 7
#define H_SPACE 4
#define V_SPACE 3

#define GetImgHeightWidth ((void (*)(int picture, int *height, int *width))(ADDR_GetImgHeightWidth))

__attribute__((always_inline))
inline void DrawBG(int y, int height) {
    int y_offset = y - YDISP - 32;
    IMGHDR *img = _GetIMGHDRFromThemeCache(BODY_STANDART);
    _DrawCroppedIMGHDR(0, y, 0, y_offset, 239, height, 0, img);
}

__attribute__((always_inline))
inline void DrawItem(int x, int y, int x2, int y2) {
    _DrawRectangle(x, y, x2, y2, 0, _GetPaletteAdrByColorIndex(0x17), _GetPaletteAdrByColorIndex(PC_FOREGROUND));
    // _DrawRectangle(x + 1, y + 1, x2 - 1, y2 - 1, 0, _GetPaletteAdrByColorIndex(PC_FOREGROUND), _GetPaletteAdrByColorIndex(0x17));
}

__attribute__((target("thumb")))
__attribute__((section(".text.DrawVisualizer_Hook")))
void DrawVisualizer_Hook(int x, int y, int picture, const char *pen, const char *brush) {
    int w, h;
    GetImgHeightWidth(picture, &h, &w);

    DrawBG(y, h);

    x--;
    int y2 = y + h;
    int item_x, item_y, item_x2, item_y2;
    for (int i = 0; i < COLUMNS; i++) {
        item_x = x + (ITEM_W + H_SPACE) * i;
        item_x2 = item_x + ITEM_W;

        int seconds;
        TDate date; TTime time;
        _GetDateTime(&date, &time);
        _GetSecondsFromDateTimeSince1997(&seconds, &date, &time);
        srand(seconds);
        int rows = (_rand() % 8) + 1;
        for (int j = 0; j < rows; j++) {
            item_y = y2 - (ITEM_H * (j + 1)) - H_SPACE * j;
            item_y2 = item_y + ITEM_H;
            DrawItem(item_x, item_y, item_x2, item_y2);
        }
    }
}
