SECTIONS {
    .FixNavigationInTileView_Part1 0xA08EBDFE : {
        KEEP(*(.text.FixNavigationInTileView_Part1))
    }
    .FixNavigationInTileView_Part2 0xA08EBE98 : {
        KEEP(*(.text.FixNavigationInTileView_Part2))
    }
    .FixNavigationInTileView_Part3 0xA08EBF3A : {
        KEEP(*(.text.FixNavigationInTileView_Part3))
    }
    .FixNavigationInTileView_Part4 0xA08EBFCE : {
        KEEP(*(.text.FixNavigationInTileView_Part4))
    }

    .FixNavigationInCardExplorer_Hook 0xA0F22290 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.FixNavigationInCardExplorer_Hook))
    }
    .FixNavigationInCardExplorer_Jump 0xA0356708 : {
        KEEP(*(.text.FixNavigationInCardExplorer_Jump))
    }

    .FixLongPress_Hook 0xA09699B0 : {
        KEEP(*(.text.FixLongPress_Hook))
    }
    .FixLongPress_Jump 0xA08EC05A : {
        KEEP(*(.text.FixLongPress_Jump))
    }

    .FixCursorPosition 0xA08EB9E4 : {
        KEEP(*(.text.FixCursorPosition))
    }
}
