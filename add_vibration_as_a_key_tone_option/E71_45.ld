SECTIONS {
    .MenuDesc DescAddr : {
        KEEP(*(.data.MenuDesc))
    }
    .ReplaceMenuDescAddr 0xA063FC28 : {
        KEEP(*(.data.ReplaceMenuDescAddr))
    }
    .FixMenuHeader 0xA063FB9A : {
        KEEP(*(.text.FixMenuHeader))
    }
    .ChangeMenuItemsCount_Part1 0xA063FBB2 : {
        KEEP(*(.text.ChangeMenuItemsCount_Part1))
    }
    .ChangeMenuItemsCount_Part2 0xA063FBDA : {
        KEEP(*(.text.ChangeMenuItemsCount_Part2))
    }
    .ChangeKeyTonesCount_Part1 0xA063FB3C : {
        KEEP(*(.text.ChangeKeyTonesCount_Part1))
    }
    .ChangeKeyTonesCount_Part2 0xA05AD382 : {
        KEEP(*(.text.ChangeKeyTonesCount_Part2))
    }

    .PlayKeySound_Hook 0xA13815A0 : {
        KEEP(*(.text.PlayKeySound_Hook))
    }
    .PlayKeySound_Jump 0xA05A285C : {
        KEEP(*(.text.PlayKeySound_Jump))
    }
}
