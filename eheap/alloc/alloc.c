
#include "../eheap/eheap.h"

/* heap - functions */
extern void init_mempool(void *pool, unsigned int size);

extern void *eh_malloc (unsigned int size);
extern void  eh_free (void *memp);
extern void *eh_realloc (void *oldp, unsigned int size);
extern void *eh_calloc (unsigned int size, unsigned int len);

extern void  AllocWS();

extern void *malloc_old(int size);
extern void  mfree_old(void *pnt);


#define malloc  eh_malloc
#define free    eh_free
#define realloc eh_realloc
#define calloc  eh_calloc

/* Заголовок блока */
struct __mp__  {                   /* memory pool */
  struct __mp__   *next;           /* single-linked list */
  unsigned int      len;           /* length of following block */
};

//Таблицы переадресации
int coarse_table[0x100];

//Статистика
struct __mp__ *mpool = 0;
unsigned int nfrags = 0;
int *maxfrag_addr = 0;
unsigned int maxfrag_size = 0;

unsigned int freeram = 0;


__thumb int GetFreeMemOfEHeapAvail()
{
 return freeram;
}

__thumb void mfree_new(void *pnt)
{
 if (((int)pnt&0xFF000000)>>0x18 == 0xA9) free(pnt);
 else mfree_old(pnt);
}


#include <string.h>

__thumb void eheap_create()
{
 //memset((void *)EHEAP_ADDR, 0, EHEAP_SIZE);
 init_mempool((void *)EHEAP_ADDR, EHEAP_SIZE);
}

#pragma diag_suppress=Pe177
__root static const int SWI_MALLOC  @ "SWI_MALLOC"   = (int)malloc;
__root static const int SWI_MFREE   @ "SWI_MFREE"    = (int)mfree_new;
__root static const int SWI_REALLOC @ "SWI_REALLOC"  = (int)realloc;
__root static const int SWI_CALLOC  @ "SWI_CALLOC"   = (int)calloc;

__root static const int SWI_ALLOCWS @ "SWI_ALLOCWS"  = (int)AllocWS;

__root static const int SWI_GETFREE @ "SWI_GETFREE"  = (int)GetFreeMemOfEHeapAvail;

#pragma diag_default=Pe177
