SECTIONS {
    .rodata 0xA13814F0 : {
        KEEP(*(.rodata*))
    }
    .MenuDesc DESC_ADDR : {
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

    .AddLgpMessage_Hook 0xA13815E0 : {
        KEEP(*(.text.AddLgpMessage_Hook))
    }
    .AddLgpMessage_Trampoline 0xA0640054 : {
        KEEP(*(.text.AddLgpMessage_Trampoline))
    }
    .AddLgpMessage_Jump 0xA063FBE4 : {
        KEEP(*(.text.AddLgpMessage_Jump))
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
