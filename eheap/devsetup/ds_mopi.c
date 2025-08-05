//EHeap - ds_mopi.c
//(C)Dimadze
//Вывод статистики в Dev Setup -> Mopi -> System Memory и в OverLay

#include "../eheap/eheap.h"

/*         EHeap - Статистика        */
extern unsigned int freeram;
extern unsigned int nfrags;
extern int *maxfrag_addr;
extern unsigned int maxfrag_size;

typedef struct {
  void *umalloc;
  void *rmalloc;
  int  *size_p1;
  int  *size_p2;
  int   size; 
  int   mode;     
}JHC_STRUCT;

extern JHC_STRUCT jhcs;

#define JALIGN(A) (char *)(((int)A&0xFFFFF000) + 0x1000)

//#include <stdio.h> - слишком много весит библиотечная sprintf :)
extern int sprintf(char *buf, char *str, ...);

__thumb void eheap_info(char *string, char *pattern, int total_perm, int free_perm)
{
  sprintf(string, "Permanent:\nSize: %d\nFree: %d\n\n"
                  "-------\n\n"
                  "EHeap Info:\n"
                  "EAddr: 0x%08X\n"
                  "ESize: 0x%08X\n"
                  "ESize: %u\n"
                  "EFree: %u\n"
                  "Frags: %u\n"
                  "MFrgAddr: 0x%08X\n"
                  "MFrgSize: %u\n\n"
                  "JHeap Info:\n"
                  "JHUAddr: 0x%08X\n"
                  "JHRAddr: 0x%08X\n"
                  "JHSize: %u\n",
                   total_perm, free_perm, EHEAP_ADDR, EHEAP_SIZE, EHEAP_SIZE,
                   freeram, nfrags, maxfrag_addr, maxfrag_size,
                   JALIGN(jhcs.umalloc), JALIGN(jhcs.rmalloc), jhcs.size);
}
