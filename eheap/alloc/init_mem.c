/*--------------------------------------------------------------------------
MALLOC.C is part of the CARM Compiler package from Keil Software.
Copyright (c) 1995 - 2005 Keil Software.  All rights reserved.
--------------------------------------------------------------------------*/

#include <stdlib.h>


struct __mp__  {                   /* memory pool */
  struct __mp__   *next;           /* single-linked list */
  unsigned int      len;           /* length of following block */
};

extern struct __mp__ *mpool;      /* Memory Pool Header */
extern void inistat(void *addr, int size);

#define	HLEN	(sizeof(struct __mp__))

/*  Memory pool header:  __mp__ points to the first available.
 *
 *  Note that the list is maintained in address order.  __mp__ points to the
 *  block with the lowest address.  That block points to the block with the
 *  next higher address and so on.                                          */


/* Initialize Block oriented memory pool */
void init_mempool (
  void *pool,                      /* address of the memory pool  */
  unsigned int size)  {            /* size of the pool in bytes   */

/*  Set the __mp__ to point to the beginning of the pool and set
 *  the pool size.                                                     */

    
  pool = (void *) (((unsigned int)pool+3)&~3);  // 25.7.2005
  mpool = (struct __mp__ *) pool;              // =========

/*  Set the link of the block in the pool to NULL (since it's the only
 *  block) and initialize the size of its data area.                   */

  ((struct __mp__ *) pool)->next       = NULL;
  ((struct __mp__ *) pool)->len        = size - HLEN;
  inistat(pool, size);
}
