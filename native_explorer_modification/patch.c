#include <swilib.h>
#include "csm.h"
#include "functions.h"

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
    if (csm->mark_mode) {
        hide_list[count++] = 0x02; // Send
    }
    hide_list[count++] = 0x13; // Search
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

    uint8_t attr;
    uint32_t err;
    register const WSHDR *source_dir asm ("r8");
    if (_GetFileAttrib_ws(source_dir, &attr, &err)) {
        _SetFileAttrib_ws(dest_dir, attr, &err);
    }

    return result;
}
