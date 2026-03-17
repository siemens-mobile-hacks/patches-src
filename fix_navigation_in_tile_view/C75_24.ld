SECTIONS {
    .FixNavigationInTileView_Part1 0xA08E57BA : {
        KEEP(*(.text.FixNavigationInTileView_Part1))
    }
    .FixNavigationInTileView_Part2 0xA08E5854 : {
        KEEP(*(.text.FixNavigationInTileView_Part2))
    }
    .FixNavigationInTileView_Part3 0xA08E58F6 : {
        KEEP(*(.text.FixNavigationInTileView_Part3))
    }
    .FixNavigationInTileView_Part4 0xA08E598A : {
        KEEP(*(.text.FixNavigationInTileView_Part4))
    }

    .FixNavigationInCardExplorer_Hook 0xA0F22290 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.FixNavigationInCardExplorer_Hook))
    }
    .FixNavigationInCardExplorer_Jump 0xA034BEC0 : {
        KEEP(*(.text.FixNavigationInCardExplorer_Jump))
    }

    .FixLongPress_Hook 0xA0870204 : {
        KEEP(*(.text.FixLongPress_Hook))
    }
    .FixLongPress_Jump 0xA08E5A16 : {
        KEEP(*(.text.FixLongPress_Jump))
    }

    .FixCursorPosition 0xA08E53A0 : {
        KEEP(*(.text.FixCursorPosition))
    }
}
