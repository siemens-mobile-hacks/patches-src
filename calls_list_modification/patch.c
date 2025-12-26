#include <swilib.h>
#include "calls_list.h"

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif


#define _CloseCSM ((void (*)(int))(ADDR_CloseCSM))
#define _LockSched ((void (*)())(ADDR_LockSched))
#define _UnlockSched ((void (*)())(ADDR_UnlockSched))
#define _MsgBoxError ((int (*)(int, int))(ADDR_MsgBoxError))
#define _FindCSMbyID ((CSM_RAM *(*)(int))(ADDR_FindCSMbyID))

#define _CSM_root() (ADDR_CSM_root)

__attribute__((always_inline))
inline void ShowError(int flag) {
    _MsgBoxError(flag, LGP_ID_NOT_POSSIBLE_AT_PRESENT);
}

__attribute__((target("thumb")))
__attribute__((section(".text.FindCSM")))
CSM_RAM *FindCSMByDesc(CSM_RAM *csm, CSM_DESC *csm_desc) {
    CSM_RAM *found = NULL;
    _LockSched();
    CSM_RAM *csm_ram = _CSM_root()->csm_q->csm.first;
    while (csm_ram) {
        if ((csm && csm_ram != csm || !csm) && csm_ram->constr == csm_desc) {
            found = csm_ram;
            break;
        }
        csm_ram = csm_ram->next;
    }
    _UnlockSched();
    return found;
}

#define CallsList_OnCreate ((int (*)(CALLS_LIST_CSM *))(ADDR_CallsList_OnCreate))

__attribute__((target("thumb")))
__attribute__((section(".text.CallsList_OnCreate_Hook")))
void CallsList_OnCreate_Hook(CALLS_LIST_CSM *csm) {
    CallsList_OnCreate(csm);
    CSM_RAM *found = FindCSMByDesc((CSM_RAM*)csm, CALLS_LIST_CSM_DESC);
    if (found) {
        // ShowError(0x11);
        _CloseCSM(found->id);
    }
}

#define CallsList_OnClose ((void (*)(CALLS_LIST_CSM *))(ADDR_CallsList_OnClose))

__attribute__((target("thumb")))
__attribute__((section(".text.CallsList_OnClose_Hook")))
void CallsList_OnClose_Hook(CALLS_LIST_CSM *csm) {
    if (csm->view_csm_id) {
        _CloseCSM(csm->view_csm_id);
    }
    if (csm->options_csm_id) {
        _CloseCSM(csm->options_csm_id);
    }
    CallsList_OnClose(csm);
}

#define CallsList_GHook ((void (*)(void *gui, int cmd))(ADDR_CallsList_GHook))

__attribute__((target("thumb")))
__attribute__((section(".text.CallsList_GHook_Hook")))
void CallsList_GHook_Hook(void *gui, enum UIDialogCmdID cmd) {
    if (cmd == UI_CMD_FOCUS) {
        CALLS_LIST_CSM *csm = (CALLS_LIST_CSM*)FindCSMByDesc(NULL, CALLS_LIST_CSM_DESC);
        if (csm) {
            CSM_RAM *csm_options = _FindCSMbyID(csm->options_csm_id);
            if (csm_options) {
                ShowError(0x1);
                return;
            }
        }
    }
    CallsList_GHook(gui, cmd);
}


#define CallsList_View_OnClose ((void (*)(CALLS_LIST_VIEW_CSM *))(ADDR_CallsList_View_OnClose))

__attribute__((target("thumb")))
__attribute__((section(".text.CallsList_View_OnClose_Hook")))
void CallsList_View_OnClose_Hook(CALLS_LIST_VIEW_CSM *csm) {
    if (csm->options_csm_id) {
        _CloseCSM(csm->options_csm_id);
    }
    CallsList_View_OnClose(csm);
}

#define CallsList_View_GHook ((void (*)(void *gui, int cmd))(ADDR_CallsList_View_GHook))

__attribute__((target("thumb")))
__attribute__((section(".text.CallsList_View_GHook_Hook")))
void CallsList_View_GHook_Hook(void *gui, enum UIDialogCmdID cmd) {
    if (cmd == UI_CMD_FOCUS) {
        CALLS_LIST_VIEW_CSM *csm = (CALLS_LIST_VIEW_CSM*)FindCSMByDesc(NULL, CALLS_LIST_VIEW_CSM_DESC);
        if (csm) {
            CSM_RAM *csm_options = _FindCSMbyID(csm->options_csm_id);
            if (csm_options) {
                ShowError(0x1);
                return;
            }
        }
    }
    CallsList_View_GHook(gui, cmd);
}

#define CallsList_Options_OnCreate ((void (*)(CALLS_LIST_OPTIONS_CSM *))(ADDR_CallsList_Options_OnCreate))
#define CallsList_Options_OnClose ((void (*)(CALLS_LIST_OPTIONS_CSM *))(ADDR_CallsList_Options_OnClose))

__attribute__((target("thumb")))
__attribute__((section(".text.CallsList_Options_OnCreate_Hook")))
void CallsList_Options_OnCreate_Hook(CALLS_LIST_OPTIONS_CSM *csm) {
    CallsList_Options_OnCreate(csm);
    csm->contacts_csm = 0;
}

__attribute__((target("thumb")))
__attribute__((section(".text.CallsList_Options_OnClose_Hook")))
void CallsList_Options_OnClose_Hook(CALLS_LIST_OPTIONS_CSM *csm) {
    if (csm->view_csm_id) {
        _CloseCSM(csm->view_csm_id);
    }
    if (csm->contacts_csm) {
        _CloseCSM(csm->contacts_csm);
    }
    CallsList_Options_OnClose(csm);
}
