#pragma once

#include <swilib.h>

typedef struct {
    char identifier[3];
    uint8_t version[2];
    int8_t flags;
    size_t size;
} ID3V2_HEADER;

typedef struct {
    char id[4];
    size_t frame_size;
    short flags;
} ID3V2_FRAME_HEADER;

typedef enum FramePictureType {
    FRAME_PICTURE_TYPE_COVER_FRONT = 0x03,
} FramePicture;

typedef enum FrameEncoding {
    FRAME_ENCODING_ISO8859_1,
} FrameEncoding;

typedef struct {
    FrameEncoding encoding;
    int uid;
    FramePicture picture_type;
    int8_t *picture_data;
    uint32_t picture_data_size;
    //
    char *raw_frame;
} PIC_FRAME;
