#pragma once

#define ADDR_IsUnlocked         (0xA07B77C3)
#define ADDR_CreateMenu         (0xA077D459)
#define ADDR_RebootPhone        (0xA07F21D0)
#define ADDR_AllocMenuWS        (0xA0782549)
#define ADDR_AllocMenuItem      (0xA078243B)
#define ADDR_wsRemoveChars      (0xA0777889)
#define ADDR_wstrcapitalize     (0xA0793ECD)
#define ADDR_SwitchPhoneOff     (0xA07F21C4)
#define ADDR_GetCurMenuItem     (0xA0780F27)
#define ADDR_SetMenuItemText    (0xA0781D0D)
#define ADDR_GetLangMesIntoWS   (0xA0A1CE57)
#define ADDR_IsDirectCallActive (0xA02A90E5)

#define ADDR_RamNetworkState (uint8_t*)(0xA84C47F2)

#define ADDR_IDLE_OnKey     (0xA02D218C | 1)
#define ADDR_EnableNetwork  (0xA0F60350)
#define ADDR_DisableNetwork (0xA0F60300)
#define ADDR_IsSIMAvailable (0xA02B9A64 | 1)

#define ADDR_MENU_DESC (MENU_DESC*)(0xA11E2080)

#define LGP_ID_SHUTDOWN 0xFD2
#define LGP_ID_REBOOT   0x592
#define LGP_ID_ONLINE   0x1238
#define LGP_ID_OFFLINE  0x123A
