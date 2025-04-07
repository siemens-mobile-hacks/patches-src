SECTIONS {
    .ShowScreenSaver_Hook 0xA06FC0DC : {
        KEEP(*(.text.ShowScreenSaver_Hook))
    }
    .ShowScreenSaver_Jump 0xA0700350 : {
        KEEP(*(.text.ShowScreenSaver_Jump))
    }
}
