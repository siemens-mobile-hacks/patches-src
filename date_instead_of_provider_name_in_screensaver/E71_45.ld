SECTIONS {
    .Insert_Hook 0xA0788BA4 : {
        KEEP(*(.text.Insert_Hook))
    }

    .Insert_Jump_1 0xA0781DBA : {
        KEEP(*(.text.Insert_Jump_1))
    }

    .Insert_Jump_2_Part_1 0xA0781D8A : {
        KEEP(*(.text.Insert_Jump_2_Part_1))
    }
    .Insert_Jump_2_Part_2 0xA0781D9A : {
        KEEP(*(.text.Insert_Jump_2_Part_2))
    }
}
