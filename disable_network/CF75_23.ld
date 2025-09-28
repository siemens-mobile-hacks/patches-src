SECTIONS {
    .DisableNetwork 0xA0F60300 : {
        KEEP(*(.text.DisableNetwork))
    }
    .EnableNetwork 0xA0F60350 : {
        KEEP(*(.text.EnableNetwork))
    }
    .AutoDisableNetwork 0xA01E0800 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.AutoDisableNetwork))
    }
    .AutoDisableNetwork_Jump 0xA02A89E2 : {
        KEEP(*(.text.AutoDisableNetwork_Jump))
    }
}
