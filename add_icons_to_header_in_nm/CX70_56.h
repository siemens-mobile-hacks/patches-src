#pragma once

#define ADDR_MALLOC             0xA0820F98
#define ADDR_MFREE              0xA0821000
#define ADDR_SET_HEADER_ICON    0xA113D743
#define ADDR_GET_HEADER_POINTER 0xA0C9724F

#define ADDR_ON_CREATE_UNK (0xA0CB9230 | 1)
#define ADDR_ON_CHANGE_UNK (0xA0D25240 | 1)
#define ADDR_ON_CLOSE_UNK  (0xA0C975AE | 1)

#define ADDR_NATIVEMENU_DEFINITION 0xA0941C4C

#define ICONS_OFFSET 618
const unsigned char ICONS_TABLE[] = {
    0xC0, 0xC6, 0xEC,
    0xB8, 0xB2, 0x01, // 3, 5 reversed :-(
    0x45, 0x41, 0xCA
};
