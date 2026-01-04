SECTIONS {
    .DrawTabs_Hook 0xA0B05C58 : {
        KEEP(*(.text.DrawTabs_Hook))
    }
    .DrawTabs_Jump 0xA0AF7D6A : {
        KEEP(*(.text.DrawTabs_Jump))
    }
    .GetIMGHDRFromThemeCache_Hook 0xA0B44C34 : {
        KEEP(*(.text.GetIMGHDRFromThemeCache_Hook))
    }
    .GetIMGHDRFromThemeCache_Jump 0xA0A25596 : {
        KEEP(*(.text.GetIMGHDRFromThemeCache_Jump))
    }
    .SkipSetWidgetRect 0xA0A2514A : {
        KEEP(*(.text.SkipSetWidgetRect))
    }
    .OnFocus_Hook 0xA1383600 : {
        KEEP(*(.text.OnFocus_Hook))
    }
    .OnFocus_Jump 0xA0C51CB0 : {
        KEEP(*(.data.OnFocus_Jump))
    }
    .CallOnCreateHandlers_Hook 0xA0C29BE0 : {
        KEEP(*(.text.CallOnCreateHandlers_Hook))
    }
    .CallOnCreateHandlers_Jump 0xA0A256CE : {
        KEEP(*(.text.CallOnCreateHandlers_Jump))
    }
}
