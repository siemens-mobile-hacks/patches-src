#include <swilib.h>

#ifdef SGOLD
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
#endif

#define _GetPaletteAdrByColorIndex ((const char*(*)(int index))(ADDR_GetPaletteAdrByColorIndex))
#define _DrawRoundedFrame ((void (*)(int x1, int y1, int x2, int y2, int x_round, int y_round, int flags, const char *pen, const char *brush))(ADDR_DrawRoundedFrame))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawRoundedFrame_Hook")))
void DrawRoundedFrame_Hook(int x1, int y1, int x2, int y2, int x_round, int y_round, int flags,
                      const char *pen, void *definition) {
    if (definition != ADDR_NATIVE_MENU_DEFINITION) {
        _DrawRoundedFrame(x1, y1, x2, y2, x_round, y_round, flags,
                          _GetPaletteAdrByColorIndex(PC_SELECTBORDER), _GetPaletteAdrByColorIndex(PC_SELECTBACKGROUND));
    }
}
