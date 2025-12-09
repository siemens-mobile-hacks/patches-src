#pragma once

#define ADDR_malloc       (uint32_t*)(0xA0092F51)
#define ADDR_mfree        (uint32_t*)(0xA0092F93)
#define ADDR_zeromem                 (0xA0FAFC00)
#define ADDR_wstrcpy                 (0xA04FB3CB)
#define ADDR_CloseCSM                (0xA0946A75)
#define ADDR_FindCSMbyID             (0xA0946971)
#define ADDR_MsgBoxError             (0xA094EA89)
#define ADDR_GetDataOfItemById       (0xA0A22839)
#define ADDR_DrawCroppedIMGHDR       (0xA0A0CB71)
#define ADDR_StartNativeExplorer     (0xA0699924)
#define ADDR_GetIMGHDRFromThemeCache (0xA0A26A95)

#define ADDR_RamSRCSM (SR_CSM**)(0xA8F05664)

#define ADDR_List_GHook   (0xA07D0340)
#define ADDR_List_OnClose (0xA07AA190)

#define ADDR_Recording_SetText           (0xA07D1AFC)
#define ADDR_Recording_UpdateElapsedTime (0xA07D19F4)

#define LGP_ID_NOT_POSSIBLE_AT_PRESENT 0x2C4
