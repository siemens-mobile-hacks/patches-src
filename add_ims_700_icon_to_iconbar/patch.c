#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef S75_52
        #include "S75_52.h"
    #endif
#endif

#define _AddIconToIconBar ((void (*)(int, short *))(ADDR_AddIconToIconBar))
#define _IsAnyOfAccessoriesConnected ((int (*)(const enum Accessory *accessory_ids, uint8_t))(ADDR_IsAnyOfAccessoriesConnected))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
void Hook(int flag, short *num) {
    if (flag == 5) {
        _AddIconToIconBar(1, num);
    }
    if (_IsAnyOfAccessoriesConnected((enum Accessory[]){ACC_MOBILE_MUSIC_SET}, 1)) {
        _AddIconToIconBar(624, num);
    }
}
