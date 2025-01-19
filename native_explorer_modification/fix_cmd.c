#include "csm.h"
#include "functions.h"

#define CopyFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_CopyFile))
#define MoveFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_MoveFile))
#define SendFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_SendFile))
#define ShowSort ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_ShowSort))
#define ShowSetAs ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_ShowSetAs))
#define ShowRename ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_ShowRename))
#define DeleteFile ((void (*)(NATIVE_EXPLORER_CSM *, int))(ADDR_DeleteFile))

extern int IsAllowPaste(NATIVE_EXPLORER_CSM *csm, WSHDR *ws);

__attribute__((target("thumb")))
__attribute__((section(".text.FixCopyFile_Hook")))
void FixCopyFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        CopyFile(csm, item_n);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixMoveFile_Hook")))
void FixMoveFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        MoveFile(csm, item_n);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixSendFile_Hook")))
void FixSendFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm) && !csm->mark_mode) {
        WSHDR path;
        uint16_t wsbody_path[128];
        _CreateLocalWS(&path, wsbody_path, 128);
        GetItemPath(csm, item_n, &path);
        if (!_isdir_ws(&path)) {
            SendFile(csm, item_n);
        }
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixSortFiles_Hook")))
void FixSortFiles_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        ShowSort(csm, item_n);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixSetAsFile_Hook")))
void FixSetAsFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        WSHDR path;
        uint16_t wsbody_path[128];
        _CreateLocalWS(&path, wsbody_path, 128);
        GetItemPath(csm, item_n, &path);
        if (!_isdir_ws(&path)) {
            ShowSetAs(csm, item_n);
        }
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixRenameFile_Hook")))
void FixRenameFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        ShowRename(csm, item_n);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixDeleteFile_Hook")))
void FixDeleteFile_Hook(NATIVE_EXPLORER_CSM *csm, int item_n) {
    if (GetTabItemsCount(csm)) {
        DeleteFile(csm, item_n);
    }
}

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
