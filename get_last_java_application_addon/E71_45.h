#pragma once

#define ADDR_malloc  (0xA0092F51)
#define ADDR_mfree   (0xA0092F93)
#define ADDR_strcpy  (0xA122AF05)
#define ADDR_strncpy (0xA122B051)

#define RamIsRunJava (int*)(0xA8EBC5B8)

#define ADDR_RB_OnCreate          (0xA0A1CDD4 | 1)
#define ADDR_RB_OnMessage         (0xA0A1CCC2 | 1)
#define ADDR_JVM_StartApplication (0xA0ACB40C)

#define data ((DATA**)(0xA8E37368))
