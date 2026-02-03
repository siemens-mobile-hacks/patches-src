SECTIONS {
    .Hook 0xA02E3500 : {
        KEEP(*(.text.Hook))
    }
    .Jump 0xA02883FA : {
        KEEP(*(.text.Jump))
    }
}
