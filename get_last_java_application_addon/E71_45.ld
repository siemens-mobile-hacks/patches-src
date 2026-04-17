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

    .RB_OnCreate_Hook 0xA13844B0 : {
            KEEP(*(.text.RB_OnCreate_Hook))
        }
    .RB_OnCreate_Jump 0xA0C514E0 : {
        KEEP(*(.data.RB_OnCreate_Jump))
    }
    .RB_OnMessage_Hook 0xA13844F0 : {
        KEEP(*(.text.RB_OnMessage_Hook))
    }
    .RB_OnMessage_Jump 0xA0C514DC : {
        KEEP(*(.data.RB_OnMessage_Jump))
    }
}
