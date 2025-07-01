SECTIONS {
    .FixNavigationInTileView_Part1 0xA0D25C76 : {
        KEEP(*(.text.FixNavigationInTileView_Part1))
    }
    .FixNavigationInTileView_Part2 0xA0D25D10 : {
        KEEP(*(.text.FixNavigationInTileView_Part2))
    }
    .FixNavigationInTileView_Part3 0xA0D25DB2 : {
        KEEP(*(.text.FixNavigationInTileView_Part3))
    }
    .FixNavigationInTileView_Part4 0xA0D25E46 : {
        KEEP(*(.text.FixNavigationInTileView_Part4))
    }

    .FixNavigationInCardExplorer_Hook 0xA0F22290 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.FixNavigationInCardExplorer_Hook))
    }
    .FixNavigationInCardExplorer_Jump 0xA09911A0 : {
        KEEP(*(.text.FixNavigationInCardExplorer_Jump))
    }

    .FixLongPress_Hook 0xA0D4679C : {
        KEEP(*(.text.FixLongPress_Hook))
    }
    .FixLongPress_Jump 0xA0D25ED2 : {
        KEEP(*(.text.FixLongPress_Jump))
    }

    .FixCursorPosition 0xA0D2585C : {
        KEEP(*(.text.FixCursorPosition))
    }
}
