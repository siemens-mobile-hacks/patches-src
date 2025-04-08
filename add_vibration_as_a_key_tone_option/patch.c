#include <swilib.h>
#include <swilib/patch.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif


#define _wsprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wsprintf))
#define _PlayVibra ((void (*)(int, int, int))(ADDR_PlayVibra))
#define _CreateLocalWS ((void (*)(WSHDR *, uint16_t *, int))(ADDR_CreateLocalWS))
#define _GetLangMesIntoWS ((void (*)(int, WSHDR *))(ADDR_GetLangMesIntoWS))

#define ClearLgp     ((void (*)(int))(ADDR_ClearLgp))
#define SetLgpTextWS ((void (*)(int, const WSHDR *))(ADDR_SetLgpTextWS))


__attribute__((target("thumb")))
__attribute__((section(".text.AddLgpMessage_Hook")))
void AddLgpMessage_Hook(int lgp_id, WSHDR *dest) {
    WSHDR ws;
    uint16_t wsbody[64];
    _CreateLocalWS(&ws, wsbody, 64);
    _wsprintf(&ws, "%t + %t", 0x17B, 0x1D2);
    SetLgpTextWS(0x7FFFD000, &ws);
    _GetLangMesIntoWS(lgp_id, dest);
}

#define GetKeyTone ((int (*)())(ADDR_GetKeyTone))
#define GetVibraState ((int (*)())(ADDR_GetVibraState))

__attribute__((target("thumb")))
__attribute__((section(".text.PlayKeySound_Hook")))
int PlayKeySound_Hook(void) {
    int key_tone = GetKeyTone();
    if (key_tone == 3 || key_tone == 4) { // vibration
        _PlayVibra(50, 5, 1);
        return key_tone - 3;
    }
    return key_tone;
}
