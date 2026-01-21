#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _IsAnyOfAccessoriesConnected ((int (*)(uint8_t *, uint8_t))(ADDR_IsAnyOfAccessoriesConnected))

#define IsDisabledUSBCharging() !((*ADDR_RamAccessoriesFlags) & (1U << 21))

#define Set ((int (*)(void *, int, int))(ADDR_Set))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_1")))
int Hook_1(void *r0, int r1, int r2) {
    if (IsDisabledUSBCharging()) {
        if (_IsAnyOfAccessoriesConnected(ACCESSORIES, 6)) {
            return 0;
        }
    }
    return Set(r0, r1, r2);
}

#define GetState ((int (*)(void *))(ADDR_GetState))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_2")))
int Hook_2(void *r0) {
    int state = GetState(r0);
    if (IsDisabledUSBCharging()) {
        if (state == 1) {
            state = 0;
        } else if (state == 2) {
            if (_IsAnyOfAccessoriesConnected(ACCESSORIES, 6)) {
                state = 0;
            }
        }
    }
    return state;
}
