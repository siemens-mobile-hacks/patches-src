#pragma once

#define ADDR_IsUnlocked         (0xA0CC8D0F)
#define ADDR_CreateMenu         (0xA112BAE9)
#define ADDR_RebootPhone        (0xA1165AC4)
#define ADDR_AllocMenuWS        (0xA0CA2CB9)
#define ADDR_AllocMenuItem      (0xA0CA2BAB)
#define ADDR_wsRemoveChars      (0xA0C996F9)
#define ADDR_wstrcapitalize     (0xA0CA5401)
#define ADDR_SwitchPhoneOff     (0xA1165AB8)
#define ADDR_GetCurMenuItem     (0xA0CA1697)
#define ADDR_SetMenuItemText    (0xA0CA247D)
#define ADDR_GetLangMesIntoWS   (0xA1567827)
#define ADDR_IsDirectCallActive (0xA08C4645)

#define ADDR_RamNetworkState (uint8_t*)(0xA844564E)

#define ADDR_IDLE_OnKey     (0xA08DDFC0 | 1)
#define ADDR_EnableNetwork  (0xA0FA0350)
#define ADDR_DisableNetwork (0xA0FA0300)
#define ADDR_IsSIMAvailable (0xA08CB3C0 | 1)

#define ADDR_MENU_DESC (MENU_DESC*)(0xA17B2080)

#define LGP_ID_SHUTDOWN 0xFD2
#define LGP_ID_REBOOT   0x592
#define LGP_ID_ONLINE   0x1238
#define LGP_ID_OFFLINE  0x123A
