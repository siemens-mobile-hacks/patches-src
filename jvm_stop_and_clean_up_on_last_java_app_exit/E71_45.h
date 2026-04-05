#pragma once

#define ADDR_mfree           (0xA0092F93)

#define RamIsRunJava (int*)(0xA8EBC5B8)

#define ADDR_HandleMsg           (0xA0ACA948)
#define ADDR_MM_EnableJavaBoost  (0xA0A0720C)
#define ADDR_RAP_GBS_SendMessage (0xA09465B0 | 1)

#define JVM_Heap    ((JVM_HEAP*)(0xA8F42CB8))
#define JVM_Slot1_P (uint32_t**)(0xA8F09AE0)
#define JVM_Slot2_P (uint32_t**)(0xA8F09ADC)
