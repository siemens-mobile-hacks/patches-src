#include <swilib.h>
#include <sys/time.h>

#include "data.h"

#ifdef E71_45
    #include "E71_45.h"
#endif

#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _KeypressOn ((void (*)(int))(ADDR_KeypressOn))
#define _GBS_DelTimer ((void (*)(GBSTMR *))(ADDR_GBS_DelTimer))
#define _GBS_StartTimerProc ((void (*)(GBSTMR *tmr, long ms, GBSTMR_CALLBACK callback))(ADDR_GBS_StartTimerProc))

#define ClockManager_SetClkLevel ((int (*)(int client, int level))(ADDR_ClockManager_SetClkLevel))

__attribute__((target("thumb")))
__attribute__((section(".text.SetCPUClockLow")))
void SetCPUClockLow(GBSTMR *tmr) {
    _GBS_DelTimer(tmr);
    if (!(*RamPressedKey)) {
        const int client = (*data)->client;
        ClockManager_SetClkLevel(client, 2); //lowest
    } else {
        _GBS_StartTimerProc(tmr, *CPU_LOW_FREQ_DELAY_TICKS, SetCPUClockLow);
    }
}


__attribute__((target("thumb")))
__attribute__((section(".text.KeyPressOn_Hook")))
void KeyPressOn_Hook(int keycode) {
    _KeypressOn(keycode);
    if (!(*data)) {
        (*data) = _malloc(sizeof(DATA));
        (*data)->tmr = NULL;
    }
    const int client = *RamClockManagerClient_UI_MSOCPU;
    (*data)->client = client;
    if (client) {
        GBSTMR *tmr = (*data)->tmr;
        ClockManager_SetClkLevel(client, 5); // highest
        if (!tmr) {
            tmr = _malloc(sizeof(GBSTMR));
            (*data)->tmr = tmr;
        }
        _GBS_StartTimerProc(tmr, *CPU_LOW_FREQ_DELAY_TICKS, SetCPUClockLow);
    }
}
