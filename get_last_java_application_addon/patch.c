#include <swilib.h>
#include <swilib/patch.h>
#include "rb.h"
#include "jvm.h"
#include "data.h"
#ifdef E71_45
    #include "E71_45.h"
#endif

#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _mfree ((void (*)(void *))(ADDR_mfree))
#define _strcpy ((char *(*)(char *, const char *))(ADDR_strcpy))
#define _strncpy ((int (*)(char *, const char *, size_t))(ADDR_strncpy))

__attribute__((target("thumb")))
__attribute__((section(".text.GetLastJavaApplication")))
const char *GetLastJavaApp(const CSM_RAM *csm) {
    const RB_CSM *rb_csm = (RB_CSM *)csm;
    if (rb_csm->rb_id == 3) {
        return (const char*)rb_csm->unk1;
    }
    return NULL;
}

#define JVM_StartApplication ((int (*)(const char *path, const char *class, const JAM_APP *jam_app))(ADDR_JVM_StartApplication))

__attribute__((target("thumb")))
__attribute__((section(".text.JVM_StartApplication_Hook")))
int JVM_StartApplication_Hook(const char *path, const char *class, const JAM_APP *jam_app) {
    if (!(*data)) {
        *data = _malloc(sizeof(DATA));
        (*data)->last_name = _malloc(128);
        (*data)->last_name[0] = '\0';
    }
    const int success = JVM_StartApplication(path, class, jam_app);
    if (success && jam_app && jam_app->name) {
        _strncpy((*data)->last_name, jam_app->name, 127);
        (*data)->last_name[127] = '\0';
    } else {
        (*data)->last_name[0] = '\0';
    }
    return success;
}

#define RB_OnCreate ((void (*)(RB_CSM *))(ADDR_RB_OnCreate))
#define RB_OnMessage ((int (*)(RB_CSM *, GBS_MSG *))(ADDR_RB_OnMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.RB_OnCreate_Hook")))
void RB_OnCreate_Hook(RB_CSM *csm) {
    if (csm->rb_id == 3) {
        csm->unk1 = (int)_malloc(128);
        _strcpy((char*)csm->unk1, (*data)->last_name);
    }
    RB_OnCreate(csm);
}

__attribute__((target("thumb")))
__attribute__((section(".text.RB_OnMessage_Hook")))
int RB_OnMessage_Hook(RB_CSM *csm, GBS_MSG *msg) {
    const int result = RB_OnMessage(csm, msg);
    if (csm->rb_id == 3) {
        if (csm->csm.state == -3) {
            _mfree((void*)csm->unk1);
        }
    }
    return result;
}
