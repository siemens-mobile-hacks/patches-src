SECTIONS {
    .JVM_Stop_Hook 0xA1384350 : {
        KEEP(*(.text.JVM_Stop_Hook))
    }
    .JVM_Stop_Jump 0xA0A082C0 : {
        KEEP(*(.text.JVM_Stop_Jump))
    }

    .JVM_Free_Hook 0xA1384380 : {
        KEEP(*(.text.JVM_Free_Hook))
    }
    .JVM_Free_Jump 0xA09FC2E0 : {
        KEEP(*(.text.JVM_Free_Jump))
    }
}
