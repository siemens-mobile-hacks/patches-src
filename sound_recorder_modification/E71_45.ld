SECTIONS {
    .List_OnClose_Hook 0xA1382050 : {
        KEEP(*(.text.List_OnClose_Hook))
    }
    .List_OnClose_Jump 0xA088ED14 : {
        KEEP(*(.data.List_OnClose_Jump))
    }
    .List_GHook_Hook 0xA13821A0 : {
        KEEP(*(.text.List_GHook_Hook))
    }
    .List_GHook_Jump 0xA08AA9EC : {
        KEEP(*(.data.List_GHook_Jump))
    }

    .Recording_FixPBarPosition 0xA08AAC1C : {
        KEEP(*(.data.Recording_FixPBarPosition))
    }
    .Recording_FixElapsedTimePosition 0xA08AABCC : {
        KEEP(*(.data.Recording_FixElapsedTimePosition))
    }
    .Recording_FixTotalTimePosition 0xA08AABE4 : {
        KEEP(*(.data.Recording_FixTotalTimePosition))
    }

    .Recording_ChangeAnimationSpeed 0xA07EEBE4 : {
        KEEP(*(.text.Recording_ChangeAnimationSpeed))
    }

    .Recording_DrawWidgetWithBG 0xA1382080 : {
        KEEP(*(.text.Recording_DrawWidgetWithBG))
    }
    .Recording_FixRedraw_Hook 0xA13820D0 : {
        KEEP(*(.text.Recording_FixRedraw_Hook))
    }
    .Recording_FixRedraw_Jump 0xA07AAC14 : {
        KEEP(*(.text.Recording_FixRedraw_Jump))
    }
    .Recording_FixRedraw_Part2 0xA07AACAC : {
        KEEP(*(.text.Recording_FixRedraw_Part2))
    }
    .Recording_FixRedraw_Part3 0xA07FF288 : {
        KEEP(*(.data.Recording_FixRedraw_Part3))
    }
    .Recording_FixRedraw_Part4 0xA07AA5B4 : {
        KEEP(*(.data.Recording_FixRedraw_Part4))
    }
    .Recording_FixRedraw_Part5 0xA07AACE0 : {
        KEEP(*(.data.Recording_FixRedraw_Part5))
    }

    .Recording_FixClose 0xA07AAF2C : {
        KEEP(*(.text.Recording_FixClose))
    }
    .Recording_SaveOnClose_Part1 0xA07AABFC : {
        KEEP(*(.text.Recording_SaveOnClose_Part1))
    }
    .Recording_SaveOnClose_Part2 0xA07AB45C : {
        KEEP(*(.text.Recording_SaveOnClose_Part2))
    }

    .Recording_ChangeText_Part1 0xA07D18F8 : {
        KEEP(*(.text.Recording_ChangeText_Part1))
    }
    .Recording_ChangeText_Hook 0xA1382120 : {
        KEEP(*(.text.Recording_ChangeText_Hook))
    }
    .Recording_ChangeText_Jump 0xA07AA5A0 : {
        KEEP(*(.text.Recording_ChangeText_Jump))
    }

    .Options_GoTo 0xA1382150 : {
        KEEP(*(.text.Options_GoTo))
    }
    .Options_ReplaceRename_Part1 0xA07D09A8 : {
        KEEP(*(.text.Options_ReplaceRename_Part1))
    }
    .Options_ReplaceRename_Part2 0xA08AF6B8 : {
        KEEP(*(.data.Options_ReplaceRename_Part2))
    }
}
