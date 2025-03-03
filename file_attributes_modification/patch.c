#include <swilib.h>

#ifdef NEWSGOLD
    #define CHECKED   0xE116
    #define UNCHECKED 0xE117
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _AllocWS ((WSHDR *(*)(size_t))(ADDR_AllocWS))
#define _wstrcat ((WSHDR *(*)(WSHDR *, const WSHDR *))(ADDR_wstrcat))
#define _wstrchr ((int (*)(const WSHDR *, uint32_t, uint32_t))(ADDR_wstrchr))
#define _wsprintf ((void (*)(WSHDR *, const char *format, ...))(ADDR_wsprintf))
#define _wstrwstr ((int (*)(const WSHDR *, const WSHDR *, uint32_t))(ADDR_wstrwstr))
#define _wsCharAt ((uint16_t (*)(const WSHDR *, uint16_t pos))(ADDR_wsCharAt))
#define _isdir_ws ((int (*)(const WSHDR *, uint32_t *))(ADDR_isdir_ws))
#define _RefreshGUI ((void (*)())(ADDR_RefreshGUI))
#define _wstrreplace ((void (*)(WSHDR *, const WSHDR *, uint32_t))(ADDR_wstrreplace))
#define _wstrcpybypos ((void (*)(WSHDR *, const WSHDR *, int, size_t))(ADDR_wstrcpybypos))
#define _wsAppendChar ((void (*)(WSHDR *, uint16_t))(ADDR_wsAppendChar))
#define _wsInsertChar ((int (*)(WSHDR *, uint16_t, int))(ADDR_wsInsertChar))
#define _TViewSetText ((void (*)(void *, const WSHDR *, void *, void *))(ADDR_TViewSetText))
#define _wsRemoveChars ((void (*)(WSHDR *, int, int))(ADDR_wsRemoveChars))
#define _CreateLocalWS ((void (*)(WSHDR *, uint16_t *, int))(ADDR_CreateLocalWS))
#define _GeneralFuncF1 ((void (*)(int))(ADDR_GeneralFuncF1))
#define _GetFileAttrib_ws ((int (*)(const WSHDR *, uint8_t *, uint32_t *))(ADDR_GetFileAttrib_ws))
#define _SetFileAttrib_ws ((int (*)(const WSHDR *, uint8_t, uint32_t *))(ADDR_SetFileAttrib_ws))


__attribute__((always_inline))
inline int GetAttrIcon(int flag) {
    return (flag) ? CHECKED : UNCHECKED;
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetCursor")))
void SetCursor(WSHDR *ws, int cursor, int switch_attribute) {
    int p = _wstrchr(ws, 1, UTF16_BG_INVERTION);
    if (p != -1) {
        _wsRemoveChars(ws, p, 1);
    }
    p = _wstrchr(ws, 1, UTF16_NO_INVERTION);
    if (p != -1) {
        _wsRemoveChars(ws, p, 1);
    }

    int p1, p2;
    if (cursor == 0) {
        p1 = 1;
        p2 = p1 + 4;
    } else {
        p1 = (cursor == 1) ? 5 : 8;
        p2 = p1 + 3;
    }
    _wsInsertChar(ws, UTF16_BG_INVERTION, p1);
    _wsInsertChar(ws, UTF16_NO_INVERTION, p2);
    if (switch_attribute) {
        int id = 1 + p2;
        ws->wsbody[id] = (ws->wsbody[id] == UNCHECKED) ? CHECKED : UNCHECKED;
    }
}

#define TViewAddElement ((void (*)(WSHDR *, int, const WSHDR *))(ADDR_TViewAddElement))
#define TViewAddElementWithColon ((void (*)(WSHDR *, int, const WSHDR *))(ADDR_TViewAddElementWithColon))

__attribute__((target("thumb")))
__attribute__((section(".text.Init_Hook")))
void Init_Hook(WSHDR *text, int lgp_id, WSHDR *path) {
    uint32_t err;
    if (_isdir_ws(path, &err)) {
        _wsAppendChar(path, '\\');
    }
    TViewAddElement(text, lgp_id, path);

    uint8_t attr;
    if (_GetFileAttrib_ws(path, &attr, &err)) {
        WSHDR attr_text, attr_data;
        uint16_t wsbody_attr_text[32], wsbody_attr_data[32];
        _CreateLocalWS(&attr_text, wsbody_attr_text, 32);
        _CreateLocalWS(&attr_data, wsbody_attr_data, 32);
        _wsprintf(&attr_data, "RO:%cH:%cS:%c",
        GetAttrIcon(attr & FA_READONLY), GetAttrIcon(attr & FA_HIDDEN), GetAttrIcon(attr & FA_SYSTEM));
        SetCursor(&attr_data, 0, 0);
        TViewAddElementWithColon(&attr_text, 0x78F, &attr_data);
        _wstrcat(text, &attr_text);
    }
}

__attribute__((always_inline))
inline uint8_t GetAttr(const WSHDR *ws, int cursor) {
    int offset = 0;
    uint8_t attr = 0;
    if (cursor == 0) {
        offset = 2;
    }
    attr |= (_wsCharAt(ws, 4 + offset) == CHECKED) ? FA_READONLY : 0;
    if (cursor == 1) {
        offset = 2;
    }
    attr |= (_wsCharAt(ws, 7 + offset) == CHECKED) ? FA_HIDDEN : 0;
    if (cursor == 2) {
        offset = 2;
    }
    attr |= (_wsCharAt(ws, 10 + offset) == CHECKED) ? FA_SYSTEM : 0;
    return attr;
}

#define cursor gui->unk2
#define TViewClear ((WSHDR *(*)(void *, void *))(ADDR_TViewClear))

__attribute__((target("thumb")))
__attribute__((section(".text.Update")))
void Update(GUI *gui, int switch_attribute) {
    WSHDR *text = TViewClear((void*)gui, (uint32_t*)ADDR_mfree);

    WSHDR search_s;
    uint16_t wsbody_search_s[16];
    _CreateLocalWS(&search_s, wsbody_search_s, 16);
    _wsprintf(&search_s, "%c%c", 0xE01E, 0xE015);
    int p_s = _wstrwstr(text, &search_s, 1);
    if (p_s == -1) {
        goto EXIT;
    }
    p_s += 2;

    WSHDR search_e;
    uint16_t wsbody_search_e[16];
    _CreateLocalWS(&search_e, wsbody_search_e, 16);
    _wsprintf(&search_e, "%c%c", 0xE012, 0xE01E);
    int p_e = _wstrwstr(text, &search_e, p_s);
    if (p_e == -1) {
        goto EXIT;
    }
    p_e -= 1;

    WSHDR path;
    uint16_t wsbody_path[128];
    _CreateLocalWS(&path, wsbody_path, 128);
    _wstrcpybypos(&path, text, p_s, p_e - p_s);
    int a_s = _wstrwstr(text, &search_s, p_e + 2);
    if (a_s == -1) {
        goto EXIT;
    }
    a_s += 2;
    int a_e = _wstrwstr(text, &search_e, a_s);
    if (a_e == -1) {
        goto EXIT;
    }
    a_e -= 1;

    WSHDR attr;
    uint16_t wsbody_attr[32];
    _CreateLocalWS(&attr, wsbody_attr, 32);
    _wstrcpybypos(&attr, text, a_s, a_e - a_s);
    SetCursor(&attr, cursor, switch_attribute);
    _wstrreplace(text, &attr, a_s);
    if (switch_attribute) {
        uint32_t err;
        _SetFileAttrib_ws(&path, GetAttr(&attr, cursor), &err);
    }
    EXIT:
    _TViewSetText((void*)gui, text, (uint32_t*)ADDR_malloc, (uint32_t*)ADDR_mfree);
    _RefreshGUI();
}

__attribute__((target("thumb")))
__attribute__((section(".text.OnKey_Hook")))
int OnKey_Hook(int cmd) {
    if (!cmd) {
        register GUI *gui asm ("r4");
        register GUI_MSG *msg asm("r5");
        int submess = msg->gbsmsg->submess;
        if (msg->gbsmsg->msg == KEY_DOWN || msg->gbsmsg->msg == LONG_PRESS) {
            if (submess == LEFT_BUTTON) {
                if (cursor == 0) {
                    cursor = 2;
                } else {
                    cursor--;
                }
                Update(gui, 0);
            } else if (submess == RIGHT_BUTTON) {
                cursor++;
                if (cursor > 2) {
                    cursor = 0;
                }
                Update(gui, 0);
            } else if (submess == ENTER_BUTTON) {
                Update(gui, 1);
            }
        }
        return 0;
    } else {
        _GeneralFuncF1(cmd);
        return -1;
    }
}
