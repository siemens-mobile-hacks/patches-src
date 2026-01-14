#include <swilib.h>
#include "csm.h"
#include "functions.h"

#define LGP_ID_EXTRA_HEADER 0x7FFFC092

#define SetUserText ((void (*)(int, const char *))(ADDR_SetUserText))
#define ClearUserText ((void (*)(int))(ADDR_ClearUserText))
#define GetMarkedCount ((uint32_t (*)(NATIVE_EXPLORER_CSM *csm))(ADDR_GetMarkedCount))
#define SetHeaderExtraLgp ((void (*)(void *, int, const void *, const void *))(ADDR_SetHeaderExtraLgp))

__attribute__((target("thumb")))
__attribute__((section(".text.SetHeaderExtra_Hook")))
void SetHeaderExtra_Hook(int cepid, int msg, int r2, int item_n, void *tab_gui) {
    _GBS_SendMessage(cepid, msg, r2, item_n, tab_gui);

    register void *gui asm("r4");
    NATIVE_EXPLORER_CSM *csm = GetCSM(gui);
    int items = GetTabItemsCount(csm);
    if (items > 0) {
        const int marked_items = GetMarkedCount(csm);

        char *s = _malloc(8);
        if (!marked_items) {
            _sprintf(s, "%d", items);
        } else {
            _sprintf(s, "%d/%d", marked_items, items);
        }
        SetUserText(LGP_ID_EXTRA_HEADER, s);
        SetHeaderExtraLgp(_GetHeaderPointer(tab_gui), LGP_ID_EXTRA_HEADER, ADDR_malloc, ADDR_mfree);
        ClearUserText(LGP_ID_EXTRA_HEADER);
        _mfree(s);
    }
}
