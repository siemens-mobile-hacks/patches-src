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
    .MergeIconsHook 0xA1380650 : {
        KEEP(*(.text.MergeIconsHook))
    }
    .MergeIconsHook_AddParam 0xA0719BBC : {
        KEEP(*(.text.MergeIconsHook_AddParam))
    }
    .MergeIconsHook_Jump 0xA0719BC8 : {
        KEEP(*(.text.MergeIconsHook_Jump))
    }
    .SetPreviewHook 0xA13806A0 : {
        KEEP(*(.text.SetPreviewHook))
    }
    .SetPreviewHook_Jump 0xA0719580 : {
        KEEP(*(.text.SetPreviewHook_Jump))
    }

    .ShowHiddenFiles_Part1 0xA0694024 : {
        KEEP(*(.text.ShowHiddenFiles_Part1))
    }
    .ShowHiddenFiles_Part2 0xA069412C : {
        KEEP(*(.text.ShowHiddenFiles_Part2))
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
    .FixInitTabHook 0xA13806D0 : {
        KEEP(*(.text.FixInitTabHook))
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
    .FixCopyMarkedDirs 0xA0715D60 : {
        KEEP(*(.text.FixCopyMarkedDirs))
    }
    .FixDeleteROFiles_Part1 0xA05D0F00 : {
        KEEP(*(.text.FixDeleteROFiles_Part1))
    }
    .FixDeleteROFiles_Part2 0xA0694F28 : {
        KEEP(*(.text.FixDeleteROFiles_Part2))
    }

    .FixHeader 0xA071EEE8 : {
        KEEP(*(.text.FixHeader))
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
    .FixMenuItem_Copy 0xA071CCF0 : {
        KEEP(*(.text.FixMenuItem_Copy))
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

    .FixMemoryLeak_2 0xA0786408 : {
        KEEP(*(.text.FixMemoryLeak_2))
    }
    .SkipFindChildren 0xA069445C : {
        KEEP(*(.text.SkipFindChildren))
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
}
