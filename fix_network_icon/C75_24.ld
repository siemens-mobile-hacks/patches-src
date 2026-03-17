SECTIONS {
    .GetNetworkIcon 0xA01E0840 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetNetworkIcon))
    }
    .GetNetworkIcon_Jump 0xA02A8898 : {
        KEEP(*(.text.GetNetworkIcon_Jump))
    }
}
