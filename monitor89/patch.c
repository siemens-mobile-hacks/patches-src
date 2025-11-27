#include <swilib.h>
#include "cc_mon.h"

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

#define _udiv ((uint32_t (*)(uint32_t, uint32_t))(ADDR_udiv))
#define _malloc ((void *(*)(size_t))(ADDR_malloc))
#define _mfree  ((void (*)(void *))(ADDR_mfree))
#define _strtoul ((int (*)(const char *, char *, int base))(ADDR_strtoul))
#define _sprintf ((void (*)(char *, const char *, ...))(ADDR_sprintf))
#define _AllocWS ((WSHDR *(*)(size_t))(ADDR_AllocWS))
#define _wsprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wsprintf))
#define _RefreshGUI ((void (*)())(ADDR_RefreshGUI))
#define _SetSoftKey ((void (*)(void *, SOFTKEY_DESC *, int))(ADDR_SetSoftKey))
#define _TViewSetText ((void (*)(void *, const WSHDR *, void *, void *))(ADDR_TViewSetText))
#define _wstrcatprintf ((void (*)(WSHDR *, const char *, ...))(ADDR_wstrcatprintf))
#define _GeneralFuncF1 ((void (*)(int))(ADDR_GeneralFuncF1))
#define _SetHeaderText ((void (*)(void *, WSHDR *, void *, void *))(ADDR_SetHeaderText))
#define _GetHeaderPointer ((void *(*)(void *))(ADDR_GetHeaderPointer))

#define flag gui->unk2

__attribute__((target("thumb")))
__attribute__((section(".text.GetBoolean")))
const char *GetBoolean(uint16_t value) {
    return (value) ? "1" : "0";
}

__attribute__((target("thumb")))
__attribute__((section(".text.GetBoolean")))
const char *GetOnOff(uint16_t value) {
    return (value) ? "On" : "Off";
}

__attribute__((target("thumb")))
__attribute__((section(".text.AddElement")))
void AddElement(WSHDR *ws, const char *title, const char *value) {
    _wstrcatprintf(ws, "%c%s:%c\n%c%s\n%c", UTF16_FONT_SMALL, title, UTF16_FONT_RESET, UTF16_FONT_SMALL_BOLD, value, UTF16_FONT_RESET);
}

__attribute__((target("thumb")))
__attribute__((section(".text.AddIntegerElement")))
void AddIntegerElement(WSHDR *ws, const char *title, int value) {
    _wstrcatprintf(ws, "%c%s:%c\n%c%d\n%c", UTF16_FONT_SMALL, title, UTF16_FONT_RESET, UTF16_FONT_SMALL_BOLD, value, UTF16_FONT_RESET);
}

__attribute__((always_inline))
__attribute__((target("thumb")))
inline void SetGeneralText(WSHDR *ws, uint16_t value) {
    General general;
    general.value = value;

    const char *sim_card;
    if (general.fields.SimCard == 0) {
        sim_card = "no Card";
    } else if (general.fields.SimCard == 1) {
        sim_card = "5V";
    } else if (general.fields.SimCard == 2) {
        sim_card = "3V";
    } else if (general.fields.SimCard == 3) {
        sim_card = "Reserved";
    } else {
        sim_card = "Unknown";
    }
    AddElement(ws, "SimCard", sim_card);
    AddElement(ws, "ClockStop", GetBoolean(general.fields.ClockStop));
    AddElement(ws, "HighSpeedSim", GetBoolean(general.fields.HighSpeedSim));
    // const char *accessory;
    // if (general.fields.Accessory == 0) {
    //     accessory = "no Accessory";
    // } else if (general.fields.Accessory == 1) {
    //     accessory = "DataCable";
    // } else if (general.fields.Accessory == 2) {
    //     accessory = "Bluetooth";
    // } else if (general.fields.Accessory == 7) {
    //     accessory = "Unknown";
    // } else {
    //     accessory = "Reserved";
    // }
    // AddElement(ws, "Accessory", accessory);
    AddElement(ws, "StatusRACH", GetBoolean(general.fields.StatusRACH));
    AddElement(ws, "StatusSABM", GetBoolean(general.fields.StatusSABM));
}

__attribute__((always_inline))
__attribute__((target("thumb")))
inline void SetSetupText(WSHDR *ws, uint16_t value) {
    Setup setup;
    setup.value = value;
    AddElement(ws, "Irda", GetOnOff(setup.fields.Irda));
    AddElement(ws, "CellBroadcast", GetOnOff(setup.fields.CellBroadcast));
    AddElement(ws, "PowerSave", GetOnOff(setup.fields.PowerSave));
    AddElement(ws, "Ringer", GetOnOff(setup.fields.Ringer));
    AddElement(ws, "Light", GetOnOff(setup.fields.Light));
    AddElement(ws, "Vibra", GetOnOff(setup.fields.Vibra));
    AddElement(ws, "AutoOff", GetOnOff(setup.fields.AutoOff));
    AddElement(ws, "Filter", GetOnOff(setup.fields.Filter));
    AddElement(ws, "Gprs", GetOnOff(setup.fields.Gprs));
#ifdef HAS_BT
    AddElement(ws, "Bluetooth", GetOnOff(setup.fields.Bluetooth));
#endif
    AddElement(ws, "AutoRoaming", GetOnOff(setup.fields.AutoRoaming));
}

__attribute__((always_inline))
__attribute__((target("thumb")))
inline void SetNetworkText(WSHDR *ws, uint16_t value) {
    Network network;
    network.value = value;
    const char *state;
    if (network.fields.MobileState == 0) {
        state = "Idle";
    } else if (network.fields.MobileState == 1) {
        state = "Call";
    } else if (network.fields.MobileState == 2) {
        state = "Scan";
    } else if (network.fields.MobileState == 3) {
        state = "Reversed";
    } else {
        state = "Unknown";
    }
    AddElement(ws, "MobileState", state);
    AddElement(ws, "PerLocUpdate", GetOnOff(network.fields.PerLocUpdate));
    AddIntegerElement(ws, "Neighbours", network.fields.Neighbours);
    AddElement(ws, "RxLevel", (network.fields.RxLevel) ? "<= -95 dBm" : "> -95 dBm");
    AddIntegerElement(ws, "Multiframe", network.fields.Multiframe);
    AddElement(ws, "PBCCHSupported", (network.fields.PBCCHSupported) ? "Yes and active" : "No");
}

__attribute__((always_inline))
__attribute__((target("thumb")))
inline void SetBatteryText(WSHDR *ws, uint16_t value) {
    Battery battery;
    battery.value = value;
    /*const char *akku_type;
    if (battery.fields.AkkuType == 0) {
        akku_type = "NiH";
    } else if (battery.fields.AkkuType == 1) {
        akku_type = "LiI";
    } else if (battery.fields.AkkuType == 2) {
        akku_type = "LiP";
    } else if (battery.fields.AkkuType == 3) {
        akku_type = "Reserve";
    } else {
        akku_type = "Unknown";
    }
    AddElement(ws, "AkkuType", akku_type);*/
    char *cap = _malloc(16);
    _sprintf(cap, "%d%%", *ADDR_RamCap);
    AddElement(ws, "Battery", cap);
    _mfree(cap);
    int16_t charge_count = -1 - *ADDR_RamChargeCount;
    AddIntegerElement(ws, "ChargeCount", charge_count);
    AddIntegerElement(ws, "ChargeBroken", (-1 - *ADDR_RamChargeBroken) + charge_count);
    AddIntegerElement(ws, "ChargeFast", -1 - *ADDR_RamChargeFast);
}

#define GetExStat ((uint16_t (*)(int))(ADDR_GetExStat))
#define GetOpTime ((int (*)())(ADDR_GetOpTime))
#define GetTalkTime ((int (*)())(ADDR_GetTalkTime))

__attribute__((always_inline))
__attribute__((target("thumb")))
inline void SetDiagnosisText(WSHDR *ws) {
    AddIntegerElement(ws, "Turnoffs", GetExStat(1));
    AddIntegerElement(ws, "Exits", GetExStat(2));
    AddIntegerElement(ws, "Restarts", GetExStat(4));
    int op_time = GetOpTime();
    AddIntegerElement(ws, "OpTime", _udiv(0x15180, op_time));
    int talk_time = GetTalkTime();
    AddIntegerElement(ws, "TalkTime", _udiv(0xE10, talk_time));
}

#define OnKey ((int (*)(void *, GUI_MSG *))(ADDR_OnKey))
#define PhoneStatus_CreateUI ((int (*)(int))(ADDR_PhoneStatus_CreateUI))

__attribute__((target("thumb")))
__attribute__((section(".text.OnKey_Hook")))
int OnKey_Hook(GUI *gui, GUI_MSG *msg) {
    if (msg->keys == 0x3D || msg->keys == 0x1) {
        if (flag) {
            _GeneralFuncF1(1);
            PhoneStatus_CreateUI(2);
            return -1;
        }
    } else if (msg->gbsmsg->msg == KEY_DOWN) {
        int key = msg->gbsmsg->submess;
        if (key >= '1' && key <= '5') {
            if (!flag) {
                //" ####  General  \r ####  Setup    \r ####  Network  \r ####  Battery  \r ####  Diagnosis\r"
                char *s = ADDR_RamCCMon;
                WSHDR *text = _AllocWS(256);
                int keycode = key - '0';
                if (keycode <= 3) {
                    if (keycode == 1) {
                        uint16_t general = _strtoul(s + 1, 0, 16);
                        SetGeneralText(text, general);
                    } else if (keycode == 2) {
                        uint16_t setup = _strtoul(s + 18, 0, 16);
                        SetSetupText(text, setup);
                    } else if (keycode == 3) {
                        uint16_t network = _strtoul(s + 35, 0, 16);
                        SetNetworkText(text, network);
                    }
                } else {
                    if (keycode == 4) {
                        uint16_t battery = _strtoul(s + 52, 0, 16);
                        SetBatteryText(text, battery);
                    } else if (keycode == 5) {
                        SetDiagnosisText(text);
                    }
                }
                _TViewSetText(gui, text, ADDR_malloc, ADDR_mfree);
                flag = keycode;
                _RefreshGUI();
                return -1;
            }
        }
    }
    return OnKey(gui, msg);
}

__attribute__((target("thumb")))
__attribute__((section(".text.GHook")))
void GHook(GUI *gui, enum UIDialogCmdID cmd) {
    if (cmd == TI_CMD_REDRAW) {
        WSHDR *title = _AllocWS(64);
        void *header = _GetHeaderPointer(gui);
        if (flag) {
            if (flag <= 3) {
                if (flag == 1) {
                    _wsprintf(title, "General");
                } else if (flag == 2) {
                    _wsprintf(title, "Setup");
                } else if (flag == 3) {
                    _wsprintf(title, "Network");
                }
            } else {
                if (flag == 4) {
                    _wsprintf(title, "Battery");
                } else if (flag == 5) {
                    _wsprintf(title, "Diagnosis");
                }
            }
            _SetSoftKey(gui, ADDR_SOFTKEY_LEFT, SET_RIGHT_SOFTKEY); // LEFT!
        } else {
            _wsprintf(title, "Monitor89");
        }
        _SetHeaderText(header, title, ADDR_malloc, ADDR_mfree);
    }
}
