#pragma once

#include <swilib.h>

#define ADDR_udiv              (0xA0837360)
#define ADDR_malloc (uint16_t*)(0xA0820F9C)
#define ADDR_mfree  (uint16_t*)(0xA0821004)
#define ADDR_strtoul           (0xA170DBB9)
#define ADDR_sprintf           (0xA1622199)
#define ADDR_AllocWS           (0xA0C99447)
#define ADDR_wsprintf          (0xA0C98C37)
#define ADDR_RefreshGUI        (0xA0C9ECFB)
#define ADDR_SetSoftKey        (0xA112D1C9)
#define ADDR_TViewSetText      (0xA1133B0B)
#define ADDR_wstrcatprintf     (0xA0C98C95)
#define ADDR_SetHeaderText     (0xA1134621)
#define ADDR_GetHeaderPointer  (0xA112C8DD)

#define ADDR_RamCap (uint16_t*)(0xA8465EE4)

#define ADDR_OnKey       (0xA08F86C6 | 1)
#define ADDR_GetCCMon_ws (0xA08F86EA | 1)
#define ADDR_GetExStat   (0xA1144788)
#define ADDR_GetOpTime   (0xA115BA1C)
#define ADDR_GetTalkTime (0xA115BA3C)

#define ADDR_RamCCMon           (char*)(0xA851B826)
#define ADDR_RamChargeCount  (int16_t*)(0xA8465FB8)
#define ADDR_RamChargeBroken (int16_t*)(0xA8465FB6)
#define ADDR_RamChargeFast   (int16_t*)(0xA8465FBC)

#define ADDR_SOFTKEY_LEFT          (SOFTKEY_DESC*)(0xA094FCEC)
#define ADDR_SOFTKEY_DEFAULT_LEFT  (SOFTKEY_DESC*)(0xA094A070)
#define ADDR_SOFTKEY_DEFAULT_RIGHT (SOFTKEY_DESC*)(0xA094A078)
