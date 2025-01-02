#ifdef NEWSGOLD
    #ifdef ELKA
        #ifdef E71_45
            #include "E71_45.h"
        #endif
    #endif
#endif

#define _GetAkku ((int (*)(int, int))(ADDR_GetAkku))
#define _RebootPhone ((void(*)())(ADDR_RebootPhone))
#define DrawSimpleBar ((void(*)(int))(ADDR_DrawSimpleBar))
#define StartTimer ((void(*)())(ADDR_StartTimer))

__attribute__((target("thumb")))
__attribute__((section(".text.DrawSimpleBarHook")))
void DrawSimpleBarHook(const int r0) {
    if (_GetAkku(0, 3) >= 3600) {
        _RebootPhone();
    } else {
        DrawSimpleBar(r0);
        StartTimer();
    }
}
