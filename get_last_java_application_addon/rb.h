#pragma once

#include <swilib.h>

typedef struct RB_CSM RB_CSM;

struct RB_CSM {
    struct CSM_RAM csm;
    int unk1;
    int rb_id;
    int gui_id;
    int unk2;
    int isolate_id;
    int unk3;
};
