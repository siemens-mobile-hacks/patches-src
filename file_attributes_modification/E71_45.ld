SECTIONS {
    .rodata 0xA1381100 : {
        KEEP(*(.rodata*))
    }

    .ShowFullPath_Part1 0xA071375C : {
        KEEP(*(.text.ShowFullPath_Part1))
    }
    .ShowFullPath_Part2 0xA0713910 : {
        KEEP(*(.text.ShowFullPath_Part2))
    }
    .ShowFullPath_Part3 0xA0713938 : {
        KEEP(*(.text.ShowFullPath_Part3))
    }
    .ShowFullPath_Part4 0xA071393C : {
        KEEP(*(.text.ShowFullPath_Part4))
    }
    .ShowFullPath_Part5 0xA0713EA0 : {
        KEEP(*(.text.ShowFullPath_Part5))
    }
    .ShowFullPath_Part6 0xA0714798 : {
        KEEP(*(.text.ShowFullPath_Part6))
    }

    .SetCursor 0xA1381120 : {
        KEEP(*(.text.SetCursor))
    }

    .Init_Hook 0xA13811E0 : {
        KEEP(*(.text.Init_Hook))
    }
    .Init_Jump 0xA0713944 : {
        KEEP(*(.text.Init_Jump))
    }

    .Update 0xA13812C0 : {
        KEEP(*(.text.Update))
    }
    .OnKey_Hook 0xA1381450 : {
        KEEP(*(.text.OnKey_Hook))
    }
    .OnKey_Jump_Part1 0xA0714D58 : {
        KEEP(*(.text.OnKey_Jump_Part1))
    }
    .OnKey_Jump_Part2 0xA0714D60 : {
        KEEP(*(.text.OnKey_Jump_Part2))
    }

    .FixSoftkeysMapping_Part1 0xA0870200 : {
        KEEP(*(.data.FixSoftkeysMapping_Part1))
    }
    .FixSoftkeysMapping_Part2 0xA0870208 : {
        KEEP(*(.data.FixSoftkeysMapping_Part2))
    }
    .FixLgpID 0xA08701D4 : {
        KEEP(*(.data.FixLgpID))
    }
}
