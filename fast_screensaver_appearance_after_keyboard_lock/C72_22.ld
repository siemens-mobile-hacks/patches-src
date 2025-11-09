SECTIONS {
    .ShowScreenSaver_Hook 0xA08CAC6C : {
        KEEP(*(.text.ShowScreenSaver_Hook))
    }
    .ShowScreenSaver_Jump 0xA08DFFD6 : {
        KEEP(*(.text.ShowScreenSaver_Jump))
    }
}
