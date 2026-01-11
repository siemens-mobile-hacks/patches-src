#include <swilib.h>
#include "csm.h"
#include "functions.h"

#define SetItemsText ((void (*)(NATIVE_EXPLORER_CSM *, int, int *, WSHDR *, WSHDR *))(ADDR_SetItemsText))

inline uint8_t GetFileAttr(uint8_t file_attr, uint8_t attr, uint8_t c) {
    return (file_attr & attr) ? c : '-';
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetItemsText_Hook")))
void SetItemsText_Hook(NATIVE_EXPLORER_CSM *csm, int item_n, int *icon, WSHDR *ws1, WSHDR *ws2) {
    SetItemsText(csm, item_n, icon, ws1, ws2);

    WSHDR ws_path;
    uint16_t wsbody_path[128];
    _CreateLocalWS(&ws_path, wsbody_path, 127);
    GetItemPath(csm, item_n, &ws_path);

    uint32_t err;
    uint8_t attr = 0;
    _GetFileAttrib_ws(&ws_path, &attr, &err);

    WSHDR ws;
    uint16_t wsbody[16];
    _CreateLocalWS(&ws, wsbody, 16);
    _wsprintf(&ws, "[%c%c%c%c]",
        GetFileAttr(attr, FA_READONLY, 'r'), GetFileAttr(attr, FA_HIDDEN, 'h'),
        GetFileAttr(attr, FA_SYSTEM, 's'), GetFileAttr(attr, FA_DIRECTORY, 'd'));
    _wsAppendChar(ws2, UTF16_ALIGN_RIGHT);
    _wstrcat(ws2, &ws);
    _wsAppendChar(ws2, UTF16_ALIGN_NONE);
}

__attribute__((target("thumb")))
__attribute__((section(".text.IsAllowPaste")))
int IsAllowPaste(NATIVE_EXPLORER_CSM *csm, WSHDR *ws) {
    WSHDR path;
    uint16_t wsbody_path[128];
    _CreateLocalWS(&path, wsbody_path, 128);
    NATIVE_EXPLORER_CM_LIST *p = csm->cm_list;
    while (p) {
        if (_BuildPath(&path, p->file_name, p->dir)) {
            if (_wstrcmp(&path, ws) == 0) {
                return 0;
            }
        }
        p = p->next;
    }
    return 1;
}


#define MergeIcons ((void (*)(void *, void *))(ADDR_MergeIcons))
#define MergeIMGHDR ((void (*)(IMGHDR *src, IMGHDR *dest))(ADDR_MergeIMGHDR))
#define IsDirectory ((int (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_IsDirectory))

__attribute__((target("thumb")))
__attribute__((section(".text.MergeIcons_Hook")))
void MergeIcons_Hook(NATIVE_EXPLORER_CSM *csm, void *item, IMGHDR *src) {
    register int r3 asm ("r3");
    if (csm->mark_mode) {
        const int item_n = *((uint8_t*)item + 4);
        if (csm->mode == NATIVE_EXPLORER_MODE_DEFAULT || !IsDirectory(csm, item_n)) {
            src = _GetPITaddr(1336);
        }
        goto MERGE;
    }
    if (r3 != 3) {
        MERGE:
            IMGHDR *dest = (IMGHDR*)((uint8_t*)item + 8);
            MergeIMGHDR(src, dest);
    }
    MergeIcons(csm, item);
}

__attribute__((target("thumb")))
__attribute__((section(".text.IsAllowThumbnail")))
int IsAllowThumbnail(void *r0) {
    register NATIVE_EXPLORER_CSM *csm asm("r6");
    return *(int*)(r0 + 0x1A8) && !csm->disable_thumbnail && !csm->mark_mode;
}

/*
 * Правильная инициализация количества вкладок в зависимости от доступности MMC.
 */
__attribute__((target("thumb")))
__attribute__((section(".text.GetTotalDrives_Hook")))
int GetTotalDrives_Hook() {
    uint32_t err;
    return (_GetTotalFlexSpace(4, &err) ? 4 : 3);
}

/*
 * Фикс инициализация второй вкладки.
 */
__attribute__((section(".text.SetSecondTabPath")))
void SetSecondTabPath(int dir_id, WSHDR *ws) {
    _wsprintf(ws, "1:\\");
}

/*
 * Неправильная инициализация начальной вкладки при выборе файла. Проявляется при отображении всех дисков.
 */

__attribute__((target("thumb")))
__attribute__((section(".text.FixInitTab_Hook")))
int FixInitTab_Hook(int r0, const WSHDR *ws) {
    int id = ws->wsbody[1] & 0xFF - '0';
    if (id >= 4) {
        id = 3;
    }
    return id;
}

/*
 * При копировании|перемещении в некоторых режимах не менялся правый софткей в корне.
 */

#define IsRootDir ((int (*)(NATIVE_EXPLORER_CSM *csm))(ADDR_IsRootDir))

__attribute__((target("thumb")))
__attribute__((section(".text.FixSoftkeys_Hook")))
int FixSoftkeys_Hook(NATIVE_EXPLORER_CSM *csm) {
    if (_wstrlen(csm->root_dir)) {
        WSHDR current_dir;
        uint16_t wsbody_current_dir[128];
        _CreateLocalWS(&current_dir, wsbody_current_dir, 128);
        GetCurrentDir(csm, &current_dir);
        return _wstrcmp(csm->root_dir, &current_dir) == 0;
    }
    return IsRootDir(csm);
}

/*
 * Отключение "ненужных" пунктов меню.
 */

__attribute__((target("thumb")))
__attribute__((section(".text.HideMenuItems_Hook")))
void HideMenuItems_Hook(NATIVE_EXPLORER_CSM *csm, int *hide_list) {
    int count = hide_list[0] + 1;
    if (csm->mode == NATIVE_EXPLORER_MODE_DEFAULT) {
        if (csm->mark_mode) {
            hide_list[count++] = 0x02; // Send
        } else {
            WSHDR path;
            uint16_t wsbody_path[128];
            register int item_n asm("r5");
            _CreateLocalWS(&path, wsbody_path, 128);
            GetItemPath(csm, item_n, &path);

            uint8_t attr;
            uint32_t err;
            _GetFileAttrib_ws(&path, &attr, &err);
            if (attr & FA_READONLY || attr & FA_SYSTEM) {
                hide_list[count++] = 0x08; // Delete
            }
        }
    }
    // hide_list[count++] = 0x13; // Search
    hide_list[count++] = 0x16; // Manage licence
    hide_list[count  ] = 0x17; // Format card
    hide_list[0] = count;
}

/*
 * Фикс установки атрибутов папок при их копировании или перемещении.
 */

#define CreateDir ((int (*)(const WSHDR *ws, const WSHDR *unk))(ADDR_CreateDir))

__attribute__((target("thumb")))
__attribute__((section(".text.FixCopyDirsAttributes_Hook")))
int FixCopyDirsAttributes_Hook(const WSHDR *dest_dir, const WSHDR *unk) {
    int result = CreateDir(dest_dir, unk);
    if (result == 0) {
        uint8_t attr;
        uint32_t err;
        register const WSHDR *src_dir asm ("r8");
        if (_GetFileAttrib_ws(src_dir, &attr, &err)) {
            _SetFileAttrib_ws(dest_dir, attr, &err);
        }
    }
    return result;
}
