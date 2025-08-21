#include <swilib.h>
#include "sr.h"

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _wstrcpy ((void (*)(WSHDR *, const WSHDR *))(ADDR_wstrcpy)
#define _CloseCSM ((void (*)(int))(ADDR_CloseCSM))
#define _GetDataOfItemById ((void *(*)(void *, int))(ADDR_GetDataOfItemById))
#define _DrawCroppedIMGHDR ((void (*)(int, int, int, int, int, int, int, const IMGHDR *))(ADDR_DrawCroppedIMGHDR))
#define _GetIMGHDRFromThemeCache ((IMGHDR *(*)(int))(ADDR_GetIMGHDRFromThemeCache))

#define GetSRCSM() (*ADDR_RamSRCSM)

#define List_OnClose ((void (*)(SR_LIST_CSM *csm))(ADDR_List_OnClose))

__attribute__((target("thumb")))
__attribute__((section(".text.List_OnClose_Hook")))
void List_OnClose_Hook(SR_LIST_CSM *csm_list) {
    List_OnClose(csm_list);
    SR_CSM *csm = GetSRCSM();
    if (csm) {
       _CloseCSM(csm->csm.id);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.Recording_DrawWidgetWithBG")))
void Recording_DrawWidgetWithBG(WIDGET *widget) {
    if (widget) {
        IMGHDR *bg = _GetIMGHDRFromThemeCache(BODY_STANDART);
        RECT *canvas = widget->canvas;
        int x = canvas->x, y = canvas->y;
        int x2 = canvas->x2, y2 = canvas->y2;
        int height = canvas->y2 - canvas->y;
        _DrawCroppedIMGHDR(x, y, 0, y2 - YDISP - 32 - height, x2 - x, height, 0, bg);
        widget->methods->onRedraw(widget);
    }
}

#define Recording_UpdateElapsedTime ((void (*)(void *gui, void *unk))(ADDR_Recording_UpdateElapsedTime))

__attribute__((target("thumb")))
__attribute__((section(".text.Recording_FixRedraw_Hook")))
void Recording_FixRedraw_Hook(void *gui, void *unk) {
    Recording_UpdateElapsedTime(gui, unk);

    WIDGET *widget_time = _GetDataOfItemById(gui, 6);
    WIDGET *widget_record_icon = _GetDataOfItemById(gui, 9);
    WIDGET *widget_pbar = _GetDataOfItemById(gui, 10);
    Recording_DrawWidgetWithBG(widget_record_icon);
    Recording_DrawWidgetWithBG(widget_time);
    if (widget_pbar) {
        widget_pbar->methods->onRedraw(widget_pbar);
    }
}

#define Recording_SetText ((void (*)(void *gui, const WSHDR *))(ADDR_Recording_SetText))

__attribute__((target("thumb")))
__attribute__((section(".text.Recording_ChangeText_Hook")))
void Recording_ChangeText_Hook(SR_RECORDING_CSM *csm_recording) {
    SR_CSM *csm = GetSRCSM();
    Recording_SetText(csm_recording->gui, csm->file_name);
    csm_recording->csm.state = 2;
}
