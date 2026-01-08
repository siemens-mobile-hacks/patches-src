#include <stdlib.h>
#include <swilib.h>
#include "data.h"
#include "camera.h"

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _udiv ((uint32_t (*)(uint32_t, uint32_t))(ADDR_udiv))
#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _mfree ((void (*)(void *))(ADDR_mfree))
#define _memcpy ((void *(*)(void *, void *, size_t))(ADDR_memcpy))
#define _zeromem ((void (*)(void *, size_t))(ADDR_zeromem))
#define _AllocWS ((WSHDR *(*)(size_t))(ADDR_AllocWS))
#define _FreeWS ((void (*)(WSHDR *))(ADDR_FreeWS))
#define _wstrcat ((void (*)(WSHDR *, WSHDR *))(ADDR_wstrcat))
#define _wsprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wsprintf))
#define _GetDateTime ((void (*)(TDate *, TTime *))(ADDR_GetDateTime))
#define _wstrcatprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wstrcatprintf))
#define _SetHeaderIcon ((void (*)(void *, int *, const void *, const void *))(ADDR_SetHeaderIcon))
#define _GetDataOfItemByID ((WIDGET *(*)(void *, int))(ADDR_GetDataOfItemByID))
#define _SetHeaderExtraText ((void (*)(void *, WSHDR *, const void *, const void *))(ADDR_SetHeaderExtraText))
#define _GUI_GetUserPointer ((void *(*)(void *))(ADDR_GUI_GetUserPointer))
#define _StartNativeExplorer ((int (*)(NativeExplorerData *))(ADDR_StartNativeExplorer))

#define BaseOnRedraw ((void (*)(void *))(ADDR_BaseOnRedraw))
#define SetHeaderLgp ((void (*)(void *, int, const void *, const void *))(ADDR_SetHeaderLgp))

#define RefreshIcons ((void (*)(CAMERA_CSM *, enum Property, int))(ADDR_RefreshIcons))
#define GetCurrentGUI ((CAMERA_GUI *(*)(CAMERA_CSM *))(ADDR_GetCurrentGUI))
#define SetPropertyTemporary ((void (*)(uint32_t, int, int))(ADDR_SetPropertyTemporary))

#define PHOTO_RESOLUTION_0 (ADDR_PhotoResolution_0)
#define PHOTO_RESOLUTION_1 (ADDR_PhotoResolution_1)
#define PHOTO_RESOLUTION_2 (ADDR_PhotoResolution_2)
#define PHOTO_RESOLUTION_3 (ADDR_PhotoResolution_3)
#define PHOTO_RESOLUTION_4 (ADDR_PhotoResolution_4)

__attribute__((target("thumb")))
__attribute__((section(".text.SetResolution_ws")))
void SetResolution_ws(uint32_t is_video, WSHDR *ws, int id) {
    int w = 0, h = 0;
    if (is_video == 0) {
        uint16_t *resolution = PHOTO_RESOLUTION_0;
        if (id == 1) {
            resolution = PHOTO_RESOLUTION_1;
        } else if (id == 2) {
            resolution = PHOTO_RESOLUTION_2;
        } else if (id == 3) {
            resolution = PHOTO_RESOLUTION_3;
        } else if (id == 4) {
            resolution = PHOTO_RESOLUTION_4;
        }
        w = resolution[0];
        h = resolution[1];
    } else {
        if (id == 0) {
            w = 128;
            h = 96;
        } else if (id == 1) {
            w = 176;
            h = 144;
        }
    }
    _wsprintf(ws, "%dx%d", w, h);
}

__attribute__((target("thumb")))
__attribute__((section(".text.OpenNativeExplorer")))
void OpenNativeExplorer(CAMERA_CSM *csm, WSHDR *dir) {
    NativeExplorerData *ne_data = _malloc(sizeof(NativeExplorerData));
    _zeromem(ne_data, sizeof(NativeExplorerData));
    if (dir->wsbody[1] == '0') {
        ne_data->dir_enum = 0x28;  // "0:\"
    } else {
        ne_data->dir_enum = 0x62;; // "4:\"
    }
    ne_data->is_exact_dir = 1;
    csm->native_explorer_csm_id = _StartNativeExplorer(ne_data);
    csm->csm.state = 2;
    csm->execute_proc = 2;
    csm->executed_proc_id = 2;
    _mfree(ne_data);
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetResolutionString_Hook")))
void SetResolutionString_Hook(CAMERA_CSM *csm, int id) {
    CAMERA_GUI *gui = GetCurrentGUI(csm);
    if (gui) {
        if (gui->info_ws) {
            _FreeWS(gui->info_ws);
        }
        gui->info_ws = _AllocWS(16);
        SetResolution_ws(csm->camera_flags & CAMERA_FLAG_VIDEO_MODE, gui->info_ws, 4 - id);
    }
}

#define StartViewFinderWithSize ((void (*)(uint32_t, int, int, int, int, int))(ADDR_StartViewFinderWithSize))

__attribute__((__always_inline__))
inline void GetViewFinderRECT(RECT *rc, int w, int h, int new_w, int new_h) {
    if (new_h) {
        new_w = _udiv(h, w * new_h);
        if (new_w > 350) { // если больше то видоискатель не работает!!!
            new_w = 350;
            goto NEW_H;
        }
    } else {
        NEW_H:
            new_h = _udiv(w, h * new_w);
    }
    rc->x = (int16_t)((240 - new_w) / 2);
    rc->x2 = (int16_t)(rc->x + new_w);
    if (new_h >= 232) {
        rc->y = 24 + 32;
    } else {
        rc->y = (int16_t)(24 + 32 + (232 - new_h) / 2);
    }
    rc->y2 = (int16_t)(rc->y + new_h);
}

__attribute__((target("thumb")))
__attribute__((section(".text.StartViewFinder_Hook")))
void StartViewFinder_Hook(CAMERA_CSM *csm, int is_photo, int x, int y, int x2, int y2) {
    int new_w = 0;
    int new_h = 0;
    if (is_photo) {
        new_h = 320 - 24 - 32 * 2 - 1;
    } else {
        new_w = 239;
    }
    RECT rc;
    GetViewFinderRECT(&rc, x2 - x, y2 - y, new_w, new_h);
    StartViewFinderWithSize(csm->instance_id, is_photo, rc.x, rc.y, rc.x2, rc.y2);
    CAMERA_GUI *gui = GetCurrentGUI(csm);
    if (gui) {
        _memcpy(&(gui->rect_region), &rc, sizeof(RECT));
        _memcpy(&(gui->rect_viewfinder), &rc, sizeof(RECT));
        if (gui->rect_viewfinder.x2 == 239) {
            gui->rect_viewfinder.x2 = 240;
        }
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixStoreCoordinates_Hook")))
void FixStoreCoordinates_Hook(RECT *rc, RECT *rc1, RECT *rc2) {
    if (rc->x < 0) {
        rc->x = 2;
    }
    if (rc->x2 > 239) {
        rc->x2 = 239 - 2;
    }
    _memcpy(rc1, rc, sizeof(RECT));
    _memcpy(rc2, rc, sizeof(RECT));
}

__attribute__((section(".text.SetHeaderLgp_Hook")))
void SetHeaderLgp_Hook(CAMERA_CSM *csm, int lgp_id, const void *malloc_fn, const void *mfree_fn) {
    CAMERA_GUI *gui = GetCurrentGUI(csm);
    void *header = _GetDataOfItemByID(gui, 2);
    if (header) {
        int *icon = (csm->camera_flags & CAMERA_FLAG_VIDEO_MODE) ? VIDEO_ICON : PHOTO_ICON;
        _SetHeaderIcon(header, icon, malloc_fn, mfree_fn);
        SetHeaderLgp(header, lgp_id, malloc_fn, mfree_fn);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.OnRedraw_Hook")))
void OnRedraw_Hook(CAMERA_GUI *gui) {
    void *header = _GetDataOfItemByID(gui, 2);
    if (header) {
        WSHDR *ws = _AllocWS(16);
        int zoom_icon = gui->zoom_icon;
        if (zoom_icon >= 0x107 && zoom_icon <= 0x10B) {
            _wsprintf(ws, "%d", zoom_icon - 0x106);
        }
        if (gui->self_timer_ws) {
            _wstrcatprintf(ws, "|%w", gui->self_timer_ws);
        }
        _SetHeaderExtraText(header, ws, ADDR_malloc, ADDR_mfree);
    }
    BaseOnRedraw(gui);
}

#define OnKey ((int (*)(CAMERA_GUI *, GUI_MSG *))(ADDR_OnKey))

__attribute__((target("thumb")))
__attribute__((section(".text.OnKey_Hook")))
int OnKey_Hook(CAMERA_GUI *gui, GUI_MSG *msg) {
    if (msg->gbsmsg->msg == KEY_DOWN || msg->gbsmsg->msg == LONG_PRESS) {
        const int key = msg->gbsmsg->submess;
        CAMERA_CSM *csm = _GUI_GetUserPointer(gui);
        if (key == VOL_UP_BUTTON) {
            msg->keys = 0x26;
        } else if (key == VOL_DOWN_BUTTON) {
            msg->keys = 0x25;
        } else if (key == '1' || key == '3') {
            if (key == '1') {
                if (data->brightness < 6) {
                    data->brightness++;
                }
            }
            if (key == '3') {
                if (data->brightness > 0) {
                    data->brightness--;
                }
            }
            SetPropertyTemporary(csm->instance_id, PropertyBrightness, data->brightness);
            return -1;
        } else if (key == '#') {
            data->white_balance++;
            if (data->white_balance > 2) {
                data->white_balance = 0;
            }
            SetPropertyTemporary(csm->instance_id, PropertyWhiteBalance, data->white_balance);
            RefreshIcons(csm, PropertyWhiteBalance, data->white_balance);
            return -1;
        } else if (key == '*') {
            data->color_mode++;
            if (data->color_mode > 5) {
                data->color_mode = 0;
            }
            SetPropertyTemporary(csm->instance_id, PropertyColorMode, data->color_mode);
            return -1;
        }
    }
    return OnKey(gui, msg);
}

__attribute__((target("thumb")))
__attribute__((section(".text.GHook")))
void GHook(CAMERA_GUI *gui, enum UIDialogCmdID cmd) {
    if (cmd == UI_CMD_CREATE) {
        malloc_data();
    } else if (cmd == UI_CMD_DESTROY) {
        if (data) {
            free_data();
        }
    }
}

#define Free ((void (*)(CAMERA_CSM *))(ADDR_Free))

__attribute__((target("thumb")))
__attribute__((section(".text.SetSettings_Hook")))
void SetSettings_Hook(CAMERA_CSM *csm) { //
    CAMERA_GUI *gui = GetCurrentGUI(csm);
    if (gui && csm->settings) {
        data->brightness = csm->settings->brightness;
        data->color_mode = csm->settings->color_mode;
    }
    Free(csm);
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetWhiteBalance_Hook")))
void SetWhiteBalance_Hook(CAMERA_CSM *csm, int property_id, uint8_t value) {
    CAMERA_GUI *gui = GetCurrentGUI(csm);
    if (gui) {
        data->white_balance = value;
    }
    RefreshIcons(csm, property_id, value);
}

__attribute__((target("thumb")))
__attribute__((section(".text.ChangeFileName_Hook")))
void ChangeFileName_Hook(WSHDR *path, WSHDR *file_name) {
    register int is_photo asm("r6");
    TDate date; TTime time;
    _GetDateTime(&date, &time);
    _wsprintf(file_name, "%lu-%02d-%02d_%02d-%02d-%02d.",
              date.year, date.month, date.day,
              time.hour, time.min, time.sec);
    if (is_photo == 1) {
        _wstrcatprintf(file_name, "jpg");
    } else {
        _wstrcatprintf(file_name, "3gp");
    }
    _wstrcat(path, file_name);
}

__attribute__((target("thumb")))
__attribute__((section(".text.Settings_SetResolution_Hook")))
void Settings_SetResolution_Hook(int r0, WSHDR *ws, int id) {
    SetResolution_ws((r0 != -1), ws, id);
}
