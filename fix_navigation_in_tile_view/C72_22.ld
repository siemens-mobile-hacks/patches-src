SECTIONS {
    .FixNavigationInTileView_Part1 0xA11A7A8A : {
        KEEP(*(.text.FixNavigationInTileView_Part1))
    }
    .FixNavigationInTileView_Part2 0xA11A7B24 : {
        KEEP(*(.text.FixNavigationInTileView_Part2))
    }
    .FixNavigationInTileView_Part3 0xA11A7BC6 : {
        KEEP(*(.text.FixNavigationInTileView_Part3))
    }
    .FixNavigationInTileView_Part4 0xA11A7C5A : {
        KEEP(*(.text.FixNavigationInTileView_Part4))
    }

    .FixNavigationInCardExplorer_Hook 0xA17A2290 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.FixNavigationInCardExplorer_Hook))
    }
    .FixNavigationInCardExplorer_Jump 0xA099FF70 : {
        KEEP(*(.text.FixNavigationInCardExplorer_Jump))
    }

    .FixLongPress_Hook 0xA118A88C : {
        KEEP(*(.text.FixLongPress_Hook))
    }
    .FixLongPress_Jump 0xA11A7CE6 : {
        KEEP(*(.text.FixLongPress_Jump))
    }

    .FixCursorPosition 0xA11A7670 : {
        KEEP(*(.text.FixCursorPosition))
    }
}
