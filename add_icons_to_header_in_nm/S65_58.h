#pragma once

#define ADDR_MALLOC             0xA0820F98
#define ADDR_MFREE              0xA0821000
#define ADDR_SET_HEADER_ICON    0xA115FA07
#define ADDR_GET_HEADER_POINTER 0xA1148DA7

#define ADDR_ON_CREATE_UNK (0xA115BBA4 | 1)
#define ADDR_ON_CHANGE_UNK (0xA119DC50 | 1)
#define ADDR_ON_CLOSE_UNK  (0xA1149106 | 1)

#define ADDR_NATIVEMENU_DEFINITION 0xA092D8C8

#define ICONS_OFFSET 553
const unsigned char ICONS_TABLE[] = {
    0xC1, 0xC7, 0xED,
    0xBC, 0xB6, 0x01, // 3, 5 reversed :-(
    0x45, 0x41, 0xCB,
};
