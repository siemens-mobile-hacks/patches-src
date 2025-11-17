#pragma once

#define ADDR_IsUnlocked         (0xA0CB677B)
#define ADDR_CreateMenu         (0xA0C91EB1)
#define ADDR_RebootPhone        (0xA116CB94)
#define ADDR_AllocMenuWS        (0xA0C96D21)
#define ADDR_AllocMenuItem      (0xA0C96C13)
#define ADDR_wsRemoveChars      (0xA0C8D269)
#define ADDR_wstrcapitalize     (0xA0C99A29)
#define ADDR_SwitchPhoneOff     (0xA116CB88)
#define ADDR_GetCurMenuItem     (0xA0C956FF)
#define ADDR_SetMenuItemText    (0xA0C964E5)
#define ADDR_GetLangMesIntoWS   (0xA1559B43)
#define ADDR_IsDirectCallActive (0xA1715059)

#define ADDR_RamNetworkState (uint8_t*)(0xA868F326)

#define ADDR_IDLE_OnKey     (0xA171C004 | 1)
#define ADDR_EnableNetwork  (0xA0FA0350)
#define ADDR_DisableNetwork (0xA0FA0300)
#define ADDR_IsSIMAvailable (0xA08C7578 | 1)

#define ADDR_MENU_DESC (MENU_DESC*)(0xA17B2080)

#define LGP_ID_SHUTDOWN 0xF65
#define LGP_ID_REBOOT   0x561
#define LGP_ID_ONLINE   0x11C6
#define LGP_ID_OFFLINE  0x11C7
