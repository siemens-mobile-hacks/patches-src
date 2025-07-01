SECTIONS {
    .GetNetworkIcon 0xA17E0840 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetNetworkIcon))
    }
    .GetNetworkIcon_Jump 0xA171567E : {
        KEEP(*(.text.GetNetworkIcon_Jump))
    }
}
