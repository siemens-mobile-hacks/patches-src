SECTIONS {
    .Hook 0xA0330D24 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA034554A : {
        KEEP(*(.text.Jump))
    }
    
    .Hook_2 0xA02B97F0 : {
        KEEP(*(.text.Hook_2))
    }
    .Jump_2 0xA02CC95C : {
        KEEP(*(.text.Jump_2))
    }
}
