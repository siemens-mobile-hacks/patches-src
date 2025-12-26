#pragma once

#include <swilib.h>

#define ADDR_CloseCSM    (0xA0946A75)
#define ADDR_LockSched   (0xA00976FF)
#define ADDR_UnlockSched (0xA009777B)
#define ADDR_MsgBoxError (0xA094EA89)
#define ADDR_FindCSMbyID (0xA0946971)

#define ADDR_CSM_root (CSMROOT*)(0xA8E903AC)

#define ADDR_CallsList_OnCreate  (0xA0A82576 | 1)
#define ADDR_CallsList_OnClose   (0xA0A825E2 | 1)
#define ADDR_CallsList_GHook     (0xA0B205E8 | 1)

#define ADDR_CallsList_View_OnClose (0xA08F6184 | 1)
#define ADDR_CallsList_View_GHook   (0xA09A3710 | 1)

#define ADDR_CallsList_Options_OnCreate  (0xA09A2B2C | 1)
#define ADDR_CallsList_Options_OnClose   (0xA09A2B56 | 1)

#define CALLS_LIST_CSM_DESC      (CSM_DESC*)(0xA0C60BF0)
#define CALLS_LIST_VIEW_CSM_DESC (CSM_DESC*)(0xA0C2C278)

#define LGP_ID_NOT_POSSIBLE_AT_PRESENT 0x2C4
