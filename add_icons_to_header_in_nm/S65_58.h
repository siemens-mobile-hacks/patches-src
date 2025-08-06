#pragma once

#define ADDR_malloc (uint32_t*)0xA0820F98
#define ADDR_mfree  (uint32_t*)0xA0821000
#define ADDR_SetHeaderIcon     0xA115FA07
#define ADDR_GetHeaderPointer  0xA1148DA7

#define ADDR_OnCreate_unk (0xA115BBA4 | 1)
#define ADDR_OnChange_unk (0xA119DC50 | 1)
#define ADDR_OnClose_unk  (0xA1149106 | 1)

#define ADDR_NATIVE_MENU_DEFINITION 0xA092D8C8

#define ICONS_OFFSET 553
const unsigned char ICONS_TABLE[] = {
    0xC1, 0xC7, 0xED,
    0xBC, 0xB6, 0x01, // 3, 5 reversed :-(
    0x45, 0x41, 0xCB,
};
