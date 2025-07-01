#ifdef NEWSGOLD
    #ifdef ELKA
        #ifdef E71_45
            #include "E71_45.h"
        #endif
        #define GetNetworkState ((int (*)())(ADDR_GetNetworkState))
        #define NETWORK_ICON 596
    #endif
#else
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #ifdef CX70_56
        #include "CX70_56.h"
    #endif
    #define GetNetworkState() (*ADDR_RamNetworkState)
#endif

#define _GetNetworkIcon ((int (*)())(ADDR_GetNetworkIcon))

__attribute__((target("thumb")))
__attribute__((section(".text.GetNetworkIcon")))
int GetNetworkIcon() {
    #ifdef NEWSGOLD
        return (GetNetworkState() == 2) ? NETWORK_ICON : _GetNetworkIcon();
    #else
        return (GetNetworkState() == 4) ? NETWORK_ICON : _GetNetworkIcon();
    #endif
}
