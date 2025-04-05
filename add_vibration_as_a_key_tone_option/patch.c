#include <swilib/patch.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define GetKeyTone ((int (*)())(ADDR_GetKeyTone))
#define GetVibraState ((int (*)())(ADDR_GetVibraState))

#define _PlayVibra ((void (*)(int, int, int))(ADDR_PlayVibra))

__attribute__((target("thumb")))
__attribute__((section(".text.PlayKeySound_Hook")))
int PlayKeySound_Hook(void) {
    int key_tone = GetKeyTone();
    if (key_tone == 3) { // vibration
        _PlayVibra(50, 5, 1);
    }
    return key_tone;
}
