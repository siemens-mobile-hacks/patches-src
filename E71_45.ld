SECTIONS {
    .text 0xA12F5600 : {
        KEEP(*(.text.Entry*))
        KEEP(*(.text*))
    }
}
