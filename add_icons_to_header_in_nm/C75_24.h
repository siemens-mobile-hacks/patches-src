#pragma once

#define ADDR_malloc (uint32_t*)(0xA0203C24)
#define ADDR_mfree  (uint32_t*)(0xA0203C8C)
#define ADDR_SetHeaderIcon     (0xA07B71D3)
#define ADDR_GetHeaderPointer  (0xA077CC81)

#define ADDR_OnCreate_unk (0xA07B3330 | 1)
#define ADDR_OnChange_unk (0xA08E4D84 | 1)
#define ADDR_OnClose_unk  (0xA077CFEE | 1)

#define ADDR_NATIVE_MENU_DEFINITION (void*)(0xA04992CC)

#define ICONS_OFFSET 634
const unsigned char ICONS_TABLE[] = {
    0xC9, 0xCF, 0xF5,
    0xC0, 0xB9, 0x01, // 3, 5 reversed :-(
    0x43, 0x3F, 0xD3
};
