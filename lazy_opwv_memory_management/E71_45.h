#pragma once

#include "data.h"

#define ADDR_mfree           (0xA0092F93)
#define ADDR_malloc          (0xA0092F51)
#define ADDR_strcpy          (0xA122AF05)
#define ADDR_zeromem         (0xA0FAFC00)
#define ADDR_NU_Sleep        (0xA009CD50)
#define ADDR_ClearMemory     (0xA0FAFC48)
#define ADDR_GBS_SendMessage   (0xA0091EAB)
#define ADDR_GeneralFunc_flag1 (0xA094F5B3)
#define ADDR_ShowPleaseWaitBox (0xA094EF0B)

#define ADDR_MemHeapFreePool     (0xA0093B4E | 1)
#define ADDR_MemDestroyHeapPool  (0xA009382E | 1)
#define ADDR_RAP_GBS_SendMessage (0xA09460EE | 1)

#define ADDR_OPWV_GetData               (0xA06C75DC | 1)
#define ADDR_OPWV_SetState              (0xA05FB596 | 1)
#define ADDR_OPWV_GetState              (0xA05FB55A | 1)
#define ADDR_OPWV_StartApp              (0xA05FB126 | 1)
#define ADDR_OPWV_Messenger_Init        (0xA0D222E6 | 1)
#define ADDR_OPWV_Messenger_SendMessage (0xA0D1FA68 | 1)

#define data ((DATA**)(0xA8E37364))
