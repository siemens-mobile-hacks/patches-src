#pragma once

#define ADDR_malloc            (0xA0092F51)
#define ADDR_mfree             (0xA0092F93)
#define ADDR_strcpy            (0xA122AF05)
#define ADDR_NU_Sleep          (0xA009CD50)
#define ADDR_GBS_SendMessage   (0xA0091EAB)

#define ADDR_RAP_GBS_SendMessage (0xA09460EE | 1)

#define ADDR_OPWV_GetState              (0xA05FB55A | 1)
#define ADDR_OPWV_StartBrowser          (0xA05FB06C | 1)
#define ADDR_OPWV_Messenger_Init        (0xA0D222E6 | 1)
#define ADDR_OPWV_Messenger_SendMessage (0xA0D1FA68 | 1)
