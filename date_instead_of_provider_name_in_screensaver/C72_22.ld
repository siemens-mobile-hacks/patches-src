SECTIONS {
    .Insert_Hook 0xA0932778 : {
        KEEP(*(.text.Insert_Hook))
    }

    .Insert_Jump_1 0xA0905D20 : {
        KEEP(*(.text.Insert_Jump_1))
    }

    .Insert_Jump_2_Part_1 0xA0905CF0 : {
        KEEP(*(.text.Insert_Jump_2_Part_1))
    }
    .Insert_Jump_2_Part_2 0xA0905D00 : {
        KEEP(*(.text.Insert_Jump_2_Part_2))
    }
}
