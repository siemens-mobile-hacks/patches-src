#pragma once

#define ADDR_IsUnlocked         (0xA1158B87)
#define ADDR_CreateMenu         (0xA1143A09)
#define ADDR_RebootPhone        (0xA1263C44)
#define ADDR_AllocMenuWS        (0xA1148879)
#define ADDR_AllocMenuItem      (0xA114876B)
#define ADDR_wsRemoveChars      (0xA0C30F19)
#define ADDR_wstrcapitalize     (0xA0C3A641)
#define ADDR_SwitchPhoneOff     (0xA1263C38)
#define ADDR_GetCurMenuItem     (0xA1147257)
#define ADDR_SetMenuItemText    (0xA114803D)
#define ADDR_GetLangMesIntoWS   (0xA1405E97)
#define ADDR_IsDirectCallActive (0xA16985D9)

#define ADDR_RamNetworkState (uint8_t*)(0xA8690BDA)

#define ADDR_IDLE_OnKey     (0xA169F634 | 1)
#define ADDR_EnableNetwork  (0xA0FA0350)
#define ADDR_DisableNetwork (0xA0FA0300)
#define ADDR_IsSIMAvailable (0xA08C3AC0 | 1)

#define ADDR_MENU_DESC (MENU_DESC*)(0xA17B2080)

#define LGP_ID_SHUTDOWN 0xF65
#define LGP_ID_REBOOT   0x561
#define LGP_ID_ONLINE   0x11C6
#define LGP_ID_OFFLINE  0x11C7
