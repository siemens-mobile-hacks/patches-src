.section .text.SkipGetBrowserStateCheck
.thumb
b . + 0x10

.section .text.GetBrowserState_Jump
.thumb
bl GetBrowserState
