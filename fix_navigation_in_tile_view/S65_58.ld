SECTIONS {
    .FixNavigationInTileView_Part1 0xA119E686 : {
        KEEP(*(.text.FixNavigationInTileView_Part1))
    }
    .FixNavigationInTileView_Part2 0xA119E720 : {
        KEEP(*(.text.FixNavigationInTileView_Part2))
    }
    .FixNavigationInTileView_Part3 0xA119E7C2 : {
        KEEP(*(.text.FixNavigationInTileView_Part3))
    }
    .FixNavigationInTileView_Part4 0xA119E856 : {
        KEEP(*(.text.FixNavigationInTileView_Part4))
    }

    .FixNavigationInCardExplorer_Hook 0xA0F22290 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.FixNavigationInCardExplorer_Hook))
    }
    .FixNavigationInCardExplorer_Jump 0xA0984E9C : {
        KEEP(*(.text.FixNavigationInCardExplorer_Jump))
    }

    .FixLongPress_Hook 0xA0FC0130 : {
        KEEP(*(.text.FixLongPress_Hook))
    }
    .FixLongPress_Jump 0xA119E8E2 : {
        KEEP(*(.text.FixLongPress_Jump))
    }

    .FixCursorPosition 0xA119E26C : {
        KEEP(*(.text.FixCursorPosition))
    }
}
