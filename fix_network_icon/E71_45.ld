SECTIONS {
    .GetNetworkIcon 0xA05C744C : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetNetworkIcon))
    }
    .GetNetworkIcon_Jump 0xA05C0FA2 : {
        KEEP(*(.text.GetNetworkIcon_Jump))
    }
}
