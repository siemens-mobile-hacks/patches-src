SECTIONS {
    .Insert_Hook 0xA17E09B0 : {
        KEEP(*(.text.Insert_Hook))
    }
    .Insert_Jump_1 0xA1725BF8 : {
        KEEP(*(.text.Insert_Jump_1))
    }

    .Insert_Jump_2_Part_1 0xA1725BC8 : {
        KEEP(*(.text.Insert_Jump_2_Part_1))
    }
    .Insert_Jump_2_Part_2 0xA1725BD8 : {
        KEEP(*(.text.Insert_Jump_2_Part_2))
    }
}
