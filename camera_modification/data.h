#pragma once

typedef struct {
    int brightness;
    int white_balance;
    int color_mode;
} DATA;

#define field_name gui.color2
#define data ((DATA*)(gui->field_name))
#define malloc_data() gui->field_name = (int)_malloc(sizeof(DATA)); _zeromem(data, sizeof(DATA))
#define free_data() _mfree(data); gui->field_name = 0
