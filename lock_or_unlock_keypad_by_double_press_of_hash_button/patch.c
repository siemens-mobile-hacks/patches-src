#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
    #ifdef S75_52
        #include "S75_52.h"
    #endif
#endif

#define _strncmp ((int (*)(const char *, const char *, size_t))(ADDR_strncmp))
#define _GeneralFuncF1 ((void (*)(int))(ADDR_GeneralFuncF1))

#define KeypadLock ((void (*)())(ADDR_KeypadLock))

__attribute__((target("thumb")))
__attribute__((section(".text.KbdLock_Hook")))
int KbdLock_Hook(const char *s1, const char *s2, size_t n) {
    if (s1[0] == '#' && s1[1] == '#') {
        _GeneralFuncF1(1);
        KeypadLock();
        return -1;
    }
    return _strncmp(s1, s2, n);
}
