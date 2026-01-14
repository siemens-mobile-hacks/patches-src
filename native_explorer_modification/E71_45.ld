SECTIONS {
    .rodata 0xA1380600 : {
        KEEP(*(.rodata*))
    }

    .FixFlags2 0xA088B710 : {
        KEEP(*(.data.FixFlags2))
    }
    .Replace_GetExtIconLarge 0xA071E5B4 : {
        KEEP(*(.text.Replace_GetExtIconLarge))
    }
    .FixDirIcon_1 0xA0870A54 : {
        KEEP(*(.data.FixDirIcon_1))
    }
    .FixDirIcon_2 0xA0870A5C : {
        KEEP(*(.data.FixDirIcon_2))
    }
    .FixUnkIcon 0xA0870340 : {
        KEEP(*(.data.FixUnkIcon))
    }
    .FixPreviewWidth_1 0xA0718D28 : {
        KEEP(*(.text.FixPreviewWidth_1))
    }
    .FixPreviewHeight_1 0xA0718D20 : {
        KEEP(*(.text.FixPreviewHeight_1))
    }
    .FixPreviewWidth_2 0xA0718604 : {
        KEEP(*(.text.FixPreviewWidth_2))
    }
    .FixPreviewHeight_2 0xA0718614 : {
        KEEP(*(.text.FixPreviewHeight_2))
    }

    .FixUnCheckedIcon 0xA0718E28 : {
        KEEP(*(.data.FixUnCheckedIcon))
    }
    .FixCheckedIcon 0xA0718E2C : {
        KEEP(*(.data.FixCheckedIcon))
    }
    .MergeIcons_Hook 0xA1380640 : {
        KEEP(*(.text.MergeIcons_Hook))
    }
    .MergeIcons_Jump1_AddParam 0xA0719BBC : {
        KEEP(*(.text.MergeIcons_Jump1_AddParam))
    }
    .MergeIcons_Jump1 0xA0719BC8 : {
        KEEP(*(.text.MergeIcons_Jump1))
    }
    .MergeIcons_Jump2 0xA0719DD4 : {
        KEEP(*(.text.MergeIcons_Jump2))
    }
    .IsAllowThumbnail 0xA13806A0 : {
        KEEP(*(.text.IsAllowThumbnail))
    }
    .IsAllowThumbnail_Jump 0xA0718E50 : {
        KEEP(*(.text.IsAllowThumbnail_Jump))
    }

    .SetItemsText_Hook 0xA1380720 : {
        KEEP(*(.text.SetItemsText_Hook))
    }
    .SetItemsText_Jump 0xA071EE70 : {
        KEEP(*(.text.SetItemsText_Jump))
    }
    .HideEntriesCount 0xA071EBAC : {
        KEEP(*(.text.HideEntriesCount))
    }
    .HideDateTime 0xA071EAAC : {
        KEEP(*(.text.HideDateTime))
    }

    .ShowHiddenFiles 0xA06982FC : {
        KEEP(*(.text.ShowHiddenFiles))
    }
    .ShowExtensions 0xA071E9D8 : {
        KEEP(*(.text.ShowExtensions))
    }

    .DisableSortFavoritesDirsOnTop 0xA06935AC : {
        KEEP(*(.text.DisableSortFavoritesDirsOnTop))
    }
    .DisableAliases_1 0xA071D264 : {
        KEEP(*(.text.DisableAliases_1))
    }
    .DisableAliases_2 0xA07135D0 : {
        KEEP(*(.text.DisableAliases_2))
    }

    .GetTotalDrives_Hook 0xA1380FBA : {
        KEEP(*(.text.GetTotalDrives_Hook))
    }
    .GetTotalDrives_Jump 0xA06994EC : {
        KEEP(*(.text.GetTotalDrives_Jump))
    }
    .FixTabs_Part1 0xA069966C : {
        KEEP(*(.text.FixTabs_Part1))
    }
    .FixTabs_Part2 0xA0699554 : {
        KEEP(*(.text.FixTabs_Part2))
    }
    .FixTabs_Part3 0xA0699674 : {
        KEEP(*(.text.FixTabs_Part3))
    }
    .SetSecondsTabPath 0xA1380700 : {
        KEEP(*(.text.SetSecondTabPath))
    }
    .SetSecondTabPath_Jump 0xA0699654 : {
        KEEP(*(.text.SetSecondTabPath_Jump))
    }
    .FixInitTab_Hook 0xA13806D0 : {
        KEEP(*(.text.FixInitTab_Hook))
    }
    .FixInitTab 0xA06993EC : {
        KEEP(*(.text.FixInitTab))
    }
    .FixMMCTabIcon 0xA0786044 : {
        KEEP(*(.text.FixMMCTabIcon))
    }
    .ShowDrives 0xA0698B1C : {
        KEEP(*(.text.ShowDrives))
    }

    .FixRenameFiles 0xA0715114 : {
        KEEP(*(.text.FixRenameFiles))
    }
    .RenameWithExt_Part1 0xA0714F28 : {
        KEEP(*(.text.RenameWithExt_Part1))
    }
    .RenameWithExt_Part2 0xA05D0988 : {
        KEEP(*(.text.RenameWithExt_Part2))
    }


    .FixCopyFiles 0xA0716470 : {
        KEEP(*(.text.FixCopyFiles))
    }
    .FixCopyMarkedDirs_Part1 0xA069B3F0 : {
        KEEP(*(.text.FixCopyMarkedDirs_Part1))
    }
    .FixCopyMarkedDirs_Part2 0xA0715DAC : {
        KEEP(*(.text.FixCopyMarkedDirs_Part2))
    }
    .FixCopyMarkedDirs_Part3 0xA0715D60 : {
        KEEP(*(.text.FixCopyMarkedDirs_Part3))
    }
    .FixCopyDirsAttributes_Hook 0xA1380C60 : {
        KEEP(*(.text.FixCopyDirsAttributes_Hook))
    }
    .FixCopyDirsAttributes_Jump 0xA0695800 : {
        KEEP(*(.text.FixCopyDirsAttributes_Jump))
    }

    .FixMoveSystemDirs 0xA0695F30 : {
        KEEP(*(.text.FixMoveSystemDirs))
    }

    .IsAllowPaste 0xA1380910 : {
        KEEP(*(.text.IsAllowPaste))
    }
    .IsAllowPaste_Jump 0xA07162FC : {
        KEEP(*(.text.IsAllowPaste_Jump))
    }


    .FixCopyFile_Hook 0xA13808DA : {
        KEEP(*(.text.FixCopyFile_Hook))
    }
    .FixCopyFile_Jump 0xA0716960 : {
        KEEP(*(.text.FixCopyFile_Jump))
    }
    .FixMoveFile_Hook 0xA1380620 : {
        KEEP(*(.text.FixMoveFile_Hook))
    }
    .FixMoveFile_Jump 0xA0716950 : {
        KEEP(*(.text.FixMoveFile_Jump))
    }
    .FixSendFile_Hook 0xA1380B8A : {
        KEEP(*(.text.FixSendFile_Hook))
    }
    .FixSendFile_Jump 0xA0716940 : {
        KEEP(*(.text.FixSendFile_Jump))
    }
    .FixSendFile 0xA069B1B0 : {
        KEEP(*(.text.FixSendFile))
    }
    .FixSortFiles_Hook 0xA1380B5A : {
       KEEP(*(.text.FixSortFiles_Hook))
    }
    .FixSortFiles_Jump 0xA07169B0 : {
        KEEP(*(.text.FixSortFiles_Jump))
    }
    .FixSetAsFile_Hook 0xA1380BF0 : {
        KEEP(*(.text.FixSetAsFile_Hook))
    }
    .FixSetAsFile_Jump 0xA0716A00 : {
        KEEP(*(.text.FixSetAsFile_Jump))
    }
    .FixRenameFile_Hook 0xA13808B0 : {
        KEEP(*(.text.FixRenameFile_Hook))
    }
    .FixRenameFile_Jump 0xA07169A0 : {
       KEEP(*(.text.FixRenameFile_Jump))
    }
    .FixDeleteFile_Hook 0xA1380B30 : {
       KEEP(*(.text.FixDeleteFile_Hook))
    }
    .FixDeleteFile_Jump 0xA0716980 : {
        KEEP(*(.text.FixDeleteFile_Jump))
    }
    .FixPaste_Part1 0xA069B508 : {
        KEEP(*(.text.FixPaste_Part1))
    }
    .FixPaste_Part2 0xA069B53C : {
        KEEP(*(.text.FixPaste_Part2))
    }
    .FixPaste_Part3 0xA069B54C :{
        KEEP(*(.text.FixPaste_Part3))
    }
    .FixPaste_Hook 0xA138096A : {
        KEEP(*(.text.FixPaste_Hook))
    }
    .FixPaste_Jump 0xA069B534 : {
        KEEP(*(.text.FixPaste_Jump))
    }
    .FixShowFileAttributes_Hook 0xA1380880 : {
        KEEP(*(.text.FixShowFileAttributes_Hook))
    }
    .FixShowFileAttributes_Jump 0xA069B860 : {
        KEEP(*(.text.FixShowFileAttributes_Jump))
    }
    .FixShowSearch 0xA069B97C : {
        KEEP(*(.text.FixShowSearch))
    }


    .FixHeader 0xA071EEE8 : {
        KEEP(*(.text.FixHeader))
    }
    .SetHeaderExtraLgpID 0xA088B784 : {
        KEEP(*(.text.SetHeaderExtraLgpID))
    }
    .SetHeaderExtra_Hook 0xA1380300 : {
        KEEP(*(.text.SetHeaderExtra_Hook))
    }
    .SetHeaderExtra_Jump 0xA06987EC : {
        KEEP(*(.text.SetHeaderExtra_Jump))
    }
    .FixSoftkeys_Hook 0xA13809F0: {
        KEEP(*(.text.FixSoftkeys_Hook))
    }
    .FixSoftkeys_Jump 0xA071DF1C : {
        KEEP(*(.text.FixSoftkeys_Jump))
    }


    .FixMenu4Dirs 0xA071CBD4 : {
        KEEP(*(.text.FixMenu4Dirs))
    }
    .FixMenu4MarkedDirs_Part1 0xA071B5C0 : {
        KEEP(*(.text.FixMenu4MarkedDirs_Part1))
    }
    .FixMenu4MarkedDirs_Part2 0xA071B5E4 : {
        KEEP(*(.text.FixMenu4MarkedDirs_Part2))
    }
    .FixMenuItem_Open_Part1 0xA071C5EC : {
        KEEP(*(.text.FixMenuItem_Open_Part1))
    }
    .FixMenuItem_Open_Part2 0xA071C6D4 : {
        KEEP(*(.text.FixMenuItem_Open_Part2))
    }
    .FixMenuItem_Open_Part3 0xA071C6E8 : {
        KEEP(*(.text.FixMenuItem_Open_Part3))
    }
    .FixMenuItem_Copy_Part1 0xA071CCF0 : {
        KEEP(*(.text.FixMenuItem_Copy_Part1))
    }
    .FixMenuItem_Copy_Part2 0xA071CC90 : {
        KEEP(*(.text.FixMenuItem_Copy_Part2))
    }
    .FixMenuItem_Send 0xA071CF08 : {
        KEEP(*(.text.FixMenuItem_Send))
    }
    .HideMenuItems_Part1 0xA071CAB8 : {
        KEEP(*(.text.HideMenuItems_Part1))
    }
    .HideMenuItems_Hook 0xA1380CB0 : {
        KEEP(*(.text.HideMenuItems_Hook))
    }
    .HideMenuItems_Jump1 0xA071CAC4 : {
        KEEP(*(.text.HideMenuItems_Jump1))
    }
    .HideMenuItems_Part2 0xA071B510 : {
        KEEP(*(.text.HideMenuItems_Part2))
    }
    .HideMenuItems_Jump2 0xA071B538 : {
        KEEP(*(.text.HideMenuItems_Jump2))
    }
    .HideMenuItems_Jump3 0xA071B874 : {
        KEEP(*(.text.HideMenuItems_Jump3))
    }

    .FixJavaDirs 0xA069AB04 : {
        KEEP(*(.text.FixJavaDirs))
    }
    /*.FixJavaDirs_Part2 0xA0718F58 : {
        KEEP(*(.text.FixJavaDirs_Part2))
    }*/
    .FixJavaDirIcon_Part1 0xA071E56C : {
        KEEP(*(.text.FixJavaDirIcon_Part1))
    }
    .FixJavaDirIcon_Part2 0xA0870A60 : {
        KEEP(*(.data.FixJavaDirIcon_Part2))
    }
    .FixRunJava 0xA09EEC7E : {
        KEEP(*(.text.FixRunJava))
    }
    .FixJavaAttributes 0xA069B7D4 : {
        KEEP(*(.text.FixJavaAttributes))
    }

    .FixDriveInfo 0xA069B8EC : {
        KEEP(*(.text.FixDriveInfo))
    }

    .FixPopupMessage 0xA069AF04 : {
        KEEP(*(.text.FixPopupMessage))
    }
    .FixPopupLgpID 0xA069B1DC : {
        KEEP(*(.data.FixPopupLgpID))
    }
    .DisablePleaseWait 0xA069A688 : {
        KEEP(*(.text.DisablePleaseWait))
    }
    .DisableCopyMoveMessage 0xA0715EBC : {
        KEEP(*(.text.DisableCopyMoveMessage))
    }
    .DisableMemoryAssistantSoftkey 0xA0870318 : {
        KEEP(*(.data.DisableMemoryAssistantSoftkey))
    }

    .FixMemoryLeak_2 0xA0786408 : {
        KEEP(*(.text.FixMemoryLeak_2))
    }
    .SkipFindChildren 0xA069445C : {
        KEEP(*(.text.SkipFindChildren))
    }
    .SkipApplicationError 0xA0698C70 : {
        KEEP(*(.text.SkipApplicationError))
    }

    .ChangeOnKey 0xA088B6FC : {
        KEEP(*(.data.ChangeOnKey))
    }
    .DisabledCMD_Default 0xA1380A50 : {
        KEEP(*(.data.DisabledCMD_Default))
    }
    .DisabledCMD_Mark 0xA1380A60 : {
        KEEP(*(.data.DisabledCMD_Mark))
    }
    .DisabledCMD_CopyMove 0xA1380A70 : {
        KEEP(*(.data.DisabledCMD_CopyMove))
    }
    .KeyHook 0xA1380A80 : {
        KEEP(*(.text.KeyHook))
    }

    .Rename_SkipFindChildren 0xA0714FB8 : {
        KEEP(*(.text.Rename_SkipFindChildren))
    }

    .ReplaceHelpMenuItem 0xA07168A8 : {
        KEEP(*(.text.ReplaceHelpMenuItem))
    }
    .RenameHelpMenuItem 0xA08704F4 : {
        KEEP(*(.data.RenameHelpMenuItem))
    }
    .5461_FixHeader 0xA084CB7C : {
        KEEP(*(.text.5461_FixHeader))
    }
    .5461_ChangeItemsCount 0xA0698978 : {
        KEEP(*(.text.5461_ChangeItemsCount))
    }
    .5461_RemoveCombination 0xA071DCC0 : {
        KEEP(*(.text.5461_RemoveCombination))
    }
    .5461_SetUserPointer 0xA0698974 : {
        KEEP(*(.text.5461_SetUserPointer))
    }
    .5461_OnKey 0xA1380200 : {
        KEEP(*(.text.5461_OnKey))
    }
    .5461_OnKey_Jump 0xA084CB88 : {
        KEEP(*(.data.5461_OnKey_Jump))
    }
    .5461_GHook 0xA13802A0 : {
        KEEP(*(.text.5461_GHook))
    }
    .5461_GHook_Jump 0xA084CB8C : {
        KEEP(*(.data.5461_GHook_Jump))
    }

    .Search_OnMessage_Hook 0xA1380D40 : {
        KEEP(*(.text.Search_OnMessage_Hook))
    }
    .Search_OnMessage_Jump 0xA087002C : {
        KEEP(*(.data.Search_OnMessage_Jump))
    }

    .Search_OnKey_Hook 0xA1380DD0 : {
        KEEP(*(.text.Search_OnKey_Hook))
    }
    .Search_OnKey_Jump 0xA088B538 : {
        KEEP(*(.data.Search_OnKey_Jump))
    }

    .Search_GHook_Hook 0xA1380F30 : {
        KEEP(*(.text.Search_GHook_Hook))
    }
    .Search_GHook_Jump 0xA088B53C : {
        KEEP(*(.data.Search_GHook_Jump))
    }

    .Search_FixCSMState 0xA0711F90 : {
        KEEP(*(.text.Search_FixCSMState))
    }

    .Search_FixHeaderIcon 0xA088B6CC : {
        KEEP(*(.data.Search_FixHeaderIcon))
    }
    .Search_ChangeHeader_Part1 0xA088B52C : {
        KEEP(*(.data.Search_ChangeHeader_Part1))
    }
    .Search_ChangeHeader_Part2 0xA07857DD : {
        KEEP(*(.data.Search_ChangeHeader_Part2))
    }
    .Search_ChangeHeader_Part3 0xA07857B0 : {
        KEEP(*(.text.Search_ChangeHeader_Part3))
    }

    .Search_Everywhere_Part1 0xA071245C : {
        KEEP(*(.text.Search_Everywhere_Part1))
    }
    .Search_Everywhere_Part2 0xA071246C : {
        KEEP(*(.text.Search_Everywhere_Part2))
    }
    .Search_Everywhere_Part3 0xA0710EF4 : {
        KEEP(*(.text.Search_Everywhere_Part3))
    }
    .Search_Everywhere_Part4 0xA0710CFC : {
        KEEP(*(.text.Search_Everywhere_Part4))
    }

    .Search_SetItemIcon_Hook 0xA1380EB0 : {
        KEEP(*(.text.Search_SetItemIcon_Hook))
    }
    .Search_SetItemIcon_Jump 0xA0785770 : {
        KEEP(*(.text.Search_SetItemIcon_Jump))
    }

    .Search_FixJavaAttributes 0xA0711680 : {
        KEEP(*(.text.Search_FixJavaAttributes))
    }

    .Search_FixGoTo_Part1 0xA071186C : {
        KEEP(*(.text.Search_FixGoTo_Part1))
    }
    .Search_FixGoTo_Part2 0xA07118BC : {
        KEEP(*(.text.Search_FixGoTo_Part2))
    }
    .Search_FixGoTo_Hook 0xA1381080 : {
        KEEP(*(.text.Search_FixGoTo_Hook))
    }
    .Search_FixGoTo_Jump 0xA07118A8 : {
        KEEP(*(.text.Search_FixGoTo_Jump))
    }

    .Search_Options_FixMenu 0xA088B66C : {
        KEEP(*(.data.Search_Options_FixMenu))
    }
    .Search_Options_FixMenu_Hook 0xA1380D50 : {
        KEEP(*(.text.Search_Options_FixMenu_Hook))
    }
    .Search_Options_FixMenu_Jump 0xA0785E6C : {
        KEEP(*(.text.Search_Options_FixMenu_Jump))
    }

    .Search_Options_HideItems_Hook 0xA1380E70 : {
        KEEP(*(.text.Search_Options_HideItems_Hook))
    }
    .Search_Options_HideItems_Jump 0xA0785E48 : {
        KEEP(*(.text.Search_Options_HideItems_Jump))
    }

    .Search_Options_FixItemOpen_Part1 0xA0785BC0 : {
        KEEP(*(.text.Search_Options_FixItemOpen_Part1))
    }
    .Search_Options_FixItemOpen_Part2 0xA0785BD4 : {
        KEEP(*(.text.Search_Options_FixItemOpen_Part2))
    }
}
