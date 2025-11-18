SECTIONS {
    .DisableNetwork 0xA0FA0300 : {
        KEEP(*(.text.DisableNetwork))
    }
    .EnableNetwork 0xA0FA0350 : {
        KEEP(*(.text.EnableNetwork))
    }
    .AutoDisableNetwork 0xA17E0800 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.AutoDisableNetwork))
    }
    .AutoDisableNetwork_Jump 0xA1714A9C : {
        KEEP(*(.text.AutoDisableNetwork_Jump))
    }
}
