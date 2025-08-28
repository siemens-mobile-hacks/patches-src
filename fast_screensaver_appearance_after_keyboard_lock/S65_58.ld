SECTIONS {
    .ShowScreenSaver_Hook 0xA17E0920 : {
        KEEP(*(.text.ShowScreenSaver_Hook))
    }
    .ShowScreenSaver_Jump 0xA16A13FC : {
        KEEP(*(.text.ShowScreenSaver_Jump))
    }
}
