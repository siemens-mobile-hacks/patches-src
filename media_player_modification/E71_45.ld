SECTIONS {
    .rodata 0xA13818A0 : {
        KEEP(*(.rodata*))
    }

    .DisableBacklightFadeHandler 0xA07A5010 : {
        KEEP(*(.text.DisableBacklightFadeHandler))
    }

    .StoreLastPlayMelodyOnChangeTrack 0xA0792A04 : {
        KEEP(*(.text.StoreLastPlayMelodyOnChangeTrack))
    }

    .DisableAutoPlayInMenu_Part1 0xA079D584 : {
        KEEP(*(.text.DisableAutoPlayInMenu_Part1))
    }
    .DisableAutoPlayInMenu_Part2 0xA078BB5C : {
        KEEP(*(.text.DisableAutoPlayInMenu_Part2))
    }

    .SetAnimationViewMode 0xA078B974 : {
        KEEP(*(.text.SetAnimationViewMode))
    }

    .FastSwitch_Part1 0xA079056C : {
        KEEP(*(.text.FastSwitch_Part1))
    }
    .FastSwitch_Part2 0xA0792A20 : {
        KEEP(*(.text.FastSwitch_Part2))
    }
    .FastSwitch_Part3 0xA078AABC : {
        KEEP(*(.text.FastSwitch_Part3))
    }
    .FastSwitch_Part4 0xA078B0D8 : {
        KEEP(*(.text.FastSwitch_Part4))
    }

    .ChangeVolumeWhenKbdIsLocked 0xA0796AA8 : {
        KEEP(*(.text.ChangeVolumeWhenKbdIsLocked))
    }
    .DisableHideWhenKbdIsLocked 0xA072B31C : {
        KEEP(*(.text.DisableHideWhenKbdIsLocked))
    }

    .FixSelectPlaylist 0xA07CDA58 : {
        KEEP(*(.text.FixSelectPlaylist))
    }

    .DisableMessage_AddTracksToPlaylist 0xA07EE598 : {
        KEEP(*(.text.DisableMessage_AddTracksToPlaylist))
    }

    .PlayProc 0xA13818EA : {
        KEEP(*(.text.PlayProc))
    }
    .HideListProc 0xA138193A : {
        KEEP(*(.text.HideListProc))
    }

    .InitData 0xA1381E30 : {
        KEEP(*(.text.InitData))
    }
    .InitData_Jump 0xA072C570 : {
        KEEP(*(.text.InitData_Jump))
    }
    .DestroyData 0xA1381E60 : {
        KEEP(*(.text.DestroyData))
    }
    .DestroyData_Jump 0xA072C36C : {
        KEEP(*(.text.DestroyData_Jump))
    }

    .OnKey 0xA138194C : {
        KEEP(*(.text.OnKey))
    }
    .OnKey_Jump 0xA088B8EC : {
        KEEP(*(.data.OnKey_Jump))
    }

    .GHook 0xA1381B70 : {
        KEEP(*(.text.GHook))
    }
    .GHook_Jump 0xA088B8F0 : {
        KEEP(*(.data.GHook_Jump))
    }

    .BaseOnRedraw_Hook 0xA1381C10 : {
        KEEP(*(.text.BaseOnRedraw_Hook))
    }
    .BaseOnRedraw_Jump 0xA079F808 : {
        KEEP(*(.text.BaseOnRedraw_Jump))
    }

    .SetHeaderToListView 0xA1381D00 : {
        KEEP(*(.text.SetHeaderToListView))
    }
    .SetHeaderToListView_Jump 0xA079D0E0 : {
        KEEP(*(.text.SetHeaderToListView_Jump))
    }
    .SetHeaderToAnimationView 0xA1381D50 : {
        KEEP(*(.text.SetHeaderToAnimationView))
    }
    .SetHeaderToAnimationView_Jump 0xA079CF48 : {
        KEEP(*(.text.SetHeaderToAnimationView_Jump))
    }
    .SetHeaderScrollText_Hook 0xA1381DA0 : {
        KEEP(*(.text.SetHeaderScrollText_Hook))
    }
    .SetHeaderScrollText_Jump 0xA078BBA4 : {
        KEEP(*(.text.SetHeaderScrollText_Jump))
    }

    .ChangeTrackName 0xA1381DDA : {
        KEEP(*(.text.ChangeTrackName))
    }
    .ChangeTrackName_Jump 0xA07A0768 : {
        KEEP(*(.text.ChangeTrackName_Jump))
    }

    .ID3v2_GetIMGHDRFromPICFrame 0xA1381F00 : {
        KEEP(*(.text.ID3v2_GetIMGHDRFromPICFrame))
    }
    .ID3v2_ReadCover 0xA1382270 : {
        KEEP(*(.text.ID3v2_ReadCover))
    }
    .ID3v2_ReadCover_Jump 0xA0792280 : {
        KEEP(*(.text.ID3v2_ReadCover_Jump))
    }

    .DrawCover 0xA1382600 : {
        KEEP(*(.text.DrawCover))
    }
    .DrawCover_Jump_1 0xA079F6AC : {
        KEEP(*(.text.DrawCover_Jump_1))
    }
    .DrawCover_Jump_2 0xA079F92C : {
        KEEP(*(.text.DrawCover_Jump_2))
    }

    .DisableVisualizerBG 0xA079E528 : {
        KEEP(*(.text.DisableVisualizerBG))
    }
    .DrawVisualizer_Hook 0xA13827E0 : {
        KEEP(*(.text.DrawVisualizer_Hook))
    }
    .DrawVisualizer_Jump 0xA079E61C : {
        KEEP(*(.text.DrawVisualizer_Jump))
    }

    .DrawResolution 0xA1382900 : {
        KEEP(*(.text.DrawResolution))
    }
    .DrawResolution_Jump 0xA079F9B0 : {
        KEEP(*(.text.DrawResolution_Jump))
    }

    .Zoom_DisableSoftKeys_Part_1 0xA079F8CC : {
        KEEP(*(.text.Zoom_DisableSoftKeys_Part_1))
    }

    .Zoom_DisableSoftKeys_Part_2 0xA08AF4E4 : {
        KEEP(*(.data.Zoom_DisableSoftKeys_Part_2))
    }
    .Zoom_DisableSoftKeys_Part_3 0xA08AF500 : {
        KEEP(*(.data.Zoom_DisableSoftKeys_Part_3))
    }

    .Options_GoTo 0xA1382BB0 : {
        KEEP(*(.text.Options_GoTo))
    }
    .Options_ReplaceAttributes_Part1 0xA08AF24C : {
        KEEP(*(.data.Options_ReplaceAttributes_Part1))
    }
    .Options_ReplaceAttributes_Part2 0xA07CC398 : {
        KEEP(*(.text.Options_ReplaceAttributes_Part2))
     }
    .Options_RemoveHelpItem 0xA08AF394 : {
        KEEP(*(.data.Options_RemoveHelpItem))
    }

    .MDB_IsAllowFile 0xA1382750 : {
        KEEP(*(.text.MDB_IsAllowFile))
    }
    .MDB_IsAllowFile_Jump 0xA0725C30 : {
        KEEP(*(.text.MDB_IsAllowFile_Jump))
    }
    .MDB_FixUI_Hook 0xA1382B90 : {
        KEEP(*(.text.MDB_FixUI_Hook))
    }
    .MDB_FixUI_Jump 0xA079A930 : {
        KEEP(*(.text.MDB_FixUI_Jump))
    }
    .MDB_UseSmallIcons 0xA0730928 : {
        KEEP(*(.text.MDB_UseSmallIcons))
    }
    .MDB_FixPreviewSize 0xA079A030 : {
        KEEP(*(.text.MDB_FixPreviewSize))
    }

    .MDB_Options_ReplaceAttributes_Part1 0xA08AA774 : {
        KEEP(*(.data.MDB_Options_ReplaceAttributes_Part1))
    }
    .MDB_Options_ReplaceAttributes_Part2 0xA0799908 : {
        KEEP(*(.text.MDB_Options_ReplaceAttributes_Part2))
    }
    .MDB_Options_RemoveHelpItem 0xA08AA7C0 : {
        KEEP(*(.data.MDB_Options_RemoveHelpItem))
    }
}
