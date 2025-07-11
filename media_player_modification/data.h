#pragma once

#include "functions.h"

typedef struct {
    int flag;
    int timer_play;
    int timer_hide_list;
    IMGHDR *cover;
} DATA;

#define field_name csm.unk2
#define data ((DATA*)(csm->field_name))
#define malloc_data() csm->field_name = (int)malloc(sizeof(DATA))
#define free_data() mfree((void*)(csm->field_name)); csm->field_name = 0
