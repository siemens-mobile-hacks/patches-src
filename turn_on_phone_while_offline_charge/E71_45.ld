SECTIONS {
    .DrawSimpleBarHook 0xA05AB6F4 : {
        KEEP(*(.text.DrawSimpleBarHook))
    }
    .DrawSimpleBar 0xA05AA6AA : {
        KEEP(*(.text.DrawSimpleBar))
    }
}
