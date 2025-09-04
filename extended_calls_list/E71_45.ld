SECTIONS {
    .OnKey_Hook 0xA1382B00 : {
        KEEP(*(.text.OnKey_Hook))
    }
    .OnKey_Jump 0xA0C7D024 : {
        KEEP(*(.data.OnKey_Jump))
    }
}
