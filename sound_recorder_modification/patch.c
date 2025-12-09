#include <swilib.h>
#include "sr.h"

#ifdef ELKA
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #define HEADER_H 32
#else
    #ifdef S75_52
        #include "S75_52.h"
    #endif
    #define HEADER_H 22
#endif

#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _mfree ((void (*)(void *))(ADDR_mfree))
#define _zeromem ((void (*)(void *, size_t))(ADDR_zeromem))
#define _wstrcpy ((void (*)(WSHDR *, const WSHDR *))(ADDR_wstrcpy)
#define _CloseCSM ((void (*)(int))(ADDR_CloseCSM))
#define _FindCSMbyID ((void *(*)(int))(ADDR_FindCSMbyID))
#define _MsgBoxError ((int (*)(int, int))(ADDR_MsgBoxError))
#define _DisableIDLETMR ((void (*)())(ADDR_DisableIDLETMR))
#define _GetDataOfItemById ((void *(*)(void *, int))(ADDR_GetDataOfItemById))
#define _DrawCroppedIMGHDR ((void (*)(int, int, int, int, int, int, int, const IMGHDR *))(ADDR_DrawCroppedIMGHDR))
#define _StartNativeExplorer ((int (*)(NativeExplorerData *))(ADDR_StartNativeExplorer))
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

#define List_GHook ((void (*)(void *, enum UIDialogCmdID))(ADDR_List_GHook))

__attribute__((target("thumb")))
__attribute__((section(".text.List_GHook_Hook")))
void List_GHook_Hook(void *gui, enum UIDialogCmdID cmd) {
    List_GHook(gui, cmd);
    if (cmd == UI_CMD_FOCUS) {
        SR_CSM *csm = GetSRCSM();
        SR_LIST_CSM *csm_list = _FindCSMbyID(csm->list_csm_id);
        if (csm_list) {
            SR_RECORDING_CSM *csm_recording = _FindCSMbyID(csm_list->recording_csm_id);
            if (csm_recording) {
                csm->error_csm_id = _MsgBoxError(0x11, LGP_ID_NOT_POSSIBLE_AT_PRESENT);
            }
        }
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
        int width = x2 - x;
        int height = y2 - y;
        _DrawCroppedIMGHDR(x, y, x2 - width, y2 - height - YDISP - HEADER_H, width + 1, height, 0, bg);
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
#ifndef ELKA
    _DisableIDLETMR();
#endif
    SR_CSM *csm = GetSRCSM();
    Recording_SetText(csm_recording->gui, csm->file_name);
    csm_recording->csm.state = 2;
}


__attribute__((target("thumb")))
__attribute__((section(".text.Options_GoTo")))
int Options_GoTo(WSHDR *file_name, WSHDR *dir) {
    NativeExplorerData *data = _malloc(sizeof(NativeExplorerData));
    _zeromem(data, sizeof(NativeExplorerData));
    data->dir_enum = 0x26;
    data->file_name = file_name;
    data->path_to_file = dir;
    data->is_exact_dir = 1;
    int csm_id = _StartNativeExplorer(data);
    _mfree(data);
    return csm_id;
}
