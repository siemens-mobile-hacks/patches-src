#include <swilib.h>
#include <swilib/patch.h>
#include "data.h"
#include "jvm_app.h"
#ifdef E71_45
    #include "E71_45.h"
#endif

#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _strncpy ((int (*)(char *, const char *, size_t))(ADDR_strncpy))

#define JVM_StartApplication ((int (*)(const char *path, const char *class, const JAM_APP *jam_app))(ADDR_JVM_StartApplication))

__attribute__((target("thumb")))
__attribute__((section(".text.JVM_StartApplication_Hook")))
int JVM_StartApplication_Hook(const char *path, const char *class, const JAM_APP *jam_app) {
    if (!(*data)) {
        *data = _malloc(sizeof(DATA));
        (*data)->slot1_name = _malloc(128);
        (*data)->slot1_name[0] = '\0';
        (*data)->slot2_name = _malloc(128);
        (*data)->slot2_name[0] = '\0';
    }
    const int success = JVM_StartApplication(path, class, jam_app);
    if (success && jam_app && jam_app->name) {
        const int count = *RamIsRunJava;
        if (count == 0) {
            _strncpy((*data)->slot1_name, jam_app->name, 127);
            (*data)->slot1_name[127] = '\0';
        } else {
            _strncpy((*data)->slot2_name, jam_app->name, 127);
            (*data)->slot2_name[127] = '\0';
        }
    }
    return success;
}

__attribute__((target("thumb")))
__attribute__((section(".text.GetLastJavaApplication")))
const char *GetLastJavaApp(int slot_id) {
    if (*data) {
        if (slot_id == 0) {
            return (*data)->slot1_name;
        } else if (slot_id == 1) {
            return (*data)->slot2_name;
        }
    }
    return NULL;
}
