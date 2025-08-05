/*--------------------------------------------------------------------------
FREE.C is part of the CARM Compiler package from Keil Software.
Copyright (c) 1995 - 2005 Keil Software.  All rights reserved.
--------------------------------------------------------------------------*/

#include <stdlib.h>

struct __mp__  {                   /* memory pool */
  struct __mp__   *next;           /* single-linked list */
  unsigned int      len;           /* length of following block */
};

extern struct __mp__ *mpool;      /* Memory Pool Header */
extern void addstat(void *addr, int size);
extern void substat(void *addr, int size);
extern void inistat(void *addr, int size);

#define	HLEN	(sizeof(struct __mp__))

/*  Memory pool header:  __mp__ points to the first available.
 *
 *  Note that the list is maintained in address order.  __mp__ points to the
 *  block with the lowest address.  That block points to the block with the
 *  next higher address and so on.                                          */

void eh_free (void *memp)  {
/*  FREE attempts to organize Q, P0, and P so that Q < P0 < P.  Then, P0 is
 *  inserted into the free list so that the list is maintained in address
 *  order.
 *
 *  FREE also attempts to consolidate small blocks into the largest block
 *  possible.  So, after allocating all memory and freeing all memory,
 *  you will have a single block that is the size of the memory pool.  The
 *  overhead for the merge is very minimal.                                */

  struct __mp__ *q;                    /* ptr to free block */
  struct __mp__ *p;                    /* q->next           */
#define p0 ((struct __mp__ *) memp)    /* block to free */

/*  If the user tried to free NULL, get out now.  Otherwise, get the address
 *  of the header of the memp block (P0).  Then, try to locate Q and P such
 *  that Q < P0 < P.                                                       */

  if (!memp)  return;
  
  void *vmemp = memp;

  memp = &p0 [-1];                     /* get address of header */

/*  Initialize.  Q = Location of first available block.                    */
  q = mpool;
  if (!q)  {
    mpool   = p0;
    p0->next = NULL;
    return;
  }
  
  struct __mp__ *memps = (struct __mp__ *)memp;
  int vlen = memps->len;

/*  B1. When P0 before Q the block to free is before the first available
 *  block. Set P as Q, clear Q, initialize P0 as first available block.    */
  if (q > p0)  {
    mpool  = p0;
    p      = q;
    q      = NULL;
    substat(vmemp, vlen);
  } 
  else  {
/*  B2. Advance P. Hop through the list until we find a free block that is
 *  located in memory AFTER the block we're trying to free.                */
    while (1)  {
      p = q->next;
      if (!p || (p > memp))
       {
         substat(vmemp, vlen);
         break;
       }
      q = p;
    }
  }

/*  B3. Check upper bound. If P0 and P are contiguous, merge block P into
 *  block P0.                                                              */
  if (p && ((((char *)p0) + p0->len + HLEN) == (char *) p))  {
    p0->len += p->len + HLEN;
    p0->next = p->next;
  }
  else  {
    p0->next = p;
  }

/*  B4. Check lower bound. If Q and P0 are contiguous, merge P0 into Q.  */
  if (q)  {
    if ((((char *)q) + q->len + HLEN) == (char *) p0)  {
      q->len += p0->len + HLEN;
      q->next = p0->next;
    }
    else  {
      q->next = p0;
    }
  }
}
