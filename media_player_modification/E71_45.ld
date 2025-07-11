SECTIONS {
    .rodata 0xA13818A0 : {
        KEEP(*(.rodata*))
    }

    .DisableBacklightFadeHandler 0xA07A5010 : {
        KEEP(*(.text.DisableBacklightFadeHandler))
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

    .PlayProc 0xA13818EA : {
        KEEP(*(.text.PlayProc))
    }
    .HideListProc 0xA1381950 : {
        KEEP(*(.text.HideListProc))
    }

    .AllocData 0xA13822D0 : {
        KEEP(*(.text.AllocData))
    }
    .AllocData_Jump 0xA072C570 : {
        KEEP(*(.text.AllocData_Jump))
    }
    .FreeData 0xA13822F0 : {
        KEEP(*(.text.FreeData))
    }
    .FreeData_Jump 0xA072C36C : {
        KEEP(*(.text.FreeData_Jump))
    }

    .OnKey 0xA1381970 : {
        KEEP(*(.text.OnKey))
    }
    .OnKey_Jump 0xA088B8EC : {
        KEEP(*(.data.OnKey_Jump))
    }

    .GHook 0xA1381B50 : {
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

    .ID3v2_ReadCover 0xA1381E30 : {
        KEEP(*(.text.ID3v2_ReadCover))
    }
    .ID3v2_ReadCover_Jump 0xA0792280 : {
        KEEP(*(.text.ID3v2_ReadCover_Jump))
    }
    .DrawCover 0xA1382200 : {
        KEEP(*(.text.DrawCover))
    }
    .DrawCover_Jump_1 0xA079F6AC : {
        KEEP(*(.text.DrawCover_Jump_1))
    }
    .DrawCover_Jump_2 0xA079F92C : {
        KEEP(*(.text.DrawCover_Jump_2))
    }
}
