SECTIONS {
    .GetNetworkIcon 0xA1720200 : {
        KEEP(*(.text.GetNetworkIcon))
        KEEP(*(.rodata*))
    }
    .GetNetworkIcon_Jump 0xA1698C00 : {
        KEEP(*(.text.GetNetworkIcon_Jump))
    }
}
