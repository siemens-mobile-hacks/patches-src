#pragma once

#define ADDR_malloc  (uint32_t*)(0xA0092F51)
#define ADDR_KeypressOn         (0xA08D3553)
#define ADDR_GBS_DelTimer       (0xA0097A53)
#define ADDR_GBS_StartTimerProc (0xA0092531)

#define ADDR_ClockManager_SetClkLevel      (0xA04D0728)

#define RamPressedKey (uint16_t*)(0xA8DF3320)

#define RamClockManagerClient_UI_MSOCPU (int*)(0xA8EA9BC4)

//bye bye PREDIAL
#define data ((DATA**)(0xA8E3735E))

#define CPU_LOW_FREQ_DELAY_TICKS (uint32_t*)(0xA1383800)
