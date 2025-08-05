
#include "../eheap/eheap.h"



extern void *GetTBaseAddr();
extern void  UnLockAccess();

extern int   coarse_table[];

#include <string.h>

__thumb void RAMReMaping()
{
  UnLockAccess();
  int *trans_base = GetTBaseAddr();
 
  unsigned short selement = ((int)EHEAP_ADDR>>0x14)&0xFFF;
  
  memset((void *)coarse_table, 0, 0x400);
 
  for (int i = 0; i < 8; i++)
  {
   int k = selement + i;  
   trans_base[k] = (int)0xA8800000 + 0x100000*i + 0xE0E;
  }
  
  for (int i = 0x00; i < 0x79; i++)
  { 
     coarse_table[i] = (int)0xA8400000 + 0x1000*i + 0xFFE;
  }
  
  for (int i = 0x79; i < 0xA7; i++)
  { 
     coarse_table[i] = (int)0xA85D2000 + 0x1000*(i - 0x79) + 0xFFE;
  }
  
  for (int i = 0xA7; i < 0xFF; i++)
  { 
     coarse_table[i] = (int)0xA8700000 + 0x1000*(i - 0xA7) + 0xFFE;
  }
  
#ifndef BROWSER
  
  trans_base[selement + 0x08] = (int)0xA8300000   + 0xE0E; 
  trans_base[selement + 0x09] = (int)0xA8600000   + 0xE0E; 
  trans_base[selement + 0x0A] = (int)coarse_table + 0x011; 

#else
   
  trans_base[selement + 0x08] = (int)0xA8600000   + 0xE0E; 
  trans_base[selement + 0x09] = (int)coarse_table + 0x011; 
  
#endif
  
  extern __thumb void eheap_create();
  eheap_create();
}

