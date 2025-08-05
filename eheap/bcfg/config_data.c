#include "conf_loader.h"
#include "../eheap/eheap.h"

//Конфигурация


__root CFG_HDR cfghdr1={CFG_UINT, "Current JH Size", JHEAPSIZE_MIN, JHEAPSIZE_MAX};
__root unsigned int CONFIG_CUR_JH_SIZE = JHEAPSIZE_NRM;

