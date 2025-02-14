SECTIONS {
    .GetFileState_Hook 0xA1380E00 : {
        KEEP(*(.text.GetFileState_Hook))
    }
    .GetFileState_Jump 0xA0725C30 : {
        KEEP(*(.text.GetFileState_Jump))
    }
}
