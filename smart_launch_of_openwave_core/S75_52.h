#pragma once

#define ADDR_malloc            (0xA0094B5C)
#define ADDR_mfree             (0xA0094948)
#define ADDR_strcpy            (0xA0FC52D1)
#define ADDR_NU_Sleep          (0xA00A275C)
#define ADDR_GBS_SendMessage   (0xA0092A94)

#define ADDR_RAP_GBS_SendMessage (0xA096F74E | 1)

#define ADDR_OPWV_GetState              (0xA04FC3E6 | 1)
#define ADDR_OPWV_StartBrowser          (0xA04FBEF8 | 1)
#define ADDR_OPWV_Messenger_Init        (0xA0D3D64E | 1)
#define ADDR_OPWV_Messenger_SendMessage (0xA0D3AE38 | 1)
