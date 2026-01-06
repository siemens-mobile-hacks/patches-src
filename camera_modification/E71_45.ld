SECTIONS {
    .rodata 0xA13830A0 : {
        KEEP(*(.rodata*))
    }
    .Functions 0xA13830D0 : {
        KEEP(*(.text.SetResolution_ws))
    }

    .SetResolutionString_Hook 0xA13831A0 : {
        KEEP(*(.text.SetResolutionString_Hook))
    }
    .SetResolutionString_Jump 0xA067C104 : {
        KEEP(*(.text.SetResolutionString_Jump))
    }

    .StartViewFinder_Hook 0xA1383220 : {
        KEEP(*(.text.StartViewFinder_Hook))
    }
    .StartViewFinder_Jump 0xA067B744 : {
        KEEP(*(.text.StartViewFinder_Jump))
    }
    .SkipSetPosition_Part1 0xA0783F6C : {
        KEEP(*(.text.SkipSetPosition_Part1))
    }
    .SkipSetPosition_Part2 0xA0783FDC : {
        KEEP(*(.text.SkipSetPosition_Part2))
    }
    .FixStoreCoordinates_Hook 0xA1383300 : {
        KEEP(*(.text.FixStoreCoordinates_Hook))
    }
    .FixStoreCoordinates_Jump 0xA0784130 : {
        KEEP(*(.text.FixStoreCoordinates_Jump))
    }

    .ChangePhotoResolution_1 0xA084BFCC : {
        KEEP(*(.data.ChangePhotoResolution_1))
    }
    .ChangePhotoResolution_2 0xA084BFC0 : {
        KEEP(*(.data.ChangePhotoResolution_2))
    }
    .ChangePhotoResolution_3 0xA084BFB4 : {
        KEEP(*(.data.ChangePhotoResolution_3))
    }
    .ChangeJPEGQuality 0xA0D0C4B4 : {
        KEEP(*(.text.ChangeJPEGQuality))
    }
    .SpeedUpViewFinder 0xA0A05E1C : {
        KEEP(*(.text.SpeedUpViewFinder))
    }

    .FixHeaderText 0xA07086A8 : {
        KEEP(*(.data.FixHeaderText))
    }
    .SetHeaderLgp_Hook 0xA1383340 : {
        KEEP(*(.text.SetHeaderLgp_Hook))
    }
    .SetHeaderLgp_Jump 0xA07080EC : {
        KEEP(*(.text.SetHeaderLgp_Jump))
    }

    .OnRedraw_Hook 0xA13833F0 : {
        KEEP(*(.text.OnRedraw_Hook))
    }
    .OnRedraw_Jump 0xA07840BC : {
        KEEP(*(.text.OnRedraw_Jump))
    }
    .DisableZoomIcons 0xA078439C : {
        KEEP(*(.text.DisableZoomIcons))
    }
    .DisableRemainingPhotos 0xA07841FC : {
        KEEP(*(.text.DisableRemainingPhotos))
    }
    .ChangeInfoTextColor_Part1 0xA0784488 : {
        KEEP(*(.text.ChangeInfoTextColor_Part1))
    }
    .ChangeInfoTextColor_Part2 0xA0784494 : {
        KEEP(*(.text.ChangeInfoTextColor_Part2))
    }
    .DisableSelfTimer 0xA0784540 : {
        KEEP(*(.text.DisableSelfTimer))
    }
    .OnKey_Hook 0xA1383510 : {
        KEEP(*(.text.OnKey_Hook))
    }
    .OnKey_Jump 0xA086F230 : {
        KEEP(*(.data.OnKey_Jump))
    }
    .GHook 0xA1383700 : {
        KEEP(*(.text.GHook))
    }
    .GHook_Jump 0xA086F234 : {
        KEEP(*(.data.GHook_Jump))
    }
    .SyncSettings 0xA1383740 : {
        KEEP(*(.text.SetSettings_Hook))
        KEEP(*(.text.SetWhiteBalance_Hook))
    }
    .SetSettings_Jump 0xA0706278 : {
        KEEP(*(.text.SetSettings_Jump))
    }
    .SetWhiteBalance_Jump 0xA0706C34 : {
        KEEP(*(.text.SetWhiteBalance_Jump))
    }

    .DisableMessageSavedTo 0xA070818C : {
        KEEP(*(.text.DisableMessageSavedTo))
    }
    .DisableMessageInsufficientMemoryAvailable 0xA0708180 : {
        KEEP(*(.text.DisableMessageInsufficientMemoryAvailable))
    }

    .ChangeFileName_Hook 0xA138349A : {
        KEEP(*(.text.ChangeFileName_Hook))
    }
    .ChangeFileName_Jump 0xA0678278 : {
        KEEP(*(.text.ChangeFileName_Jump))
    }

    .Options_DisableMessages 0xA0706964 : {
        KEEP(*(.text.Options_DisableMessages))
    }
    .Options_Active_RemoveItemHelp_Part1 0xA07089D4 : {
        KEEP(*(.text.Options_Active_RemoveItemHelp_Part1))
    }
    .Options_Active_RemoveItemHelp_Part2 0xA07089DC : {
        KEEP(*(.text.Options_Active_RemoveItemHelp_Part2))
    }
    .Options_Idle_FixItemPictures 0xA086F8C4 : {
        KEEP(*(.data.Options_Idle_FixItemPictures))
    }
    .Options_Idle_FixItemOtherVideos 0xA086F8E0 : {
        KEEP(*(.data.Options_Idle_FixItemOtherVideos))
    }
    .Options_Idle_RemoveItemHelp 0xA086F910 : {
        KEEP(*(.data.Options_Idle_RemoveItemHelp))
    }

    .Settings_RemoveItemDefaultName 0xA0709AB8 : {
        KEEP(*(.text.Settings_RemoveItemDefaultName))
    }
    .Settings_SetResolution_Hook 0xA13831F0 : {
        KEEP(*(.text.Settings_SetResolution_Hook))
    }
    .Settings_SetResolution_Jump 0xA0708E14 : {
        KEEP(*(.text.Settings_SetResolution_Jump))
    }
}
