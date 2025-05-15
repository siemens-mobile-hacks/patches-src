SECTIONS {
    .DisableNetworkIcon 0xA05C0F9A : {
        KEEP(*(.text.DisableNetworkIcon))
    }
    .DisableBatteryIcon 0xA05C153A : {
        KEEP(*(.text.DisableBatteryIcon))
    }

    .DrawIconBarIcon 0xA13816A0 : {
        KEEP(*(.text.DrawIconBarIcon))
    }
    .DrawIconBar_Hook 0xA1381700 : {
        KEEP(*(.text.DrawIconBar_Hook))
    }
    .DrawIconBar_Trampoline 0xA05C6B4C : {
        KEEP(*(.text.DrawIconBar_Trampoline))
    }
    .DrawIconBar_Jump_Part1 0xA05C13E8 : {
        KEEP(*(.text.DrawIconBar_Jump_Part1))
    }
    .DrawIconBar_Jump_Part2 0xA05C1532 : {
        KEEP(*(.text.DrawIconBar_Jump_Part2))
    }

    .ChangeAutoUpdateTimer 0xA066D130 : {
        KEEP(*(.data.ChangeAutoUpdateTimer))
    }
}
