.section .text.GetNetworkIcon_Jump
.thumb
bl GetNetworkIcon

#if defined(SECONDARY_DISPLAY)
    .section .text.GetNetworkIcon_2_Jump
    .thumb
    bl GetNetworkIcon_2
#endif
