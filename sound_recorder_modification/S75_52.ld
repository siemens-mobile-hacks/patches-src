SECTIONS {
    .List_OnClose_Hook 0xA1482050 : {
        KEEP(*(.text.List_OnClose_Hook))
    }
    .List_OnClose_Jump 0xA08CB81C : {
        KEEP(*(.data.List_OnClose_Jump))
    }
    .List_GHook_Hook 0xA14821A0 : {
        KEEP(*(.text.List_GHook_Hook))
    }
    .List_GHook_Jump 0xA08DD894 : {
        KEEP(*(.data.List_GHook_Jump))
    }

    .Recording_FixPBarPosition 0xA08DDAC4 : {
        KEEP(*(.data.Recording_FixPBarPosition))
    }
    .Recording_FixAnimationPosition 0xA0654C6C : {
        KEEP(*(.text.Recording_FixAnimationPosition))
    }
    .Recording_FixFinishedTextPosition 0xA08DDAA8 : {
        KEEP(*(.data.Recording_FixFinishedTextPosition))
    }

    .Recording_ChangeAnimationSpeed 0xA0654C98 : {
        KEEP(*(.text.Recording_ChangeAnimationSpeed))
    }

    .Recording_DrawWidgetWithBG 0xA1482080 : {
        KEEP(*(.text.Recording_DrawWidgetWithBG))
    }
    .Recording_FixRedraw_Hook 0xA14820D0 : {
        KEEP(*(.text.Recording_FixRedraw_Hook))
    }
    .Recording_FixRedraw_Trampoline 0xA0604514 : {
        KEEP(*(.text.Recording_FixRedraw_Trampoline))
    }
    .Recording_FixRedraw_Jump 0xA0604BFE : {
        KEEP(*(.text.Recording_FixRedraw_Jump))
    }
    .Recording_FixRedraw_Part2 0xA0604C60 : {
        KEEP(*(.text.Recording_FixRedraw_Part2))
    }
    .Recording_FixRedraw_Part3 0xA0654CA2 : {
        KEEP(*(.text.Recording_FixRedraw_Part3))
    }
    .Recording_FixRedraw_Part4 0xA0604D80 : {
        KEEP(*(.data.Recording_FixRedraw_Part4))
    }
    .Recording_FixRedraw_Part5 0xA0604950 : {
        KEEP(*(.data.Recording_FixRedraw_Part5))
    }

    .Recording_FixClose 0xA0604E0E : {
        KEEP(*(.text.Recording_FixClose))
    }
    .Recording_SaveOnClose_Part1 0xA0604BEA : {
        KEEP(*(.text.Recording_SaveOnClose_Part1))
    }
    .Recording_SaveOnClose_Part2 0xA0604D02 : {
        KEEP(*(.text.Recording_SaveOnClose_Part2))
    }

    .Recording_ChangeText_Part1 0xA062D3DA : {
        KEEP(*(.text.Recording_ChangeText_Part1))
    }
    .Recording_ChangeText_Hook 0xA0605230 : {
        KEEP(*(.text.Recording_ChangeText_Hook))
    }
    .Recording_ChangeText_Jump 0xA06047B6 : {
        KEEP(*(.text.Recording_ChangeText_Jump))
    }

    .Options_GoTo 0xA1482120 : {
        KEEP(*(.text.Options_GoTo))
    }
    .Options_ReplaceRename_Part1_Trampoline 0xA0602290 : {
        KEEP(*(.text.Options_ReplaceRename_Part1_Trampoline))
    }
    .Options_ReplaceRename_Part1_Jump 0xA062CA2E : {
        KEEP(*(.text.Options_ReplaceRename_Part1_Jump))
    }
    .Options_ReplaceRename_Part2 0xA08E24B8 : {
        KEEP(*(.data.Options_ReplaceRename_Part2))
    }
}
