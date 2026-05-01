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

#define _str_2ws ((void (*)(WSHDR *ws, const char *str, unsigned int size))(ADDR_str_2ws))
#define _CreateGUI ((int (*)(GUI *gui))(ADDR_CreateGUI))
#define _GBS_SendMessage ((void (*)(int cepid, int msg, ...))(ADDR_GBS_SendMessage))
#define _GetLangMessIntoWS ((void (*)(int lgp_id, WSHDR *ws))(ADDR_GetLangMessIntoWS))

#ifdef NEWSGOLD
    #define _IsScreenSaver ((int (*)())(ADDR_IsScreenSaver))

    #define BaseOnRedraw ((void (*)(void *))(ADDR_BaseOnRedraw))
    #define GetScreenSaverType ((uint8_t (*)())(ADDR_GetScreenSaverType))
    #define GetScreenSaverTypeFromSettings ((uint8_t (*)())(ADDR_GetScreenSaverTypeFromSettings))
#else
    #define _DrawRectangle ((void (*)(int, int, int, int, int, const char *, const char *))(ADDR_DrawRectangle))
    #define _GetPaletteAdrByColorIndex ((char* (*)(int index))(ADDR_GetPaletteAdrByColorIndex))
#endif

__attribute__((target("thumb")))
__attribute__((section(".text.FixName_Hook")))
void FixName_Hook(WSHDR *ws, int lgp_id) {
#ifdef NEWSGOLD
    if (lgp_id == LGP_ID_REF1 || lgp_id == LGP_ID_REF2) {
#else
    if (lgp_id == LGP_ID_REF) {
#endif
        _str_2ws(ws, "Third-party", 12);
    } else {
        _GetLangMessIntoWS(lgp_id, ws);
    }
}

#ifdef NEWSGOLD

__attribute__((target("thumb")))
__attribute__((section(".text.GetType")))
int GetType() {
    return (_IsScreenSaver()) ? GetScreenSaverType() : GetScreenSaverTypeFromSettings();
}

__attribute__((target("thumb")))
__attribute__((section(".text.BaseOnRedraw_Hook")))
void BaseOnRedraw_Hook(void *gui) {
    if (GetType() != 2) {
        BaseOnRedraw(gui);
    }
}

#else

__attribute__((target("thumb")))
__attribute__((section(".text.OnRedraw_Hook")))
void OnRedraw_Hook() {
    _DrawRectangle(0, 0, SCREEN_W - 1, SCREEN_H - 1, 0,
        _GetPaletteAdrByColorIndex(1), _GetPaletteAdrByColorIndex(1));
}
#endif

__attribute__((target("thumb")))
__attribute__((section(".text.CreateGUI_Hook")))
int CreateGUI_Hook(GUI *gui) {
    const int gui_id = _CreateGUI(gui);
#ifdef NEWSGOLD
    if (gui->definition == DEFINITION_REF1 || gui->definition == DEFINITION_REF2) {
#else
    if (gui->definition == DEFINITION_REF) {
#endif
        _GBS_SendMessage(MMI_CEPID, 0x3FA, gui_id, gui);
    }
    return gui_id;
}
