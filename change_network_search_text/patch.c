#include <swilib.h>

#ifdef NEWSGOLD
    #ifdef ELKA
        #ifdef E71_45
            #include "E71_45.h"
        #endif
    #endif
    #define GetNetworkState ((int (*)())(ADDR_GetNetworkState))
    #define NETWORK_STATE_OFFLINE 2
#else
    #ifdef S65_58
        #include "S65_58.h"
    #endif
    #define GetNetworkState() (*ADDR_RamNetworkState)
    #define NETWORK_STATE_OFFLINE 4
#endif

#define _GetLangMesIntoWS ((void (*)(int lgp_id, WSHDR *ws))(ADDR_GetLangMesIntoWS))
#define _wstrcapitalize ((int (*)(WSHDR *ws))(ADDR_wstrcapitalize))
#define _wsprintf ((void (*)(WSHDR *ws, const char *format, ...))(ADDR_wsprintf))

__attribute__((target("thumb")))
__attribute__((section(".text.IDLE_SetLangMesIntoWS")))
void IDLE_SetLangMesIntoWS(int lgp_id, WSHDR *ws) {
    if (lgp_id == LGP_ID_CATCH) {
        if (GetNetworkState() == NETWORK_STATE_OFFLINE) {
            _GetLangMesIntoWS(LGP_ID, ws);
            #ifdef NEWSGOLD
                _wstrcapitalize(ws);
            #endif
            return;
        }
    }
    _GetLangMesIntoWS(lgp_id, ws);
}

__attribute__((target("thumb")))
__attribute__((section(".text.ScreenSaver_SetLangMesIntoWS")))
#ifdef NEWSGOLD
    void ScreenSaver_SetLangMesIntoWS(WSHDR *ws, const char *format, int lgp_id, void *r3) {
        if (lgp_id == LGP_ID_CATCH) {
            if (GetNetworkState() == NETWORK_STATE_OFFLINE) {
                _wsprintf(ws, format, LGP_ID, r3);
                _wstrcapitalize(ws);
                return;
            }
        }
        _wsprintf(ws, format, lgp_id, r3);
    }
#else
    void ScreenSaver_SetLangMesIntoWS(int lgp_id, WSHDR *ws) {
        if (lgp_id == LGP_ID_CATCH) {
            if (GetNetworkState() == NETWORK_STATE_OFFLINE) {
                _GetLangMesIntoWS(LGP_ID, ws);
                return;
            }
        }
        _GetLangMesIntoWS(lgp_id, ws);
    }
#endif
