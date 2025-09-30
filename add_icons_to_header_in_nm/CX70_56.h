#pragma once

#define ADDR_malloc (uint32_t*)(0xA0820F98)
#define ADDR_mfree  (uint32_t*)(0xA0821000)
#define ADDR_SetHeaderIcon     (0xA113D743)
#define ADDR_GetHeaderPointer  (0xA0C9724F)

#define ADDR_OnCreate_unk (0xA0CB9230 | 1)
#define ADDR_OnChange_unk (0xA0D25240 | 1)
#define ADDR_OnClose_unk  (0xA0C975AE | 1)

#define ADDR_NATIVE_MENU_DEFINITION (void*)(0xA0941C4C)

#define ICONS_OFFSET 618
const unsigned char ICONS_TABLE[] = {
    0xC0, 0xC6, 0xEC,
    0xB8, 0xB2, 0x01, // 3, 5 reversed :-(
    0x45, 0x41, 0xCA
};
