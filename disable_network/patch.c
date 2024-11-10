#include <swilib.h>

#ifdef SGOLD
    #ifdef S65_58
        #include "S65_58.h"
    #endif
#endif

#define _GBS_SendMessage ((void (*)(int cepid_to, int msg, ...))(ADDR_GBS_SendMessage))
#define _DisableNetwork ((void (*)())(ADDR_DisableNetwork))
#define GetUnk ((int (*)())(ADDR_GetUnk))

#define IsSimPresent() (*ADDR_RamIsSimPresent)

__attribute__((section(".text.DisableNetwork")))
void DisableNetwork(void) {
    _GBS_SendMessage(0x4058, 7, 0, 0, 0);
}

__attribute__((section(".text.EnableNetwork")))
void EnableNetwork(void) {
    _GBS_SendMessage(0x4058, 8, 0, 0, 0);
}

__attribute__((target("thumb")))
__attribute__((section(".text.AutoDisableNetwork")))
int AutoDisableNetwork() {
    if (!IsSimPresent()) {
        _DisableNetwork();
    }
    return GetUnk();
}
