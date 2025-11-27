#pragma once

#include <swilib.h>

#define ADDR_udiv              (0xA0219FE8)
#define ADDR_malloc (uint16_t*)(0xA0203C24)
#define ADDR_mfree  (uint16_t*)(0xA0203C8C)
#define ADDR_strtoul           (0xA0E5AF8D)
#define ADDR_sprintf           (0xA0E592ED)
#define ADDR_AllocWS           (0xA07775D7)
#define ADDR_wsprintf          (0xA0776DC7)
#define ADDR_RefreshGUI        (0xA077E58B)
#define ADDR_SetSoftKey        (0xA0783399)
#define ADDR_TViewSetText      (0xA07BD913)
#define ADDR_wstrcatprintf     (0xA0776E25)
#define ADDR_SetHeaderText     (0xA07BE429)
#define ADDR_GetHeaderPointer  (0xA0782AAD)

#define ADDR_RamCap (uint16_t*)(0xA84E8878)

#define ADDR_OnKey       (0xA033AF3E | 1)
#define ADDR_GetCCMon_ws (0xA033AF62 | 1)
#define ADDR_GetExStat   (0xA07CE5E8)
#define ADDR_GetOpTime   (0xA07E5898)
#define ADDR_GetTalkTime (0xA07E58B8)

#define ADDR_RamCCMon           (char*)(0xA85A8D8C)
#define ADDR_RamChargeCount  (int16_t*)(0xA84E894C)
#define ADDR_RamChargeBroken (int16_t*)(0xA84E894A)
#define ADDR_RamChargeFast   (int16_t*)(0xA84E8950)

#define ADDR_SOFTKEY_LEFT          (SOFTKEY_DESC*)(0xA04B54A8)
#define ADDR_SOFTKEY_DEFAULT_LEFT  (SOFTKEY_DESC*)(0xA04AA9F4)
#define ADDR_SOFTKEY_DEFAULT_RIGHT (SOFTKEY_DESC*)(0xA04AA9FC)
