//EHeap - stat.c
//(C)Dimadze
//Ф-ии для подсчёта статистики EHeap

struct __mp__  {                   /* memory pool */
  struct __mp__   *next;           /* single-linked list */
  unsigned int      len;           /* length of following block */
};

/*         EHeap - Статистика        */

extern struct __mp__ *mpool;
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


#define	HLEN	(sizeof(struct __mp__))


void addstat(void *addr, int size)
{
 nfrags++;
 if (maxfrag_addr)
  {
   if (size >= maxfrag_size) 
    {
     maxfrag_size = size;
     maxfrag_addr = (int *)addr;
    }
  }else
    {
     maxfrag_size = size;
     maxfrag_addr = (int *)addr;
    }
 
 if (freeram + size + HLEN > 0) freeram -= (size + HLEN);
}


void substat(void *addr, int size)
{
 if (nfrags) nfrags--;
 if (maxfrag_addr)
  {
   if ((int)addr == (int)maxfrag_addr) 
    {
     maxfrag_size = 0;
     maxfrag_addr = (int *)-1;
    }
  }else
    {
     maxfrag_size = 0;
     maxfrag_addr = (int *)-1;
    }
 
 freeram += (size + HLEN);
}

#include "../eheap/eheap.h"

void inistat(void *addr, int size)
{
 jhcs.umalloc = (void *)-1;
 jhcs.rmalloc = (void *)-1; 
 
 freeram = size - HLEN;
 nfrags = 0;
 maxfrag_addr = (void *)-1;
 maxfrag_size = 0;
}
