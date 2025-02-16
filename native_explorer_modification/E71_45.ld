SECTIONS {
    .rodata 0xA1380600 : {
        KEEP(*(.rodata*))
    }

    .Replace_GetMultiLinesMenuGUI 0xA0785F60 : {
        KEEP(*(.text.Replace_GetMultiLinesMenuGUI))
    }
    .Replace_AllocMLMenuItem 0xA071E17C : {
        KEEP(*(.text.Replace_AllocMLMenuItem))
    }
    .FixMemoryLeak_1 0xA071E1D8 : {
        KEEP(*(.text.FixMemoryLeak_1))
    }
    .Replace_GetExtIconLarge_1 0xA071E5B4 : {
        KEEP(*(.text.Replace_GetExtIconLarge_1))
    }
    .Replace_GetExtIconLarge_2 0xA071E570 : {
        KEEP(*(.text.Replace_GetExtIconLarge_2))
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

    .FixTabs_Part1 0xA04E57BC : {
        KEEP(*(.text.FixTabs_Part1))
    }
    .FixTabs_Part2 0xA069966C : {
        KEEP(*(.text.FixTabs_Part2))
    }
    .FixTabs_Part3 0xA0699554 : {
        KEEP(*(.text.FixTabs_Part3))
    }
    .FixTabs_Part4 0xA0699674 : {
        KEEP(*(.text.FixTabs_Part4))
    }
    .Set2ndTabPath 0xA1380700 : {
        KEEP(*(.text.Set2ndTabPath))
    }
    .Set2ndTabPath_Jump 0xA0699654 : {
        KEEP(*(.text.Set2ndTabPath_Jump))
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


    .FixDeleteROFiles_Part1 0xA05D0F00 : {
        KEEP(*(.text.FixDeleteROFiles_Part1))
    }
    .FixDeleteROFiles_Part2 0xA0694F28 : {
        KEEP(*(.text.FixDeleteROFiles_Part2))
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


    .FixHeader 0xA071EEE8 : {
        KEEP(*(.text.FixHeader))
    }
    .SetHeaderExtraLgpID 0xA088B784 : {
        KEEP(*(.text.SetHeaderExtraLgpID))
    }
    .SetHeaderExtra_Hook 0xA1380720 : {
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
    .FixMenuItem_Open 0xA071C5EC : {
        KEEP(*(.text.FixMenuItem_Open))
    }
    .FixMenuItem_Copy_Part1 0xA071CCF0 : {
        KEEP(*(.text.FixMenuItem_Copy_Part1))
    }
    .FixMenuItem_Copy_Part2 0xA071CC90 : {
        KEEP(*(.text.FixMenuItem_Copy_Part2))
    }
    .HideMenuItems_Part1 0xA071CAB8 : {
        KEEP(*(.text.HideMenuItems_Part1))
    }
    .HideMenuItems_Hook 0xA138087A : {
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

    .FixMemoryLeak_2 0xA0786408 : {
        KEEP(*(.text.FixMemoryLeak_2))
    }
    .SkipFindChildren 0xA069445C : {
        KEEP(*(.text.SkipFindChildren))
    }
    .SkipApplicationError 0xA0698C70 : {
        KEEP(*(.text.SkipApplicationError))
    }
    .DisableSearch 0xA069B950 : {
        KEEP(*(.text.DisableSearch))
    }


    .ReplaceHelpMenuItem_Part1 0xA07168A8 : {
        KEEP(*(.text.ReplaceHelpMenuItem_Part1))
    }
    .ReplaceHelpMenuItem_Part2 0xA08704F4 : {
        KEEP(*(.data.ReplaceHelpMenuItem_Part2))
    }
    .Fix5461MenuHeader 0xA084CB7C : {
        KEEP(*(.text.Fix5461MenuHeader))
    }
    .RemoveDrivesItemFrom5461Menu_Part1 0xA0698978 : {
        KEEP(*(.text.RemoveDrivesItemFrom5461Menu_Part1))
    }
    .RemoveDrivesItemFrom5461Menu_Part2 0xA0698954 : {
        KEEP(*(.text.RemoveDrivesItemFrom5461Menu_Part2))
    }
    .Remove5461Combination 0xA071DCC0 : {
        KEEP(*(.text.Remove5461Combination))
    }

    .DisableFastSearch 0xA088B710 : {
        KEEP(*(.data.DisableFastSearch))
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
}
