#pragma once

#include "id3v2.h"
#include "functions.h"

enum CoverStatus {
    COVER_DISABLED,
    COVER_LOADING,
    COVER_LOADED,
};

typedef struct {
    int flag;
    int timer_play;
    int timer_hide_list;

    IMGHDR *cover;
    int cover_status;
    PIC_FRAME *pic_frame;
} DATA;

#define field_name csm.unk2
#define data ((DATA*)(csm->field_name))
#define malloc_data() csm->field_name = (int)malloc(sizeof(DATA))

#define free_cover() if (data->cover) {mfree(data->cover->bitmap); mfree(data->cover); data->cover = NULL;}
#define free_pic_frame() if (data->pic_frame) {mfree(data->pic_frame->raw_frame); mfree(data->pic_frame); data->pic_frame = NULL;}
#define free_data() mfree((void*)(csm->field_name)); csm->field_name = 0
