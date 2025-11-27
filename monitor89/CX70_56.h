#pragma once

#include <swilib.h>

#define ADDR_udiv              (0xA0837018)
#define ADDR_malloc (uint16_t*)(0xA0820F98)
#define ADDR_mfree  (uint16_t*)(0xA0821000)
#define ADDR_strtoul           (0xA16EF731)
#define ADDR_sprintf           (0xA1610211)
#define ADDR_AllocWS           (0xA0C8CFB7)
#define ADDR_wsprintf          (0xA0C8C7BF)
#define ADDR_RefreshGUI        (0xA0C92DA5)
#define ADDR_SetSoftKey        (0xA0C97B2B)
#define ADDR_TViewSetText      (0xA0CBC2C3)
#define ADDR_wstrcatprintf     (0xA0C8C81D)
#define ADDR_GeneralFuncF1     (0xA0C92C71)
#define ADDR_SetHeaderText     (0xA113D489)
#define ADDR_GetHeaderPointer  (0xA0C9724F)

#define ADDR_RamCap (uint16_t*)(0xA86C0D30)

#define ADDR_OnKey                (0xA08FC126 | 1)
#define ADDR_GetExStat            (0xA114CFB8)
#define ADDR_GetOpTime            (0xA116329C)
#define ADDR_GetTalkTime          (0xA11632BC)
#define ADDR_PhoneStatus_CreateUI (0xA08FC44C | 1)

#define ADDR_RamCCMon           (char*)(0xA8776ED4)
#define ADDR_RamChargeCount  (int16_t*)(0xA86C0E04)
#define ADDR_RamChargeBroken (int16_t*)(0xA86C0E02)
#define ADDR_RamChargeFast   (int16_t*)(0xA86C0E08)

#define ADDR_SOFTKEY_LEFT          (SOFTKEY_DESC*)(0xA094D66C)
