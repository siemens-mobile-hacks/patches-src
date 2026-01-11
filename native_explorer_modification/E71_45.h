#pragma once

#define ADDR_malloc      (uint32_t*)(0xA0092F51)
#define ADDR_mfree       (uint32_t*)(0xA0092F93)
#define ADDR_zeromem                (0xA0FAFC00)
#define ADDR_AllocWS                (0xA093F611)
#define ADDR_wstrlen                (0xA04FAC53)
#define ADDR_wstrcmp                (0xA04FAC7F)
#define ADDR_wstrcat                (0xA04FB411)
#define ADDR_wsprintf               (0xA093EB4D)
#define ADDR_isdir_ws               (0xA0568028)
#define ADDR_BuildPath              (0xA05D0534)
#define ADDR_RefreshGUI             (0xA094F6E5)
#define ADDR_GetPITaddr             (0xA094CE9B)
#define ADDR_wsAppendChar           (0xA04FB4D9)
#define ADDR_CreateLocalWS          (0xA04FB25B)
#define ADDR_AllocMenuItem          (0xA0954585)
#define ADDR_GetCurMenuItem         (0xA0952DBB)
#define ADDR_SetMenuItemText        (0xA0953E97)
#define ADDR_GBS_SendMessage        (0xA0091EAB)
#define ADDR_GetFileAttrib_ws       (0xA0567EF8)
#define ADDR_SetFileAttrib_ws       (0xA05681EC)
#define ADDR_GetHeaderPointer       (0xA0954E3D)
#define ADDR_GetMenuItemCount       (0xA0950F33)
#define ADDR_GetTotalFlexSpace      (0xA05686C0)
#define ADDR_GUI_GetUserPointer     (0xA095654F)
#define ADDR_SetHeaderScrollText    (0xA0A285B9)
#define ADDR_SetMenuItemIconArray   (0xA09544F7)
#define ADDR_SetMenuItemIconIMGHDR  (0xA09544FB)
#define ADDR_GetExtUidByFileName_ws (0xA05026F8)

#define ADDR_MENU_ICON_EMPTY (int*)(0xA0C3608C)

#define ADDR_RefreshTab       (0xA069A57C)
#define ADDR_GetTabByCSM      (0xA071D770)
#define ADDR_GetItemPath      (0xA0698C24)
#define ADDR_GetCurrentDir    (0xA0699FF0)
#define ADDR_GetTabItemsCount (0xA0699970)

#define ADDR_SetItemsText (0xA071E948)

#define ADDR_MergeIcons  (0xA0718A70)
#define ADDR_MergeIMGHDR (0xA094D0DC | 1)
#define ADDR_IsDirectory (0xA071D7DC)

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

#define ADDR_ShowFileAttributes (0xA07130DC)

#define ADDR_IsRootDir (0xA0699D84)

#define ADDR_CreateDir (0xA05D02E8)

#define ADDR_SetThumbnailEnable (0xA0698ADC)
#define ADDR_IsThumbnailEnabled (0xA0698ABC)

#define ADDR_Search_OnKey             (0xA0785628)
#define ADDR_Search_GHook             (0xA0785698)
#define ADDR_Search_OnMessage         (0xA071230C)

#define ADDR_Search_SendFile          (0xA07111EC)
#define ADDR_Search_ExecuteFile       (0xA0711790)
#define ADDR_Search_IsFileExists      (0xA0710F00)
#define ADDR_Search_CreateOptionsGUI  (0xA07859CC)
#define ADDR_Search_CreateOptionsMenu (0xA0785BF8)

#define ADDR_GetExtIconSmall (0xA05028C8)

#define ICON_UNK 0x3EA
#define LGP_ID_SEARCH 0xDAE
