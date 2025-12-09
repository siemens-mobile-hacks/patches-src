#pragma once

#define ADDR_malloc       (uint32_t*)(0xA0094B5C)
#define ADDR_mfree        (uint32_t*)(0xA0094948)
#define ADDR_zeromem                 (0xA0FC496C)
#define ADDR_wstrcpy                 (0xA01F77C3)
#define ADDR_CloseCSM                (0xA096FFA7)
#define ADDR_FindCSMbyID             (0xA096FEB1)
#define ADDR_MsgBoxError             (0xA0977D2D)
#define ADDR_DisableIDLETMR          (0xA097887B)
#define ADDR_GetDataOfItemById       (0xA0A18745)
#define ADDR_DrawCroppedIMGHDR       (0xA0A02CB5)
#define ADDR_StartNativeExplorer     (0xA052A5F7)
#define ADDR_GetIMGHDRFromThemeCache (0xA0A1C803)

#define ADDR_RamSRCSM (SR_CSM**)(0xA8E3EC4C)

#define ADDR_List_GHook   (0xA062C608 | 1)
#define ADDR_List_OnClose (0xA0604472 | 1)

#define ADDR_Recording_SetText           (0xA062D506 | 1)
#define ADDR_Recording_UpdateElapsedTime (0xA062D476 | 1)

#define LGP_ID_NOT_POSSIBLE_AT_PRESENT 0x2C4
