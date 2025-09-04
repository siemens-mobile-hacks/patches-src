#pragma once

#define ADDR_GetHeaderPointer (0xA0954E3D)
#define ADDR_ShowCallsList    (0xA0A82501)

#define ADDR_OnKey               (0xA0B2057C | 1)
#define HEADER_MISSED   (uint32_t*)(0xA0C7CFD0)
#define HEADER_RECEIVED (uint32_t*)(0xA0C7CFE4)
#define HEADER_DIALLED  (uint32_t*)(0xA0C7CFF8)
