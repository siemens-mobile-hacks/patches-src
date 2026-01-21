#pragma once

#define ADDR_IsAnyOfAccessoriesConnected (0xA053E95C)

#define ADDR_Set      (0xA04CB7A4)
#define ADDR_GetState (0xA00945A0 | 1)

#define ADDR_RamAccessoriesFlags (uint32_t*)(0xA8D9424C)

#define ACCESSORIES (uint8_t*)(0xA1381500)
