#include "patch.h"

#ifdef E71_45
    #include "E71_45.h"
#endif
#ifdef S75_52
    #include "S75_52.h"
#endif

#define GrabBGFromLCD ((void (*)(void *, RECT *, void *, void *))(ADDR_GrabBGFromLCD))
#define DrawMenuItemScrollText ((void (*)(MENU_ITEM_GUI *))(ADDR_DrawMenuItemScrollString))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawMenuItemScrollText_Hook")))
void DrawMenuItemScrollText_Hook(MENU_ITEM_GUI *menu_item) {
    if (menu_item->is_active_item || menu_item->scroll_text_gui.params->unk_flag_minus1 != -1) {
        DrawMenuItemScrollText(menu_item);
    } else {
        const int prev_scroll_mode = menu_item->scroll_text_gui.scroll_mode;
        menu_item->scroll_text_gui.scroll_mode = 8;
        DrawMenuItemScrollText(menu_item);
        menu_item->scroll_text_gui.scroll_mode = prev_scroll_mode;
    }
}

#define FreeIMGHDR ((void (*)(void *, void *))(ADDR_FreeIMGHDR))

__attribute__((target("thumb")))
__attribute__((section(".text.GrabBGFromLCD_Hook")))
void GrabBGFromLCD_Hook(SCROLL_TEXT_GUI *scroll_text, RECT *rc, void *malloc_addr, void *mfree_addr) {
    IMGHDR **bg = &(scroll_text->params->bg);
    if (scroll_text->scroll_mode != 8) {
        GrabBGFromLCD(bg, rc, malloc_addr, mfree_addr);
    } else {
        FreeIMGHDR(bg, mfree_addr);
    }
}
