#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef E71_45
        #include "E71_45.h"
    #endif
#endif

#define _GetHeaderPointer ((void *(*)(void *))(ADDR_GetHeaderPointer))
#define _ShowCallList ((void (*)(int, int))(ADDR_ShowCallsList))

#define _OnKey ((int (*)(void *, GUI_MSG *))(ADDR_OnKey))

__attribute__((target("thumb")))
__attribute__((section(".text.OnKey_Hook")))
int OnKey_Hook(void *gui, GUI_MSG *msg) {
    WIDGET *header = _GetHeaderPointer(gui);
    void *header_definition = header->definition;
    if (msg->keys == 0x28) { // LEFT_BUTTON
        if (header_definition == HEADER_DIALLED) {
            _ShowCallList(0, 0); // missed
        } else if (header_definition == HEADER_RECEIVED) {
            _ShowCallList(2, 0); // dialled
        } else if (header_definition == HEADER_MISSED) {
            _ShowCallList(1, 0); // received
        }
        return 1;
    } else if (msg->keys == 0x27) { // RIGHT_BUTTON
        if (header_definition == HEADER_DIALLED) {
            _ShowCallList(1, 0); // received
        } else if (header_definition == HEADER_RECEIVED) {
            _ShowCallList(0, 0); // missed
        } else if (header_definition == HEADER_MISSED) {
            _ShowCallList(2, 0); // dialled
        }
        return 1;
    }
    return _OnKey(gui, msg);
}
