#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif

#define _SetHeaderIcon ((void (*)(void *, int *, void *, void *))(ADDR_SetHeaderIcon))
#define _GetHeaderPointer ((void *(*)(void *))(ADDR_GetHeaderPointer))

#define CallOnCreateHandlers ((int (*)(void *content_gui, void *malloc_fn))(ADDR_CallOnCreateHandlers))

__attribute__((target("thumb")))
__attribute__((section(".text.CallOnCreateHandlers_Hook")))
void CallOnCreateHandlers_Hook(void *content_gui, void *malloc_fn) {
    register void *sp asm("sp");
    int *icons = *(int**)((uint8_t*)sp + 36);
    CallOnCreateHandlers(content_gui, malloc_fn);
    void *header = _GetHeaderPointer(content_gui);
    _SetHeaderIcon(header, &(icons[3]), ADDR_malloc, ADDR_mfree);
}
