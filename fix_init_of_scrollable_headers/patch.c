#ifdef E71_45
    #include "E71_45.h"
#endif
#ifdef S75_52
    #include "S75_52.h"
#endif

#define _SetScrollType ((void (*)(void *, int))(ADDR_SetScrollType))
#define _SetScrollSpeed ((void (*)(void *, int, int))(ADDR_SetScrollSpeed))

__attribute__((target("thumb")))
__attribute__((section(".text.SetScrollType")))
void SetScrollType(void *scroll, int type) {
    _SetScrollType(scroll, type);
    _SetScrollSpeed(scroll, 0x212, 0x2A);
}
