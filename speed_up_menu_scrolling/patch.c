#include "patch.h"

#ifdef E71_45
    #include "E71_45.h"
#endif


#define _DrawMenuItemScrollText ((void (*)(MENU_ITEM_GUI *))(ADDR_DrawMenuItemScrollString))
#define _GrabBGFromLCD ((void (*)(void *, RECT *, void *, void *))(ADDR_GrabBGFromLCD))
#define FreeIMGHDR ((void (*)(void *, void *))(ADDR_FreeIMGHDR))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawMenuItemScrollText")))
void DrawMenuItemScrollText(MENU_ITEM_GUI *menu_item) {
    if (menu_item->is_active_item || menu_item->scroll_text_gui.params->unk_flag_minus1 != -1) {
        _DrawMenuItemScrollText(menu_item);
    } else {
        const int prev_scroll_mode = menu_item->scroll_text_gui.scroll_mode;
        menu_item->scroll_text_gui.scroll_mode = 8;
        _DrawMenuItemScrollText(menu_item);
        menu_item->scroll_text_gui.scroll_mode = prev_scroll_mode;
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.GrabBGFromLCD")))
void GrabBGFromLCD(SCROLL_TEXT_GUI *scroll_text, RECT *rc, void *malloc_addr, void *mfree_addr) {
    if (scroll_text->scroll_mode != 8) {
        _GrabBGFromLCD(&scroll_text->params->bg, rc, malloc_addr, mfree_addr);
    } else {
        FreeIMGHDR(&scroll_text->params->bg, mfree_addr);
    }
}
