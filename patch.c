#include <swilib/obs.h>
#include <swilib/image.h>

#ifdef NEWSGOLD
    #ifdef ELKA
        #ifdef E71_45
            #include "E71_45.h"
        #endif
    #else
    #endif
#endif


#define GetThemeCacheIdByUnk ((int (*)(unsigned int))(0xa073ccec))
#define _Obs_SetInput_File ((int (*)(HObj, int *r8, WSHDR *path))(ADDR_Obs_SetInput_File))
#define _Obs_SetTransparent ((int (*)(HObj, int))(ADDR_Obs_SetTransparent))

__attribute__((section(".text.Entry")))
int Entry(HObj hobj, int *r8, WSHDR *path) {
    int theme_cache_id = GetThemeCacheIdByUnk(*(char*)(*r8 + sizeof(int)));
    int res = _Obs_SetInput_File(hobj, 0, path);
    if (res == 0) {
        if (theme_cache_id == SELECTION_1_LINE ||
            theme_cache_id == SELECTION_2_LINE ||
            theme_cache_id == SELECTION_3_LINE ||
            theme_cache_id == TAB_SELECTED ||
            theme_cache_id == POPUP_SEARCH_LINE ||
            theme_cache_id == POPUP_QUICK_ACCESS_FIELD ) {
            _Obs_SetTransparent(hobj, 5);
        }
    }
    return res;
}
