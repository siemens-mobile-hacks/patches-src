#pragma once

#define ADDR_malloc (uint32_t*)(0xA0203C24)
#define ADDR_mfree  (uint32_t*)(0xA0203C8C)
#define ADDR_SetHeaderIcon     (0xA07BE6E3)
#define ADDR_GetHeaderPointer  (0xA0782AAD)

#define ADDR_OnCreate_unk (0xA07BA840 | 1)
#define ADDR_OnChange_unk (0xA08EB3C8 | 1)
#define ADDR_OnClose_unk  (0xA0782E1A | 1)

#define ADDR_NATIVE_MENU_DEFINITION (void*)(0xA049D074)

#define ICONS_OFFSET 701
const unsigned char ICONS_TABLE[] = {
    0xC0, 0xC6, 0xEC,
    0xB8, 0xB2, 0x01, // 3, 5 reversed :-(
    0x45, 0x41, 0xCA
};
