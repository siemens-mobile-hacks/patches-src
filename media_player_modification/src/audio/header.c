#include <swilib.h>
#include "../functions.h"

#define EnableMenu ((void (*)(MP_GUI *gui, int flag))(ADDR_EnableMenu))
#define GetInfoLineText ((void (*)(MP_GUI *, WSHDR *))(ADDR_GetInfoLineText))

__attribute__((target("thumb")))
__attribute__((section(".text.SetHeaderToListView")))
void SetHeaderToListView(MP_GUI *gui) {
    WSHDR *ws = _AllocWS(64);
    void *header = _GetDataOfItemByID(gui, 2);
    GetInfoLineText(gui, ws);
    _SetHeaderScrollText(header, ws, ADDR_malloc, ADDR_mfree);
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetHeaderToAnimationView")))
void SetHeaderToAnimationView(MP_GUI *gui) {
    WSHDR *ws = _AllocWS(64);
    void *header = _GetDataOfItemByID(gui, 2);
    _GetLangMesIntoWS(0xD07, ws);
    _SetHeaderScrollText(header, ws, ADDR_malloc, ADDR_mfree);
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetHeaderScrollText_Hook")))
void SetHeaderScrollText_Hook(MP_GUI *gui, const WSHDR *title, const void *malloc_fn, const void *mfree_fn) {
    if (gui->media_type != MP_MEDIA_TYPE_AUDIO) {
        void *header = _GetDataOfItemByID(gui, 2);
        _SetHeaderScrollText(header, title, (void *)malloc_fn, (void *)mfree_fn);
    }
}
