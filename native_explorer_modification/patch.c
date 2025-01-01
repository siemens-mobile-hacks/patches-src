#include <swilib.h>

#ifdef E71_45
    #include "E71_45.h"
#endif

#define _wsprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wsprintf))
#define _GetPITaddr ((IMGHDR *(*)(int num))(ADDR_GetPITaddr))
#define _CalcBitmapSize ((int (*)(short w, short i, char bpnum))(ADDR_CalcBitmapSize))


#define MergeIMGHDR ((void (*)(IMGHDR *src, IMGHDR *dest))(ADDR_MergeIMGHDR))
#define MergeIcons_Unk ((void (*)(void *, void *))(ADDR_MergeIcons_Unk))
#define SetPreview ((void (*)(void *))(ADDR_SetPreview))

__attribute__((target("thumb")))
__attribute__((section(".text.MergeIconsHook")))
void MergeIconsHook(void *r0, void *r1, IMGHDR *src) {
    if (((char*)r0)[0x84]) { // enabled mark mode
        src = _GetPITaddr(1336);
    }
    IMGHDR *dest = (IMGHDR*)((char*)r1 + 8);
    MergeIMGHDR(src, dest);
    MergeIcons_Unk(r0, r1);
}

__attribute__((section(".text.SetPreviewHook")))
void SetPreviewHook(void *r0) {
    if (!((char*)r0)[0x84]) { // disabled mark mode
        SetPreview(r0);
    }
}

__attribute__((section(".text.Set2ndTabPath")))
void Set2ndTabPath(void *r0, WSHDR *ws) {
    _wsprintf(ws, "1:\\");
}

__attribute__((target("thumb")))
__attribute__((section(".text.FixInitTabHook")))
int FixInitTabHook(int r0, const WSHDR *ws) {
    int id = ws->wsbody[1] & 0xFF - '0';
    if (id >= 4) {
        id = 3;
    }
    return id;
}
