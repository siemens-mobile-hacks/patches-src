SECTIONS {
    .Insert_Hook 0xA0391DD4 : {
        KEEP(*(.text.Insert_Hook))
    }
    .Insert_Jump_1 0xA0383F60 : {
        KEEP(*(.text.Insert_Jump_1))
    }

    .Insert_Jump_2_Part_1 0xA0383F30 : {
        KEEP(*(.text.Insert_Jump_2_Part_1))
    }
    .Insert_Jump_2_Part_2 0xA0383F40 : {
        KEEP(*(.text.Insert_Jump_2_Part_2))
    }
}
