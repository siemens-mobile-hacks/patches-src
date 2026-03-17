SECTIONS {
    .Insert_Hook 0xA0420F78 : {
        KEEP(*(.text.Insert_Hook))
    }
    .Insert_Jump_1 0xA03421B0 : {
        KEEP(*(.text.Insert_Jump_1))
    }

    .Insert_Jump_2_Part_1 0xA0342180 : {
        KEEP(*(.text.Insert_Jump_2_Part_1))
    }
    .Insert_Jump_2_Part_2 0xA0342190 : {
        KEEP(*(.text.Insert_Jump_2_Part_2))
    }
}
