SECTIONS {
    .ShowScreenSaver_Hook 0xA038F048 : {
        KEEP(*(.text.ShowScreenSaver_Hook))
    }
    .ShowScreenSaver_Jump 0xA034313C : {
        KEEP(*(.text.ShowScreenSaver_Jump))
    }
}
