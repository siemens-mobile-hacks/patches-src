#include <swilib.h>
#include "csm.h"
#include "functions.h"

#define MergeIMGHDR ((void (*)(IMGHDR *src, IMGHDR *dest))(ADDR_MergeIMGHDR))
#define MergeIcons ((void (*)(void *, void *))(ADDR_MergeIcons))

__attribute__((target("thumb")))
__attribute__((section(".text.MergeIcons_Hook")))
void MergeIcons_Hook(NATIVE_EXPLORER_CSM *csm, void *r1, IMGHDR *src) {
    register int r3 asm("r3");
    if (r3 != 3) {
        if (csm->mark_mode) {
            src = _GetPITaddr(1336);
        }
        IMGHDR *dest = (IMGHDR*)((char*)r1 + 8);
        MergeIMGHDR(src, dest);
    }
    MergeIcons(csm, r1);
}

__attribute__((target("thumb")))
__attribute__((section(".text.IsAllowThumbnail")))
int IsAllowThumbnail(void *r0) {
    register NATIVE_EXPLORER_CSM *csm asm("r6");
    return *(int*)(r0 + 0x1A8) && !csm->disable_thumbnail && !csm->mark_mode;
}

__attribute__((section(".text.Set2ndTabPath")))
void Set2ndTabPath(void *r0, WSHDR *ws) {
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

#define LGP_ID_EXTRA_HEADER 0x7FFFC092

#define ClearLgp     ((void (*)(int))(ADDR_ClearLgp))
#define SetLgpText ((void (*)(int, const WSHDR *))(ADDR_SetLgpText))
#define SetHeaderExtraLgp ((void (*)(void *, int, void *, void *))(ADDR_SetHeaderExtraLgp))

inline uint8_t GetFileAttr(uint8_t file_attr, uint8_t attr, uint8_t c) {
    return (file_attr & attr) ? c : '-';
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetHeaderExtra_Hook")))
void SetHeaderExtra_Hook(int cepid, int msg, int r2, int item_n, void *tab_gui) {
    _GBS_SendMessage(cepid, msg, r2, item_n, tab_gui);

    uint8_t attr = 0;
    if (_GetMenuItemCount(tab_gui)) {
        WSHDR ws_path;
        unsigned int err;
        uint16_t wsbody_path[128];
        register void *gui asm("r4");

        NATIVE_EXPLORER_CSM *csm = GetCSM(gui);

        _CreateLocalWS(&ws_path, wsbody_path, 128);
        GetItemPath(csm, item_n, &ws_path);
        _GetFileAttrib_ws(&ws_path, &attr, &err);
        WSHDR ws;
        uint16_t wsbody[16];
        _CreateLocalWS(&ws, wsbody, 16);
        _wsprintf(&ws, "[%c%c%c%c]",
                  GetFileAttr(attr, FA_READONLY, 'r'), GetFileAttr(attr, FA_HIDDEN, 'h'),
                  GetFileAttr(attr, FA_SYSTEM, 's'), GetFileAttr(attr, FA_DIRECTORY, 'd'));
        SetLgpText(LGP_ID_EXTRA_HEADER, &ws);
        SetHeaderExtraLgp(_GetHeaderPointer(tab_gui), LGP_ID_EXTRA_HEADER, ADDR_malloc, ADDR_mfree);
        ClearLgp(LGP_ID_EXTRA_HEADER);
    }
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

/*
 * Фикс переименовывания файлов по хоткею.
 */

#define ShowRename ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_ShowRename))

__attribute__((target("thumb")))
__attribute__((section(".text.FixRenameFile_Hook")))
void FixRenameFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        ShowRename(csm, item_n);
    }
}

/*
 * Фикс копирывания файлов по хоткею.
 */

#define CopyFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_CopyFile))

__attribute__((target("thumb")))
__attribute__((section(".text.FixCopyFile_Hook")))
void FixCopyFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        CopyFile(csm, item_n);
    }
}

/*
 * Фикс перемещения файлов по хоткею.
 */

#define MoveFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_MoveFile))

__attribute__((target("thumb")))
__attribute__((section(".text.FixMoveFile_Hook")))
void FixMoveFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        MoveFile(csm, item_n);
    }
}

/*
 * Фикс удаления файлов по хоткею.
 */

#define DeleteFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_DeleteFile))

__attribute__((target("thumb")))
__attribute__((section(".text.FixDeleteFile_Hook")))
void FixDeleteFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        DeleteFile(csm, item_n);
    }
}

/*
 * Фикс передачи файлов по хоткею.
 */

#define SendFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_SendFile))

__attribute__((target("thumb")))
__attribute__((section(".text.FixSendFile_Hook")))
void FixSendFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        SendFile(csm, item_n);
    }
}

#define ShowSetAs ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_ShowSetAs))

__attribute__((target("thumb")))
__attribute__((section(".text.FixSetAsFile_Hook")))
void FixSetAsFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        ShowSetAs(csm, item_n);
    }
}

/*
 * Фикс вставки файлов по хоткею.
 */

#define Paste_Unknown_1 ((void (*)(NATIVE_EXPLORER_CSM *))(ADDR_Paste_Unknown_1))
#define Paste_Unknown_2 ((void (*)(NATIVE_EXPLORER_CSM *csm, WSHDR *ws, int zero))(ADDR_Paste_Unknown_2))

__attribute__((target("thumb")))
__attribute__((section(".text.FixPaste_Hook")))
void FixPaste_Hook(NATIVE_EXPLORER_CSM *csm, int item_n, WSHDR *ws) {
    GetItemPath(csm, item_n, ws);
    if (!_wstrlen(ws)) {
        GetCurrentDir(csm, ws);
    }
    if (IsAllowPaste(csm, ws)) {
        Paste_Unknown_1(csm);
        Paste_Unknown_2(csm, ws, 0);
    }
}

/*
 * При копировании|перемещении нескольких папок некоторые элементы списка не отключались.
 */

#define DisableItem_Unknown ((int (*)(NATIVE_EXPLORER_CSM *csm, WSHDR *ws))(ADDR_DisableItem_Unknown))

__attribute__((target("thumb")))
__attribute__((section(".text.FixDisableItem_Hook")))
int FixDisableItem_Hook(NATIVE_EXPLORER_CSM *csm, WSHDR *ws) {
    return !IsAllowPaste(csm, ws) ? 0 : DisableItem_Unknown(csm, ws);
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
 * Отключаем "ненужные" пункты меню.
 */

__attribute__((target("thumb")))
__attribute__((section(".text.HideMenuItems_Hook")))
void HideMenuItems_Hook(int *hide_list) {
    int count = hide_list[0] + 1;
    hide_list[count++] = 0x16; // Manage licence
    hide_list[count++] = 0x17; // Format card
    hide_list[count  ] = 0x13; // Search
    hide_list[0] = count;
}
