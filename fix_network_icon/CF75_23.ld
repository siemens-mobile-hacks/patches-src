SECTIONS {
    .GetNetworkIcon 0xA01E0840 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetNetworkIcon))
    }
    .GetNetworkIcon_Jump 0xA02A970C : {
        KEEP(*(.text.GetNetworkIcon_Jump))
    }
    .GetNetworkIcon_2 0xA01E0860 : {
        KEEP(*(.text.GetNetworkIcon_2))
    }
    .GetNetworkIcon_2_Jump 0xA02D5F1E : {
        KEEP(*(.text.GetNetworkIcon_2_Jump))
    }
}
