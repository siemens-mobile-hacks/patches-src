#pragma once

#include <swilib.h>

#define ADDR_udiv              (0xA0219FE8)
#define ADDR_malloc (uint16_t*)(0xA0203C24)
#define ADDR_mfree  (uint16_t*)(0xA0203C8C)
#define ADDR_strtoul           (0xA0E502D5)
#define ADDR_sprintf           (0xA0E4E635)
#define ADDR_AllocWS           (0xA07717AB)
#define ADDR_wsprintf          (0xA0770F9B)
#define ADDR_RefreshGUI        (0xA077875F)
#define ADDR_SetSoftKey        (0xA077D56D)
#define ADDR_TViewSetText      (0xA07B6403)
#define ADDR_wstrcatprintf     (0xA0770FF9)
#define ADDR_GeneralFuncF1     (0xA077850D)
#define ADDR_SetHeaderText     (0xA07B6F19)
#define ADDR_GetHeaderPointer  (0xA077CC81)

#define ADDR_RamCap (uint16_t*)(0xA84E96C0)

#define ADDR_OnKey                (0xA0334656 | 1)
#define ADDR_GetExStat            (0xA07C70BC)
#define ADDR_GetOpTime            (0xA07DE36C)
#define ADDR_GetTalkTime          (0xA07DE38C)
#define ADDR_PhoneStatus_CreateUI (0xA033497C | 1)

#define ADDR_RamCCMon           (char*)(0xA85AB104)
#define ADDR_RamChargeCount  (int16_t*)(0xA84E9794)
#define ADDR_RamChargeBroken (int16_t*)(0xA84E9792)
#define ADDR_RamChargeFast   (int16_t*)(0xA84E9798)

#define ADDR_SOFTKEY_LEFT (SOFTKEY_DESC*)(0xA04AFDC8)
