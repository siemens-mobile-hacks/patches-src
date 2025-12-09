#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #ifdef S75_52
        #include "S75_52.h"
    #endif
    #define PutDateIntoWS ((void (*)(WSHDR *))(ADDR_PutDateIntoWS))
#else
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef C72_22
        #include "C72_22.h"
    #endif
    #define _GetDateTime ((void (*)(TDate *, TTime *))(ADDR_GetDateTime))
    #define _GetDate_ws ((void (*)(WSHDR *, const TDate *, int))(ADDR_GetDate_ws))
#endif

#define Insert ((void (*)(void *, const WSHDR *, int))(ADDR_Insert))

__attribute__((target("thumb")))
__attribute__((section(".text.Insert_Hook")))
void Insert_Hook(void *r0, WSHDR *ws, int pos) {
#ifdef NEWSGOLD
    PutDateIntoWS(ws);
#else
    TDate date;
    _GetDateTime(&date, NULL);
    _GetDate_ws(ws, &date, 0xF);
#endif
    Insert(r0, ws, pos);
}
