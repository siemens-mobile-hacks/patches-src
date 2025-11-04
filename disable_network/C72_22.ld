SECTIONS {
    .DisableNetwork 0xA0FA0300 : {
        KEEP(*(.text.DisableNetwork))
    }
    .EnableNetwork 0xA0FA0350 : {
        KEEP(*(.text.EnableNetwork))
    }
    .AutoDisableNetwork 0xA0800800 : {
        KEEP(*(.rodata*))
        KEEP(*(.text.AutoDisableNetwork))
    }
    .AutoDisableNetwork_Jump 0xA08C3EF6 : {
        KEEP(*(.text.AutoDisableNetwork_Jump))
    }
}
