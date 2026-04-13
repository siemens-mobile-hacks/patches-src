SECTIONS {
    .GetLastJavaApplication 0xA1384400 : {
        KEEP(*(.text.GetLastJavaApplication))
    }

    .JVM_StartApplication_Hook 0xA1384430 : {
        KEEP(*(.text.JVM_StartApplication_Hook))
    }
    .JVM_StartApplication_Jump 0xA0ACAD40 : {
        KEEP(*(.text.JVM_StartApplication_Jump))
    }
}
