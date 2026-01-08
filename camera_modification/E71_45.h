#pragma once

#include <swilib.h>

#define ADDR_udiv                (0xA0FAFEF0)
#define ADDR_malloc    (int32_t*)(0xA0092F51)
#define ADDR_mfree     (int32_t*)(0xA0092F93)
#define ADDR_memcpy              (0xA0FAFCA4)
#define ADDR_zeromem             (0xA0FAFC00)
#define ADDR_AllocWS             (0xA093F611)
#define ADDR_FreeWS              (0xA04FAB85)
#define ADDR_wstrcat             (0xA04FB411)
#define ADDR_wsprintf            (0xA093EB4D)
#define ADDR_GetDateTime         (0xA08CF3FB)
#define ADDR_wstrcatprintf       (0xA093EBE7)
#define ADDR_SetHeaderIcon       (0xA0A283F7)
#define ADDR_GetDataOfItemByID   (0xA0A22839)
#define ADDR_SetHeaderExtraText  (0xA0A28245)
#define ADDR_GUI_GetUserPointer  (0xA095654F)
#define ADDR_StartNativeExplorer (0xA0699924)

#define ADDR_BaseOnRedraw (0xA0955BEE | 1)
#define ADDR_SetHeaderLgp (0xA0A28138 | 1)

#define ADDR_Free                    (0xA07075C4)
#define ADDR_OnKey                   (0xA0707D24)
#define ADDR_RefreshIcons            (0xA070AC54)
#define ADDR_GetCurrentGUI           (0xA070AE18)
#define ADDR_SetPropertyTemporary    (0xA06732EC)
#define ADDR_StartViewFinderWithSize (0xA0672C1C)

#define ADDR_PhotoResolution_0 (uint16_t*)(0xA084BFD8)
#define ADDR_PhotoResolution_1 (uint16_t*)(0xA084BFCC)
#define ADDR_PhotoResolution_2 (uint16_t*)(0xA084BFC0)
#define ADDR_PhotoResolution_3 (uint16_t*)(0xA084BFB4)
#define ADDR_PhotoResolution_4 (uint16_t*)(0xA084BFA8)

#define PHOTO_ICON (int*)(0xA086F280)
#define VIDEO_ICON (int*)(0xA086F26C)
