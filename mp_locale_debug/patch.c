#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define PATCH_ID 0x3331

#define _GetBuffer ((void *(*)(int))(ADDR_GetBuffer))

#define GetLocaleFlag ((int (*)())(ADDR_GetLocaleFlag))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
int Hook() {
    void *buffer = _GetBuffer(PATCH_ID);
    return (buffer) ? 1 : GetLocaleFlag();
}
