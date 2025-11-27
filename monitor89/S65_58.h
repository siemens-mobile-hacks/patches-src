#pragma once

#include <swilib.h>

#define ADDR_udiv              (0xA0837018)
#define ADDR_malloc (uint16_t*)(0xA0820F98)
#define ADDR_mfree  (uint16_t*)(0xA0821000)
#define ADDR_strtoul           (0xA166B0D9)
#define ADDR_sprintf           (0xA1669A99)
#define ADDR_AllocWS           (0xA0C30C67)
#define ADDR_wsprintf          (0xA0C3046F)
#define ADDR_RefreshGUI        (0xA11448FD)
#define ADDR_SetSoftKey        (0xA1149683)
#define ADDR_TViewSetText      (0xA115EC37)
#define ADDR_wstrcatprintf     (0xA0C304CD)
#define ADDR_GeneralFuncF1     (0xA11447C9)
#define ADDR_SetHeaderText     (0xA115F74D)
#define ADDR_GetHeaderPointer  (0xA1148DA7)

#define ADDR_RamCap (uint16_t*)(0xA86C2678)

#define ADDR_OnKey                (0xA08E0406 | 1)
#define ADDR_GetExStat            (0xA123CC1C)
#define ADDR_GetOpTime            (0xA1253CC8)
#define ADDR_GetTalkTime          (0xA1253CE8)
#define ADDR_PhoneStatus_CreateUI (0xA08E072C | 1)

#define ADDR_RamCCMon           (char*)(0xA8774BF4)
#define ADDR_RamChargeCount  (int16_t*)(0xA86C274C)
#define ADDR_RamChargeBroken (int16_t*)(0xA86C274A)
#define ADDR_RamChargeFast   (int16_t*)(0xA86C2750)

#define ADDR_SOFTKEY_LEFT          (SOFTKEY_DESC*)(0xA0936BD4)
