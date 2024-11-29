#ifdef E71_45
    #include "E71_45.h"
#endif

#define GramBGFromLCD ((void (*)(void *, void *, void *, void *))(ADDR_GrabBGFromLCD))

__attribute__((target("thumb")))
__attribute__((section(".text.GrubBGFromLCD")))
void Hook(void *r0, void *r1, void *r2, void *r3) {
    if (r0 && *(unsigned int*)r0 == 0) {
        GramBGFromLCD(r0, r1, r2, r3);
    }
}
