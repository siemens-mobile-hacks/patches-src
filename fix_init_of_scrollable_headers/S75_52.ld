SECTIONS {
    .SetScrollType 0xA0B73234 : {
        KEEP(*(.text.SetScrollType))
    }
    .SetScrollType_Jump 0xA0A1D67E : {
        KEEP(*(.text.SetScrollType_Jump))
    }
}
