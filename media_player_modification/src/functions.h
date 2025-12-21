#pragma once

#include "mp.h"

#ifdef E71_45
    #include "../E71_45.h"
#endif

#define malloc ((void *(*)(size_t))(ADDR_malloc))
#define mfree ((void (*)(void *))(ADDR_mfree))
#define memcpy ((void *(*)(void *, const void *, size_t))(ADDR_memcpy))
#define strlen ((int (*)(const char *))(ADDR_strlen))
#define strncmp ((int (*)(const char *, const char *, size_t))(ADDR_strncmp))
#define _zeromem ((void (*)(void *, size_t))(ADDR_zeromem))
#define _AllocWS ((WSHDR *(*)(size_t))(ADDR_AllocWS))
#define _wsprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wsprintf))
#define _wstriwstr ((int (*)(const WSHDR *, const WSHDR *, int))(ADDR_wstriwstr))
#define _DrawString ((void (*)(const WSHDR *, int, int, int, int, int, int, const char *, const char *))(ADDR_DrawString))
#define _DrawIMGHDR ((void (*)(int x, int y, const IMGHDR *))(ADDR_DrawIMGHDR))
#define _wstrinsert ((void (*)(WSHDR *, const WSHDR *, int))(ADDR_wstrinsert))
#define _GetFontYSIZE ((int (*)(int))(ADDR_GetFontYSIZE))
#define _wsInsertChar ((void (*)(WSHDR *, uint16_t, int))(ADDR_wsInsertChar))
#define _SetMenuToGUI ((void (*)(void *, void *))(ADDR_SetMenuToGUI))
#define _CreateLocalWS ((WSHDR *(*)(WSHDR *, uint16_t *, size_t))(ADDR_CreateLocalWS))
#define _DrawRectangle ((void (*)(int, int, int, int, int, const char *, const char *))(ADDR_DrawRectangle))
#define _GetCurMenuItem ((int (*)(void *))(ADDR_GetCurMenuItem))
#define _GBS_SendMessage ((void (*)(int, int, ...))(ADDR_GBS_SendMessage))
#define _GetLangMesIntoWS ((void (*)(int, WSHDR *))(ADDR_GetLangMesIntoWS))
#define _GetMenuItemCount ((int (*)(void *))(ADDR_GetMenuItemCount))
#define _GetDataOfItemByID ((void *(*)(void *, int))(ADDR_GetDataOfItemByID))
#define _DrawCroppedIMGHDR ((void (*)(int, int, int, int, int, int, int, IMGHDR *))(ADDR_DrawCroppedIMGHDR))
#define _MenuGetUserPointer ((void *(*)(void *))(ADDR_MenuGetUserPointer))
#define _SetCursorToMenuItem ((void (*)(void *, int))(ADDR_SetCursorToMenuItem))
#define _SetHeaderScrollText ((void (*)(void *, const WSHDR *, const void *, const void *))(ADDR_SetHeaderScrollText))
#define _GetIMGHDRFromThemeCache ((IMGHDR *(*)(int))(ADDR_GetIMGHDRFromThemeCache))
#define _GetPaletteAdrByColorIndex ((const char *(*)(int))(ADDR_GetPaletteAdrByColorIndex))

#define _GUI_NewTimer ((int (*)(void *))(ADDR_GUI_NewTimer))
#define _GUI_DeleteTimer ((int (*)(void *, int))(ADDR_GUI_DeleteTimer))
#define _GUI_StartTimerProc ((void (*)(void *, int, long, GUI_TimerProc))(ADDR_GUI_StartTimerProc))

#define _sys_open_ws ((int (*)(const WSHDR *, uint32_t, uint32_t, uint32_t *))(ADDR_sys_open_ws))
#define _sys_read ((int (*)(int, void *, int, uint32_t *))(ADDR_sys_read))
#define _sys_lseek ((int (*)(int, uint32_t, uint32_t, uint32_t *, uint32_t *))(ADDR_sys_lseek))
#define _sys_close ((int (*)(int, uint32_t *))(ADDR_sys_close))

#define _BuildPath ((int (*)(WSHDR *, const WSHDR *, const WSHDR *))(ADDR_BuildPath))
#define _GetExtUid_ws ((int (*)(const WSHDR *))(ADDR_GetExtUid_ws))
#define _GetExtUidByFileName_ws ((int (*)(const WSHDR *))(ADDR_GetExtUidByFileName_ws))

#define _iso8859_1_2ws ((int (*)(WSHDR *, const char *, size_t))(ADDR_iso8859_1_2ws))
#define _str_2ws ((int (*)(WSHDR *, const char *, size_t))(ADDR_str_2ws))

#define _GetDateTime ((void (*)(TDate *, TTime *))(ADDR_GetDateTime))
#define _GetSecondsFromDateTimeSince1997 ((int (*)(int *, TDate *, TTime *))(ADDR_GetSecondsFromDateTimeSince1997))

#define srand ((void (*)(uint32_t))(ADDR_srand))
#define _rand ((int (*)())(ADDR_rand))

#define _Obs_CreateObject ((HObj (*)(int, int, int, int, int, int, uint32_t *))(ADDR_Obs_CreateObject))
#define _Obs_SetInputMemory ((int (*)(HObj, int, char *, int))(ADDR_Obs_SetInput_Memory))
#define _Obs_SetOutputImageSize ((int (*)(HObj, short, short))(ADDR_Obs_SetOutputImageSize))
#define _Obs_SetScaling ((int (*)(HObj, int))(ADDR_Obs_SetScaling))
#define _Obs_Start ((int (*)(HObj))(ADDR_Obs_Start))
#define _Obs_Output_GetPictstruct ((int (*)(HObj, IMGHDR **))(ADDR_Obs_Output_GetPictstruct))
#define _Obs_DestroyObject ((int (*)(HObj))(ADDR_Obs_DestroyObject))
#define _CalcBitmapSize ((int (*)(short, short, char))(ADDR_CalcBitmapSize))

#define _NU_Sleep ((void (*)(unsigned long))(ADDR_NU_Sleep))
#define _SUBPROC(f, p2) _GBS_SendMessage(HELPER_CEPID, 0x0001, p2, f, NULL);
