#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #ifdef S75_52
        #include "S75_52.h"
    #endif
#endif

#define _GetAkku ((int (*)(int, int))(ADDR_GetAkku))
#define _RebootPhone ((void(*)())(ADDR_RebootPhone))

#define StartTimer ((void(*)())(ADDR_StartTimer))
#define DrawSimpleBar ((void(*)(int))(ADDR_DrawSimpleBar))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
void Hook(const int r0) {
    if (_GetAkku(0, 3) >= 3600) {
        _RebootPhone();
    } else {
        DrawSimpleBar(r0);
        StartTimer();
    }
}
