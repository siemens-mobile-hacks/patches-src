
#include "eheap.h"

__thumb void zeroheap()
{
 int *cheap = (int *)CHEAP_ADDR;
 for (int i = 0; i < CHEAP_SIZE/4; i++) cheap[i] = 0;
}
