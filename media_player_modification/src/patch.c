#include <swilib.h>
#include "data.h"
#include "functions.h"

__attribute__((target("thumb")))
__attribute__((section(".text.InitData")))
void InitData(MP_CSM *csm) {
    malloc_data();
    _zeromem(data, sizeof(DATA));
}

__attribute__((target("thumb")))
__attribute__((section(".text.DestroyData")))
void DestroyData(MP_CSM *csm) {
    free_pic_frame();
    free_cover();
    free_data();
}


#define MP_OnKey ((int (*)(MP_GUI *gui, GUI_MSG *msg))(ADDR_OnKey))
#define MP_GHook ((void (*)(MP_GUI *gui, int cmd))(ADDR_GHook))
#define ReloadMenu ((void (*)(MP_GUI *gui))(ADDR_ReloadMenu))
#define ChangeSoundViewMode ((void (*)(MP_GUI *gui, uint8_t mode))(ADDR_ChangeSoundViewMode))

__attribute__((target("thumb")))
__attribute__((section(".text.PlayProc")))
void PlayProc(MP_GUI *gui) {
    MP_CSM *csm = _MenuGetUserPointer(gui);
    if (data->flag == 0) {
        WIDGET *menu = *gui->menu;
        int cursor = _GetCurMenuItem(menu);
        int playing_id = (int)gui->menu[4];
        if (cursor != playing_id) {
            _GBS_SendMessage(MMI_CEPID, 0x8053, cursor, csm->csm.id, 0x1D);
        }
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.HideListProc")))
void HideListProc(MP_GUI *gui) {
    ChangeSoundViewMode(gui, 1);
}

__attribute__((always_inline))
inline int IsDisableNavigation(MP_CSM *csm) {
    return (csm->field110_0xcc != 0 || csm->play_status == MP_PLAY_STATUS_FAST_FORWARD || csm->play_status == MP_PLAY_STATUS_REWIND_BACKWARD);
}

__attribute__((always_inline))
inline void StartTimerHideList(MP_GUI *gui) {
    MP_CSM *csm = _MenuGetUserPointer(gui);
    _GUI_StartTimerProc(gui, data->timer_hide_list, 1000 * 5, (void (*)(void *))HideListProc);
}


#define KeyLock ((void (*)())(ADDR_KeyLock))

__attribute__((target("thumb")))
__attribute__((section(".text.OnKey")))
int OnKey(MP_GUI *gui, GUI_MSG *gui_msg) {
    MP_CSM *csm = _MenuGetUserPointer(gui);
    WIDGET *menu = *gui->menu;

    if (gui->media_type == MP_MEDIA_TYPE_AUDIO) {
        StartTimerHideList(gui);

        int msg = gui_msg->gbsmsg->msg;
        int submess = gui_msg->gbsmsg->submess;
        if (msg == KEY_DOWN) {
            if (submess == '#') {
                return -1;
            }
        } else if (msg == LONG_PRESS) {
            if (submess == '#') {
                KeyLock();
                return -1;
            }
        }
        if (gui->sound_view_mode == MP_SOUND_VIEW_MODE_ANIMATION) {
            if (gui_msg->keys == 0x26 || gui_msg->keys == 0x25) { // UP_BUTTON, DOWN_BUTTON => '#'
                gui_msg->keys = 0x15;
            } else if (msg == KEY_DOWN) {
                if (submess == LEFT_BUTTON || submess == RIGHT_BUTTON) {
                    data->flag = submess;
                    return -1;
                }
            } else if (msg == LONG_PRESS) {
                if (submess == LEFT_BUTTON || RIGHT_BUTTON) {
                    data->flag = 0;
                }
            } else if (msg == KEY_UP) {
                if (submess == data->flag) {
                    if (submess == LEFT_BUTTON) {
                        PREV:
                            gui_msg->gbsmsg->submess = KEY_DOWN;
                            gui_msg->keys = 0x26; // UP_BUTTON
                    } else if (submess == RIGHT_BUTTON) {
                        NEXT:
                            gui_msg->gbsmsg->submess = KEY_DOWN;
                            gui_msg->keys = 0x25; // DOWN_BUTTON
                    }
                }
            }
        } else {
            if (IsDisableNavigation(csm)) {
                if (submess == UP_BUTTON || submess == DOWN_BUTTON) {
                    return -1;
                }
            }
            if (msg == KEY_DOWN || msg == LONG_PRESS) {
                if (submess == UP_BUTTON) {
                    int cursor = _GetCurMenuItem(menu) - 1;
                    if (cursor < 0) {
                        cursor = _GetMenuItemCount(menu) - 1;
                    }
                    _SetCursorToMenuItem(menu, cursor);
                    ReloadMenu(gui);
                    data->flag = submess;
                    return -1;
                } else if (submess == DOWN_BUTTON) {
                    int cursor = _GetCurMenuItem(menu) + 1;
                    if (cursor > _GetMenuItemCount(menu) - 1) {
                        cursor = 0;
                    }
                    _SetCursorToMenuItem(menu, cursor);
                    ReloadMenu(gui);
                    data->flag = submess;
                    return -1;
                }
            } else if (msg == KEY_UP) {
                if (data->flag == submess) {
                    data->flag = 0;
                    _GUI_StartTimerProc(gui, data->timer_play, 500, (void (*)(void*))PlayProc);
                    return -1;
                }
            }
        }
    }
    else if (gui->media_type == MP_MEDIA_TYPE_IMAGE) {
        if (gui_msg->keys == 0x28 || gui_msg->keys == 0x27 || gui_msg->keys == 0x2C || gui_msg->keys == 0x2D) { //LEFT_BUTTON, RIGHT_BUTTON like UP_BUTTON, DOWN_BUTTON
            gui_msg->keys -= 2;
        }
        // if (gui_msg->keys == 0x2A || gui_msg->keys == 0x2B) { // LONG_PRESS
        // }
    }
    return MP_OnKey(gui, gui_msg);
}

__attribute__((target("thumb")))
__attribute__((section(".text.GHook")))
void GHook(MP_GUI *gui, int cmd) {
    MP_CSM *csm = _MenuGetUserPointer(gui);
    if (csm->media_type == MP_MEDIA_TYPE_AUDIO) {
        if (cmd == 0x2) { // create
            data->timer_play = _GUI_NewTimer(gui);
            data->timer_hide_list = _GUI_NewTimer(gui);
        } else if (cmd == 0x3) { // destroy
            _GUI_DeleteTimer(gui, data->timer_play);
            _GUI_DeleteTimer(gui, data->timer_hide_list);
        }
        else if (cmd == 0xA) { //focus
            StartTimerHideList(gui);
        }
    }
    MP_GHook(gui, cmd);
}

#define BaseOnRedraw ((void (*)(void *gui))(ADDR_BaseOnRedraw))

__attribute__((target("thumb")))
__attribute__((section(".text.BaseOnRedraw_Hook")))
void BaseOnRedraw_Hook(MP_GUI *gui) {
    if (gui->media_type == MP_MEDIA_TYPE_AUDIO && gui->sound_view_mode == MP_SOUND_VIEW_MODE_LIST) {
        IMGHDR *img = _GetIMGHDRFromThemeCache(BODY_STANDART);

        WIDGET *menu = *gui->menu;
        WIDGET *header = _GetDataOfItemByID(gui, 2);
        if (header) {
            header->methods->onRedraw(header);
        }

        int x = menu->canvas->x;
        int width = menu->canvas->x2 - x;
        int height = 30;

        int y = YDISP + 32;
        _DrawCroppedIMGHDR(x, y, 0, 0, width, height, 0, img);

        y = menu->canvas->y2;
        int offset_y = menu->canvas->y2 - YDISP - 32;
        _DrawCroppedIMGHDR(x, y, 0, offset_y, width, height, 0, img);

        WIDGET *softkeys = _GetDataOfItemByID(gui, 0);
        if (softkeys) {
            softkeys->methods->onRedraw(softkeys);
        }

    } else {
        BaseOnRedraw(gui);
    }
}

#define MediaDB_GetFileState ((int (*)(const WSHDR *))(ADDR_MediaDB_GetFileState))

__attribute__((target("thumb")))
__attribute__((section(".text.MediaDB_IsAllowFile")))
int MediaDB_IsAllowFile(const WSHDR *path) {
    WSHDR ws;
    uint16_t wsbody[32];
    _CreateLocalWS(&ws, wsbody, 31);
    _str_2ws(&ws, "zbin\\", 31);
    int uid = _GetExtUidByFileName_ws(path);
    if (uid == 0x27 && _wstriwstr(path, &ws, 3) == 4) { // ignore all png files in X:\\zbin
        return -1;
    }
    return MediaDB_GetFileState(path);
}

