#include <swilib.h>
#include "../data.h"

#define DrawMediaBitmaps ((void (*)(const MP_GUI *))(ADDR_DrawMediaBitmaps))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawResolution")))
void DrawResolution(MP_GUI *gui) {
    if (gui->media_type == MP_MEDIA_TYPE_IMAGE && !gui->is_fullscreen && !gui->is_zoom) {
        MP_CSM *csm = _MenuGetUserPointer(gui);
        if (csm && csm->file_info) {
            int width = csm->file_info->w;
            int height = csm->file_info->h;
            if (width || height) {
                WSHDR ws;
                uint16_t wsbody[32];
                _CreateLocalWS(&ws, wsbody, 31);

                _wsprintf(&ws, "%dx%d", width, height);

                int y = YDISP + 32;
                int y2 = y + _GetFontYSIZE(FONT_SMALL);
                _DrawString(&ws, 0, y, 239 - 2, y2, FONT_SMALL, TEXT_ALIGNRIGHT | TEXT_OUTLINE,
                            _GetPaletteAdrByColorIndex(PC_FOREGROUND), _GetPaletteAdrByColorIndex(PC_BACKGROUND));
            }
        }
    }
    DrawMediaBitmaps(gui);
}
