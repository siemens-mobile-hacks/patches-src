#include <swilib.h>

#ifdef CL61_00
    #include "CL61_00.h"
#endif

#define _GBS_SendMessage ((void (*)(int cepid_to, int msg, ...))(ADDR_GBS_SendMessage))

__attribute__((target("thumb")))
__attribute__((section(".text.DisableNetwork")))
void DisableNetwork(void) {
    _GBS_SendMessage(0x403D, 5, 0, 0, 0);
}

__attribute__((target("thumb")))
__attribute__((section(".text.EnableNetwork")))
void EnableNetwork(void) {
    _GBS_SendMessage(0x403D, 6, 0, 0, 0);
}

#define SIM_GetType ((int (*)())(ADDR_SIM_GetType))
#define IDLE_OnCreate ((void (*)(CSM_RAM *))(ADDR_IDLE_OnCreate))

__attribute__((target("thumb")))
__attribute__((section(".text.Hook")))
void Hook(CSM_RAM *csm) {
    if (SIM_GetType() == 0) {
        DisableNetwork();
    }
    IDLE_OnCreate(csm);
}
