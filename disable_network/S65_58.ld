SECTIONS {
    .DisableNetwork 0xA0FA0300 : {
        KEEP(*(.text.DisableNetwork))
    }
    .EnableNetwork 0xA0FA0350 : {
        KEEP(*(.text.EnableNetwork))
    }
    .AutoDisableNetwork 0xA17E0800 : {
        KEEP(*(.text.AutoDisableNetwork))
        KEEP(*(.rodata*))
    }
    .AutoDisableNetwork_Jump 0xA1697E8A : {
        KEEP(*(.text.AutoDisableNetwork_Jump))
    }
}
