SECTIONS {
    .Common 0xA1482200 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetType))
    }

    .Outdoor_Add_Part1 0xA03CE1CA : {
        KEEP(*(.text.Outdoor_Add_Part1))
    }
    .Outdoor_Add_Part2 0xA03A8724 : {
        KEEP(*(.text.Outdoor_Add_Part2))
    }
    .Outdoor_RemoveMissedIcon 0xA043A910 : {
        KEEP(*(.data.Outdoor_RemoveMissedIcon))
    }

    .FixName_Hook 0xA0610644 : {
        KEEP(*(.text.FixName_Hook))
    }
    .FixName_Jump_1 0xA03A84B0 : {
        KEEP(*(.text.FixName_Jump_1))
    }
    .FixName_Jump_2 0xA029F5A4 : {
        KEEP(*(.text.FixName_Jump_2))
    }

    .BaseOnRedraw_Hook 0xA032F2AC : {
        KEEP(*(.text.BaseOnRedraw_Hook))
    }
    .BaseOnRedraw_Jump 0xA038399C : {
        KEEP(*(.text.BaseOnRedraw_Jump))
    }

    .CreateGUI_Hook 0xA03F24F0 : {
        KEEP(*(.text.CreateGUI_Hook))
    }
    .CreateGUI_Jump 0xA0346B82 : {
        KEEP(*(.text.CreateGUI_Jump))
    }
}
