#pragma once

#define ADDR_IsUnlocked         (0xA07B02B3)
#define ADDR_CreateMenu         (0xA077762D)
#define ADDR_RebootPhone        (0xA07EACA4)
#define ADDR_AllocMenuWS        (0xA077C71D)
#define ADDR_AllocMenuItem      (0xA077C60F)
#define ADDR_wsRemoveChars      (0xA0771A5D)
#define ADDR_wstrcapitalize     (0xA078C81F)
#define ADDR_SwitchPhoneOff     (0xA07EAC98)
#define ADDR_GetCurMenuItem     (0xA077B0FB)
#define ADDR_SetMenuItemText    (0xA077BEE1)
#define ADDR_GetLangMesIntoWS   (0xA0A14B97)
#define ADDR_IsDirectCallActive (0xA02A8271)

#define ADDR_RamNetworkState (uint8_t*)(0xA84C2B3A)

#define ADDR_IDLE_OnKey     (0xA02CF04C | 1)
#define ADDR_EnableNetwork  (0xA0F60350)
#define ADDR_DisableNetwork (0xA0F60300)
#define ADDR_IsSIMAvailable (0xA02B8BE8 | 1)

#define ADDR_MENU_DESC (MENU_DESC*)(0xA11E2080)

#define LGP_ID_SHUTDOWN 0xFD2
#define LGP_ID_REBOOT   0x592
#define LGP_ID_ONLINE   0x1238
#define LGP_ID_OFFLINE  0x123A
