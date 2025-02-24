#pragma once

#define ADDR_SetVLType         (0xA0633FA0)
#define ADDR_StopVibration     (0xA06D922E | 1)
#define ADDR_IsVibraLocked     (0xA04AD186 | 1)
#define ADDR_IsFeatureEnabled  (0xA0932802 | 1)
#define ADDR_GetDynlightStatus (0xA05AEC14 | 1)

#define ADDR_SLI_SetState   0xA04B77D4
#define ADDR_SetVibration   0xA04AD9CB
#define ADDR_GetVibraStatus 0xA05AEC0F
