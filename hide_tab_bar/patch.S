.section .text.DrawTabs_Jump
.thumb
bl DrawTabs_Hook

.section .text.GetIMGHDRFromThemeCache_Jump
.thumb
mov r0, r5
bl GetIMGHDRFromThemeCache_Hook

.section .text.SkipSetWidgetRect
.thumb
nop
nop

.section .data.OnFocus_Jump
.int OnFocus_Hook

.section .text.CallOnCreateHandlers_Jump
.thumb
bl CallOnCreateHandlers_Hook
