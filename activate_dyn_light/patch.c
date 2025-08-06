#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _SLI_SetState ((void (*)(uint8_t))(ADDR_SLI_SetState))
#define _SetVibration ((void (*)(uint8_t))(ADDR_SetVibration))
#define _GetVibraStatus ((int (*)())(ADDR_GetVibraStatus))

#define SetVLType ((void (*)(void *, int))(ADDR_SetVLType))
#define StopVibration ((int (*)())(ADDR_StopVibration))
#define IsVibraLocked ((int (*)())(ADDR_IsVibraLocked))
#define GetDynlightStatus ((int (*)())(ADDR_GetDynlightStatus))

__attribute__((target("thumb")))
__attribute__((section(".text.SetVLType_Hook")))
void SetVLType_Hook(void *r0, int type) { // always set vibration
    if (type == 1 || type == 3) {
        type = 2;
    }
    SetVLType(r0, type);
}

__attribute__((target("thumb")))
__attribute__((section(".text.SetVibration_Hook")))
void SetVibration_Hook(uint8_t level) {
    if (GetDynlightStatus()) {
        _SLI_SetState(level >= 0x32);
    }
    if (_GetVibraStatus() && !IsVibraLocked()) {
        _SetVibration(level);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.StopVibration_Hook")))
void StopVibration_Hook() {
    if (GetDynlightStatus()) {
        _SLI_SetState(0);
    }
    StopVibration();
}
