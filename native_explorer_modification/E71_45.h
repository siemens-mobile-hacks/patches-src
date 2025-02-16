#pragma once

#define ADDR_malloc             (void*)(0xA0092F51)
#define ADDR_mfree              (void*)(0xA0092F93)
#define ADDR_wstrlen            (0xA04FAC53)
#define ADDR_wstrcmp            (0xA04FAC7F)
#define ADDR_wsprintf           (0xA093EB4D)
#define ADDR_isdir_ws           (0xA0568028)
#define ADDR_BuildPath          (0xA05D0534)
#define ADDR_GetPITaddr         (0xA094CE9B)
#define ADDR_CreateLocalWS      (0xA04FB25B)
#define ADDR_GBS_SendMessage    (0xA0091EAB)
#define ADDR_GetFileAttrib_ws   (0xA0567EF8)
#define ADDR_GetHeaderPointer   (0xA0954E3D)
#define ADDR_GetMenuItemCount   (0xA0950F33)
#define ADDR_MenuGetUserPointer (0xA095654F)

#define ADDR_GetItemPath      (0xA0698C24)
#define ADDR_GetCurrentDir    (0xA0699FF0)
#define ADDR_GetTabItemsCount (0xA0699970)

#define ADDR_MergeIcons  (0xA0718A70)
#define ADDR_MergeIMGHDR (0xA094D0DC | 1)
#define ADDR_IsDirectory (0xA071D7DC)

#define ADDR_ClearLgp           (0xA095D6FC)
#define ADDR_SetLgpText         (0xA095D468)
#define ADDR_SetHeaderExtraLgp  (0xA0A281EA | 1)

#define KEYMAP               (uint8_t*)(0xA1380850)
#define DISABLED_CMD_DEFAULT (uint8_t*)(0xA1380A50)
#define DISABLED_CMD_MARK    (uint8_t*)(0xA1380A60)
#define DISABLED_CMD_CM      (uint8_t*)(0xA1380A70)
#define ADDR_OnKey                     (0xA07864B8)
#define ADDR_SendCMD                   (0xA0698794)

#define ADDR_CopyFile   (0xA069B398)
#define ADDR_MoveFile   (0xA069B4BC)
#define ADDR_SendFile   (0xA069AFD0)
#define ADDR_ShowSort   (0xA069B6D8)
#define ADDR_ShowSetAs  (0xA069B86C)
#define ADDR_DeleteFile (0xA069ADB8)
#define ADDR_ShowRename (0xA069B638)

#define ADDR_Paste_Unknown_1     (0xA0698EE0)
#define ADDR_Paste_Unknown_2     (0xA0716004)
#define ADDR_DisableItem_Unknown (0xA07162FC)

#define ADDR_IsRootDir (0xA0699D84)
