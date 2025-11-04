SECTIONS {
    .GetNetworkIcon 0xA0800840 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.GetNetworkIcon))
    }
    .GetNetworkIcon_Jump 0xA08C4C68 : {
        KEEP(*(.text.GetNetworkIcon_Jump))
    }
}
