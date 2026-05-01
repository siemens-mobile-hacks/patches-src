SECTIONS {
    .Common 0xA1384550 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetType))
    }

    .Outdoor_Add_Part1 0xA07ED1BA : {
        KEEP(*(.text.Outdoor_Add_Part1))
    }
    .Outdoor_Add_Part2 0xA07CABCC : {
        KEEP(*(.text.Outdoor_Add_Part2))
    }
    .Outdoor_RemoveMissedIcon 0xA086E0C4 : {
        KEEP(*(.data.Outdoor_RemoveMissedIcon))
    }

    .FixName_Hook 0xA0676008 : {
        KEEP(*(.text.FixName_Hook))
    }
    .FixName_Jump_1 0xA07CA9A2 : {
        KEEP(*(.text.FixName_Jump_1))
    }
    .FixName_Jump_2 0xA05C52C0 : {
        KEEP(*(.text.FixName_Jump_2))
    }

    .BaseOnRedraw_Hook 0xA078B748 : {
        KEEP(*(.text.BaseOnRedraw_Hook))
    }
    .BaseOnRedraw_Jump 0xA07817B0 : {
        KEEP(*(.text.BaseOnRedraw_Jump))
    }

    .CreateGUI_Hook 0xA080A268 : {
        KEEP(*(.text.CreateGUI_Hook))
    }
    .CreateGUI_Jump 0xA070335C : {
        KEEP(*(.text.CreateGUI_Jump))
    }
}
