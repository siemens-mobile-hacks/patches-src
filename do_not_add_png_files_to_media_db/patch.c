#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif


#define _GetExtUidByFileName_ws ((int (*)(const WSHDR *))(ADDR_GetExtUidByFileName_ws))
#define GetFileState ((int (*)(const WSHDR *))(ADDR_GetFileState))

__attribute__((section(".text.GetFileState_Hook")))
int GetFileState_Hook(const WSHDR *path) {
    if (_GetExtUidByFileName_ws(path) == 39) { // png
        return -1;
    }
    return GetFileState(path);
}
