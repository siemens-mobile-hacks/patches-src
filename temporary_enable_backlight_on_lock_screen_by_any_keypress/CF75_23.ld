SECTIONS {
    .Hook 0xA02FA2AC : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA02D2898 : {
        KEEP(*(.text.Jump))
    }
    
    .Hook_2 0xA02B97F0 : {
        KEEP(*(.text.Hook_2))
    }
    .Jump_2 0xA02CC95C : {
        KEEP(*(.text.Jump_2))
    }
}
