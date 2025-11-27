#pragma once

#include <stdint.h>

typedef union {
    uint16_t value;
    struct {
        uint16_t reserved: 7;
        uint16_t StatusSABM: 1;
        uint16_t StatusRACH: 1;
        uint16_t Accessory: 3;
        uint16_t HighSpeedSim: 1;
        uint16_t ClockStop: 1;
        uint16_t SimCard: 2;
    } fields;
} General;

typedef union {
    uint16_t value;
    struct {
        uint16_t reserved: 5;
        uint16_t AutoRoaming: 1;
        uint16_t Bluetooth: 1;
        uint16_t Gprs: 1;
        uint16_t Filter: 1;
        uint16_t AutoOff: 1;
        uint16_t Vibra: 1;
        uint16_t Light: 1;
        uint16_t Ringer: 1;
        uint16_t PowerSave: 1;
        uint16_t CellBroadcast: 1;
        uint16_t Irda: 1;
    } fields;
} Setup;

typedef union {
    uint16_t value;
    struct {
        uint16_t reserved: 4;
        uint16_t PBCCHSupported: 1;
        uint16_t Multiframe: 3;
        uint16_t RxLevel: 1;
        uint16_t Neighbours: 4;
        uint16_t PerLocUpdate: 1;
        uint16_t MobileState: 2;
    } fields;
} Network;

typedef union {
    uint16_t value;
    struct {
        uint16_t SpecialQuantisationCoding: 10;
        uint16_t Battery: 4;
        uint16_t AkkuType: 2;
    } fields;
} Battery;
