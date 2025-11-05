#pragma once

#define ADDR_malloc (uint32_t*)(0xA0820F9C)
#define ADDR_mfree  (uint32_t*)(0xA0821004)
#define ADDR_SetHeaderIcon     (0xA11348DB)
#define ADDR_GetHeaderPointer  (0xA112C8DD)

#define ADDR_OnCreate_unk (0xA0CCB014 | 1)
#define ADDR_OnChange_unk (0xA11A7054 | 1)
#define ADDR_OnClose_unk  (0xA112CC4A | 1)

#define ADDR_NATIVE_MENU_DEFINITION (void*)(0xA0942694)

#define ICONS_OFFSET 580
const unsigned char ICONS_TABLE[] = {
    0xC5, 0xCB, 0xF1,
    0xBC, 0xB5, 0x01, // 3, 5 reversed :-(
    0x46, 0x42, 0xCF
};
