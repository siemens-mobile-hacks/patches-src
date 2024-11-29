#include <swilib.h>

typedef unsigned char undefined;
typedef unsigned char byte;

typedef struct {
    struct RECT rect;
    int scroll_delay;
    int scroll_speed;
    int unk_flag_minus1;
    int field4_0x14;
    int field5_0x18;
    struct IMGHDR *bg;
} SCROLL_TEXT_GUI_PARAMS;

typedef struct {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    byte scroll_mode;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    int scroll_delay;
    int scroll_speed;
    undefined field34_0x28;
    undefined field35_0x29;
    undefined field36_0x2a;
    undefined field37_0x2b;
    undefined field38_0x2c;
    undefined field39_0x2d;
    undefined field40_0x2e;
    undefined field41_0x2f;
} SCROLL_TEXT_GUI_PREV_PARAMS;

typedef struct {
    SCROLL_TEXT_GUI_PARAMS *params;
    int field1_0x4;
    SCROLL_TEXT_GUI_PREV_PARAMS *last_params;
    int field3_0xc;
    int field4_0x10;
    int field5_0x14;
    int font_id;
    int field7_0x1c;
    int field8_0x20;
    int field9_0x24;
    int field10_0x28;
    int field11_0x2c;
    int scroll_offset;
    int field13_0x34;
    byte scroll_mode;
    undefined field15_0x39;
    undefined field16_0x3a;
    undefined field17_0x3b;
    int field18_0x3c;
    int field19_0x40;
    int field20_0x44;
    int field21_0x48;
    void *(*malloc)(size_t);
    void (*mfree)(void *);
} SCROLL_TEXT_GUI;

typedef struct {
    SCROLL_TEXT_GUI scroll_text_gui;
    int field1_0x54;
    int is_active_item;
    int field3_0x5c;
    int field4_0x60;
    int field5_0x64;
    int field6_0x68;
    int field7_0x6c;
    int field8_0x70;
    int field9_0x74;
    int field10_0x78;
    int field11_0x7c;
    int field12_0x80;
    int field13_0x84;
    int field14_0x88;
    int field15_0x8c;
    int field16_0x90;
} MENU_ITEM_GUI;
