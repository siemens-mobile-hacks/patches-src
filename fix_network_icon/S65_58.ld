SECTIONS {
    .GetNetworkIcon 0xA1720200 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetNetworkIcon))
    }
    .GetNetworkIcon_Jump 0xA1698C00 : {
        KEEP(*(.text.GetNetworkIcon_Jump))
    }
}
