#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif
#ifdef S75_52
    #include "S75_52.h"
#endif

#define _GeneralFuncF1 ((void (*)(int))(ADDR_GeneralFuncF1))

int GetNetworkState();
#define SimIsPresent() (*ADDR_RamSimIsPresent)
#define EnableNetwork ((void (*)())(ADDR_EnableNetwork))
#define DisableNetwork ((void (*)())(ADDR_DisableNetwork))
#define EnableMenuItem ((void (*)(void *, int, int flag, int refresh))(ADDR_EnableMenuItem))

__attribute__((target("thumb")))
__attribute__((section(".text.SwitchOfflineMode")))
void SwitchOfflineMode() {
    if (SimIsPresent()) {
        _GeneralFuncF1(1);
        if (GetNetworkState() == 2) {
            EnableNetwork();
        } else {
            DisableNetwork();
        }
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.ItemProc")))
void ItemProc(void *gui, int item_n) {
    if (item_n == 2) {
        if (!SimIsPresent()) {
            EnableMenuItem(gui, item_n, 0, 0);
        }
    }
}
