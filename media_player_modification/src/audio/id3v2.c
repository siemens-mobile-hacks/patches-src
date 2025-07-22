#include <swilib.h>
#include <byteswap.h>
#include "../data.h"
#include "../functions.h"
#include "id3v2.h"

#define SynchsafeInteger2Integer ((uint32_t (*)(uint32_t *))(ADDR_SynchsafeInteger2Integer))

#define HEADER_SIZE       10
#define FRAME_HEADER_SIZE 10

__attribute__((always_inline))
inline int IsValidFrameCharacter(const char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) ? 1 : 0;
}

__attribute__((always_inline))
inline int IsValidFrameID(const char *id) {
    return (IsValidFrameCharacter(id[0]) && IsValidFrameCharacter(id[1]) && IsValidFrameCharacter(id[2]) && IsValidFrameCharacter(id[3]));
}

__attribute__((always_inline))
inline int GetPictureUID(const char *mime_type) {
    WSHDR ws1, ws2;
    uint16_t wsbody1[128], wsbody2[8];
    _CreateLocalWS(&ws1, wsbody1, 127);
    _CreateLocalWS(&ws2, wsbody2, 7);
    const char *ext[4] = {"jpg", "jpeg", "png", "gif"};
    _iso8859_1_2ws(&ws1, mime_type, 127);
    for (int i = 0; i < 4; i++) {
        _str_2ws(&ws2, ext[i], 7);
        if (_wstriwstr(&ws1, &ws2, 1) != 0xFFFF) {
            return _GetExtUid_ws(&ws2);
        }
    }
    return 0;
}

__attribute__((always_inline))
inline PIC_FRAME *ReadPICFrame(int fp, size_t frame_size) {
    uint32_t err;
    PIC_FRAME *frame = malloc(sizeof(PIC_FRAME));
    frame->raw_frame = malloc(frame_size);
    if (_sys_read(fp, frame->raw_frame, frame_size, &err) != frame_size) {
        goto ERROR;
    }

    uint32_t offset = 0;
    //encoding
    frame->encoding = (FrameEncoding)frame->raw_frame[0];
    if (frame->encoding != FRAME_ENCODING_ISO8859_1) {
        goto ERROR;
    }
    offset++;
    //mime_type
    char *mime_type = (frame->raw_frame) + offset;
    frame->uid = GetPictureUID(mime_type);
    if (!frame->uid) {
        goto ERROR;
    }
    offset += strlen(mime_type) + 1;

    //picture_type
    frame->picture_type = *(FramePictureType*)(frame->raw_frame + offset);
    if (frame->picture_type != FRAME_PICTURE_TYPE_COVER_FRONT && frame->picture_type != FRAME_PICTURE_TYPE_OTHER) {
        goto ERROR;
    }
    offset++;
    //description
    char *description = (frame->raw_frame) + offset;
    offset += strlen(description) + 1;
    //picture_data
    frame->picture_data = (int8_t*)(frame->raw_frame + offset);
    frame->picture_data_size = frame_size - (FRAME_HEADER_SIZE + offset);
    if (frame->picture_data_size >= 512 * 1024) { // 512 kb
        ERROR:
            mfree(frame->raw_frame);
            mfree(frame);
            return NULL;
    }
    return frame;
}

__attribute__((target("thumb")))
__attribute__((section(".text.ID3v2_GetIMGHDRFromPICFrame")))
void ID3v2_GetIMGHDRFromPICFrame(MP_CSM *csm) {
    IMGHDR *img = NULL;
    uint32_t err;
    HObj hobj = _Obs_CreateObject(data->cover.frame->uid, 0x2D, 3, 0, 1, 1, &err);
    if (hobj) {
        int status = _Obs_SetInputMemory(hobj, 0, (char*)(data->cover.frame->picture_data), data->cover.frame->picture_data_size);
        if (status != 0 && status <= 0x7FFF) {
            goto EXIT;
        }
        status = _Obs_SetOutputImageSize(hobj, 120, 120);
        if (status != 0 && status <= 0x7FFF) {
            goto EXIT;
        }
        status = _Obs_SetScaling(hobj, 5);
        if (status != 0 && status <= 0x7FFF) {
            goto EXIT;
        }
        status = _Obs_Start(hobj);
        if (status != 0 && status <= 0x7FFF) {
            goto EXIT;
        }
        IMGHDR *tmp = NULL;
        status = _Obs_Output_GetPictstruct(hobj, &tmp);
        if (status != 0 && status <= 0x7FFF) {
            goto EXIT;
        }
        size_t size = _CalcBitmapSize(tmp->w, tmp->h, tmp->bpnum);
        img = malloc(sizeof(IMGHDR));
        memcpy(img, tmp, sizeof(IMGHDR));
        img->bitmap = malloc(size);
        memcpy(img->bitmap, tmp->bitmap, size);
    }
    EXIT:
        _Obs_DestroyObject(hobj);
        free_pic_frame();
        data->cover.img = img;
        data->cover.status = (data->cover.img) ? COVER_LOADED : COVER_DISABLED;
}

__attribute__((always_inline))
inline void CoverLoadingWait(const MP_CSM *csm) {
    while (data->cover.status == COVER_LOADING) {
        _NU_Sleep(50);
    }
}

__attribute__((target("thumb")))
__attribute__((section(".text.ID3v2_ReadCover")))
void ID3v2_ReadCover(MP_CSM *csm) {
    CoverLoadingWait(csm);
    data->cover.status = COVER_DISABLED;
    free_pic_frame();
    free_cover();
    if (csm->uid != 3) { // !mp3
        return;
    }

    WSHDR ws;
    uint16_t wsbody[128];
    _CreateLocalWS(&ws, wsbody, 127);
    _BuildPath(&ws, csm->file_name, csm->dir_name);

    uint32_t err, err2;
    int fp = _sys_open_ws(&ws, A_ReadOnly | A_BIN, P_READ, &err);
    if (fp == -1) {
        return;
    }

    ID3V2_HEADER header;
    uint32_t offset = _sys_read(fp, &header, HEADER_SIZE, &err);
    if (offset != HEADER_SIZE) {
        goto CLOSE;
    }
    if (strncmp(header.identifier, "ID3", 3) != 0) {
        goto CLOSE;
    }
    if (header.version[0] != 3 && header.version[0] != 4) {
        goto CLOSE;
    }
    if (header.flags & 0x6) { // extended header
        size_t size = 0;
        if (_sys_read(fp, &size, 4, &err) != 4) {
            goto CLOSE;
        }
        size_t extended_header_size = SynchsafeInteger2Integer(&size);
        if (header.version[0] == 3) {
            extended_header_size += 4;
        }
        offset += extended_header_size;
    }

    ID3V2_FRAME_HEADER frame_header;
    PIC_FRAME *pic_frame_cover = NULL;
    PIC_FRAME *pic_frame_other = NULL;
    while (offset < SynchsafeInteger2Integer(&(header.size))) {
        if (_sys_read(fp, &frame_header, FRAME_HEADER_SIZE, &err) != FRAME_HEADER_SIZE) {
            break;
        }
        if (!IsValidFrameID(frame_header.id)) {
            break;
        }
        size_t frame_size = bswap_32(frame_header.frame_size);
        if (strncmp(frame_header.id, "APIC", 4) == 0) {
            PIC_FRAME *pic_frame = ReadPICFrame(fp, frame_size);
            if (pic_frame) {
                if (pic_frame->picture_type == FRAME_PICTURE_TYPE_COVER_FRONT) {
                    pic_frame_cover = pic_frame;
                    break;
                } else if (pic_frame->picture_type == FRAME_PICTURE_TYPE_OTHER) {
                    pic_frame_other = pic_frame;
                }
            }
        }
        offset += FRAME_HEADER_SIZE + frame_size;
        if (_sys_lseek(fp, offset, S_SET, &err, &err2) == - 1) {
            break;
        }
    }
    if (pic_frame_cover) {
        data->cover.frame = pic_frame_cover;
        data->cover.status = COVER_LOADING;
        _SUBPROC(ID3v2_GetIMGHDRFromPICFrame, csm);
    }
    if (pic_frame_other) {
        if (!pic_frame_cover) {
            CoverLoadingWait(csm);
            data->cover.frame = pic_frame_other;
            data->cover.status = COVER_LOADING;
            _SUBPROC(ID3v2_GetIMGHDRFromPICFrame, csm);
        } else {
            mfree(pic_frame_other->raw_frame);
            mfree(pic_frame_other);
        }
    }
    CLOSE:
        _sys_close(fp, &err);
}
