#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif

#define _SetWidgetRect ((void (*)(WIDGET *, int, int, int, int))(ADDR_SetWidgetRect))
#define _SetHeaderIcon ((void (*)(void *, int *, void *, void *))(ADDR_SetHeaderIcon))
#define _GetHeaderPointer ((void *(*)(void *))(ADDR_GetHeaderPointer))
#define _GetIMGHDRFromThemeCache ((IMGHDR *(*)(int))(ADDR_GetIMGHDRFromThemeCache))

#define GUI_IsFlagEnable ((int (*)(void *, int))(ADDR_GUI_IsFlagEnable))

__attribute__((__always_inline__))
inline void *GetTGUI(void *r0) {
    return (void*)(*(uint32_t*)(r0 + 100));
}

#define DrawTabs ((void (*)(void *, void *))(ADDR_DrawTabs))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawTabs_Hook")))
void DrawTabs_Hook(void *r0, void *r1) {
    void *tab_gui = GetTGUI(r0);
    if (GUI_IsFlagEnable(tab_gui, 0x10)) {
        DrawTabs(r0, r1);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.GetIMGHDRFromThemeCache_Hook")))
IMGHDR *GetIMGHDRFromThemeCache_Hook(void *tab_gui) {
    int theme_cache_id = (GUI_IsFlagEnable(tab_gui, 0x10)) ? BODY_TAB : BODY_STANDART;
    return _GetIMGHDRFromThemeCache(theme_cache_id);
}

#define OnFocus ((void (*)(void *, malloc_func_t, mfree_func_t))(ADDR_OnFocus))

__attribute__((target("thumb")))
__attribute__((section(".text.OnFocus_Hook")))
void OnFocus_Hook(void *tab_gui, malloc_func_t malloc_fn, mfree_func_t mfree_fn) {
    if (GUI_IsFlagEnable(tab_gui, 0x10)) {
        _SetWidgetRect(tab_gui, 0x12, 0x38, 0xCC, 0x20);
    }
    OnFocus(tab_gui, malloc_fn, mfree_fn);
}

#define CallOnCreateHandlers ((int (*)(void *content_gui, void *malloc_fn))(ADDR_CallOnCreateHandlers))

__attribute__((target("thumb")))
__attribute__((section(".text.CallOnCreateHandlers_Hook")))
void CallOnCreateHandlers_Hook(void *content_gui, void *malloc_fn) {
    register void *sp asm("sp");
    void *tab_gui = (void*)*((uint32_t*)sp + 7);
    if (!GUI_IsFlagEnable(tab_gui, 0x10)) {
        int *icons = *(int**)((uint8_t*)sp + 36);
        CallOnCreateHandlers(content_gui, malloc_fn);
        void *header = _GetHeaderPointer(content_gui);
        _SetHeaderIcon(header, &(icons[3]), ADDR_malloc, ADDR_mfree);
    }
}
