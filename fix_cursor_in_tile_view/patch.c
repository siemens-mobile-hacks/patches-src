#include <swilib.h>

#ifdef SGOLD
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef C72_22
        #include "C72_22.h"
    #endif
#endif

#define _DrawRoundedFrame ((void (*)(int x1, int y1, int x2, int y2, int x_round, int y_round, int flags, const char *pen, const char *brush))(ADDR_DrawRoundedFrame))
#define _GetPaletteAdrByColorIndex ((const char*(*)(int index))(ADDR_GetPaletteAdrByColorIndex))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawRoundedFrame_Hook")))
void DrawRoundedFrame_Hook(int x1, int y1, int x2, int y2, int x_round, int y_round, int flags,
                      const char *pen, void *definition) {
    if (definition != ADDR_NATIVE_MENU_DEFINITION) {
        const char *col_shadow = _GetPaletteAdrByColorIndex(PC_SELECTSHADOW);
        _DrawRoundedFrame(x1 + 1, y1 + 1, x2 + 1, y2 + 1, x_round, y_round, flags, col_shadow, col_shadow);

        _DrawRoundedFrame(x1, y1, x2, y2, x_round, y_round, flags,
                          _GetPaletteAdrByColorIndex(PC_SELECTBORDER), _GetPaletteAdrByColorIndex(PC_SELECTBACKGROUND));
    }
}
