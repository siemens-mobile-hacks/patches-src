SECTIONS {
    .SetScrollType 0xA0A2395C : {
        KEEP(*(.text.SetScrollType))
    }
    .SetScrollType_Jump 0xA0A27916 : {
        KEEP(*(.text.SetScrollType_Jump))
    }
}
