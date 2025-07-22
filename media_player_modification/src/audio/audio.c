#include <swilib.h>
#include "../data.h"
#include "../functions.h"

__attribute__((target("thumb")))
__attribute__((section(".text.ChangeTrackName")))
void ChangeTrackName(WSHDR *ws, const WSHDR *artist) {
    _wsInsertChar(ws, ' ', 1);
    _wsInsertChar(ws, '-', 1);
    _wsInsertChar(ws, ' ', 1);
    _wstrinsert(ws, artist, 1);
}

#define DrawVisualizer ((void (*)(MP_GUI *gui, int animation_type))(ADDR_DrawVisualizer))

__attribute__((section(".text.DrawCover")))
void DrawCover(MP_GUI *gui, int animation_type) {
    MP_CSM *csm = _MenuGetUserPointer(gui);
    switch (data->cover.status) {
    case COVER_DISABLED: default:
        DrawVisualizer(gui, animation_type);
        break;
    case COVER_LOADING: break;
    case COVER_LOADED:
        if (data->cover.img) {
            int y = 95;
            int width = gui->gui.canvas->x2 - gui->gui.canvas->x;
            int height = 120;
            IMGHDR *bg = _GetIMGHDRFromThemeCache(BODY_STANDART);
            _DrawCroppedIMGHDR(gui->gui.canvas->x, y, 0, y - YDISP - 32, width, height, 0, bg);
            _DrawIMGHDR(60, y, data->cover.img);
        }
        break;
    }
}
