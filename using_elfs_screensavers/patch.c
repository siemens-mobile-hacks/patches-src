#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef S75_52
        #include "S75_52.h"
    #endif
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#else
    #ifdef S65_58
        #include "S65_58.h"
    #endif
#endif

#ifndef ELKA
    #define SCREEN_W 132
    #define SCREEN_H 176
#endif

#define _CreateGUI ((int (*)(GUI *gui))(ADDR_CreateGUI))
#define _GBS_SendMessage ((void (*)(int cepid, int msg, ...))(ADDR_GBS_SendMessage))
#define _GetLangMessIntoWS ((void (*)(int lgp_id, WSHDR *ws))(ADDR_GetLangMessIntoWS))
#define _str_2ws ((void (*)(WSHDR *ws, const char *str, unsigned int size))(ADDR_str_2ws))

#ifndef NEWSGOLD
    #define _DrawRectangle ((void (*)(int, int, int, int, int, const char *, const char *))(ADDR_DrawRectangle))
    #define _GetPaletteAdrByColorIndex ((char* (*)(int index))(ADDR_GetPaletteAdrByColorIndex))
#endif

__attribute__((target("thumb")))
__attribute__((section(".text.CreateGUI")))
int CreateGUI_SS(GUI *gui) {
    int gui_id = _CreateGUI(gui);
#ifdef NEWSGOLD
    if ((unsigned int)gui->definition >= 0xA8000000) {
        _GBS_SendMessage(MMI_CEPID, 0x3FA, gui_id, gui);
    }
#else
    if (gui->definition == DEFINITON_ENERGY_SAVER) {
        _GBS_SendMessage(MMI_CEPID, 0x3FA, gui_id, gui);
    }
#endif
    return gui_id;
}

#ifndef NEWSGOLD
__attribute__((target("thumb")))
__attribute__((section(".text.OnRedraw")))
void OnRedraw() {
    _DrawRectangle(0, 0, SCREEN_W - 1, SCREEN_H - 1, 0,
        _GetPaletteAdrByColorIndex(1), _GetPaletteAdrByColorIndex(1));
}
#endif

__attribute__((target("thumb")))
__attribute__((section(".text.GetLangMessageIntoWS")))
void GetLangMessageIntoWS(int lgp_id, WSHDR *ws) {
     if (lgp_id == LGP_ID_ENERGY_SAVER) {
         _str_2ws(ws, "ELF", 3);
     } else {
         _GetLangMessIntoWS(lgp_id, ws);
     }
}
