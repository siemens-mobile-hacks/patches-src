#pragma once

typedef struct {
    int state;
    void (*proc)(char *param);
    char *param;
    int please_wait_gui_id;
} DATA;
