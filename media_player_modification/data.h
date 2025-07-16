#pragma once

#include "id3v2.h"
#include "functions.h"

typedef enum CoverStatus {
    COVER_DISABLED,
    COVER_LOADING,
    COVER_LOADED,
} CoverStatus;

typedef struct {
    CoverStatus status;
    IMGHDR *img;
    PIC_FRAME *frame;
} COVER;

typedef struct {
    int flag;
    int timer_play;
    int timer_hide_list;

    COVER cover;
} DATA;

#define field_name csm.unk2
#define data ((DATA*)(csm->field_name))
#define malloc_data() csm->field_name = (int)malloc(sizeof(DATA))

#define free_cover() if (data->cover.img) {mfree(data->cover.img->bitmap); mfree(data->cover.img); data->cover.img = NULL;}
#define free_pic_frame() if (data->cover.frame) {mfree(data->cover.frame->raw_frame); mfree(data->cover.frame); data->cover.frame = NULL;}
#define free_data() mfree((void*)(csm->field_name)); csm->field_name = 0
