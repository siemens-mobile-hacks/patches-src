#pragma once

typedef unsigned char  undefined;
typedef unsigned char  byte;
typedef unsigned char  undefined1;
typedef unsigned short ushort;
typedef unsigned short undefined2;
typedef unsigned int   undefined4;
typedef unsigned int   uint;

typedef enum MP_MediaType {
    MP_MEDIA_TYPE_UNKNOWN =- 1,
    MP_MEDIA_TYPE_IMAGE = 0,
    MP_MEDIA_TYPE_AUDIO = 1,
    MP_MEDIA_TYPE_VIDEO = 2
} MP_MediaType;

typedef enum MP_PlayStatus {
    MP_PLAY_STATUS_PLAY,
    MP_PLAY_STATUS_STOP,
    MP_PLAY_STATUS_PAUSE,
    MP_PLAY_STATUS_FAST_FORWARD,
    MP_PLAY_STATUS_REWIND_BACKWARD,
} MP_PlayStatus;

typedef enum MP_SoundViewMode {
    MP_SOUND_VIEW_MODE_LIST,
    MP_SOUND_VIEW_MODE_ANIMATION
} MP_SoundViewMode;
