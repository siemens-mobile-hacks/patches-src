#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #ifdef EL71_45
        #include "EL71_45.h"
    #endif
    #ifdef S75_52
        #include "S75_52.h"
    #endif
#endif

#define _Obs_SetInput_File ((int (*)(HObj, int *r8, WSHDR *path))(ADDR_Obs_SetInput_File))
#define _Obs_SetTransparent ((int (*)(HObj, int))(ADDR_Obs_SetTransparent))

#define GetThemeCacheId ((int (*)(uint32_t))(ADDR_GetThemeCacheId))

#ifdef THUMB_VARIANT
__attribute__((target("thumb")))
#endif
__attribute__((section(".text.HookThemeImageLoading")))
int HookThemeImageLoading(HObj hobj, void *r1, WSHDR *path) {
    int theme_cache_id = GetThemeCacheId(*(uint16_t*)(*(uint32_t*)r1 + 4));
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
