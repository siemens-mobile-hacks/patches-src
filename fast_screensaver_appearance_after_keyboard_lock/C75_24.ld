SECTIONS {
    .ShowScreenSaver_Hook 0xA02B8494 : {
        KEEP(*(.text.ShowScreenSaver_Hook))
    }
    .ShowScreenSaver_Jump 0xA02D1046 : {
        KEEP(*(.text.ShowScreenSaver_Jump))
    }
}
