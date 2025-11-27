#include <swilib.h>

#ifdef C72_22
    #include "C72_22.h"
#endif
#ifdef CX70_56
    #include "CX70_56.h"
#endif
#ifdef S65_58
    #include "S65_58.h"
#endif
#ifdef CF75_23
    #include "CF75_23.h"
#endif

#define CEPID_MMS 0x4220
#define MESSAGE "MMS client is disabled!"

#define _CloseCSM ((void (*)(int))(ADDR_CloseCSM))
#define _MsgBoxError ((int (*)(int flag, int lgp_id))(ADDR_MsgBoxError))
#define _GetGBSProcAddress ((void *(*)(short cepid))(ADDR_GetGBSProcAddress))

__attribute__((target("thumb")))
__attribute__((section(".text.CreateOrClose")))
void CreateOrClose(CSM_RAM *csm, void (*OnCreate)(CSM_RAM *)) {
    if (_GetGBSProcAddress(CEPID_MMS)) {
        OnCreate(csm);
    } else {
        _MsgBoxError(0x11, (int)MESSAGE);
        _CloseCSM(csm->id);
    }
}

#define OnCreate_1 ((void (*)(CSM_RAM *))(ADDR_OnCreate_1))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_1")))
void Hook_1(CSM_RAM *csm) {
    CreateOrClose(csm, OnCreate_1);
}

#define OnCreate_2 ((void (*)(CSM_RAM *))(ADDR_OnCreate_2))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook_2")))
void Hook_2(CSM_RAM *csm) {
    CreateOrClose(csm, OnCreate_2);
}
