#pragma once

#ifdef E71_45
    #include "../E71_45.h"
#endif

#define _wstrlen ((int (*)(const WSHDR *))(ADDR_wstrlen))
#define _wstrcmp ((int (*)(const WSHDR *, const WSHDR *))(ADDR_wstrcmp))
#define _wsprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wsprintf))
#define _isdir_ws ((int (*)(const WSHDR *))(ADDR_isdir_ws))
#define _BuildPath ((int (*)(WSHDR *, const WSHDR *, const WSHDR *))(ADDR_BuildPath))
#define _GetPITaddr ((IMGHDR *(*)(int))(ADDR_GetPITaddr))
#define _CreateLocalWS ((void (*)(WSHDR *, uint16_t *, int))(ADDR_CreateLocalWS))
#define _AllocMenuItem ((void *(*)(void *))(ADDR_AllocMenuItem))
#define _GetCurMenuItem ((int (*)(void *))(ADDR_GetCurMenuItem))
#define _SetMenuItemText ((void (*)(void *, void *, const WSHDR *, int))(ADDR_SetMenuItemText))
#define _GBS_SendMessage ((void (*)(int, int , ...))(ADDR_GBS_SendMessage))
#define _GetHeaderPointer ((void *(*)(void *))(ADDR_GetHeaderPointer))
#define _GetFileAttrib_ws ((int (*)(const WSHDR *, uint8_t *, unsigned int *))(ADDR_GetFileAttrib_ws))
#define _SetFileAttrib_ws ((int (*)(const WSHDR *, uint8_t, unsigned int *))(ADDR_SetFileAttrib_ws))
#define _GetMenuItemCount ((int (*)(void *))(ADDR_GetMenuItemCount))
#define _MenuGetUserPointer ((void *(*)(void *))(ADDR_MenuGetUserPointer))
#define _SetMenuItemIconArray ((void (*)(void *, void *, int *))(ADDR_SetMenuItemIconArray))
#define _SetMenuItemIconIMGHDR ((void (*)(void *, void *, const IMGHDR *))(ADDR_SetMenuItemIconIMGHDR))
#define _GetExtUidByFileName_ws ((int (*)(const WSHDR *))(ADDR_GetExtUidByFileName_ws))

#define GetItemPath ((void (*)(NATIVE_EXPLORER_CSM *, int, WSHDR *))(ADDR_GetItemPath))
#define GetCurrentDir ((void (*)(NATIVE_EXPLORER_CSM *, WSHDR *ws))(ADDR_GetCurrentDir))
#define GetTabItemsCount ((int (*)(NATIVE_EXPLORER_CSM *))(ADDR_GetTabItemsCount))


__attribute__((always_inline))
inline void *GetCSM(void *gui) {
    return (void*)(*(int*)((int)_MenuGetUserPointer(gui) + 8));
}
