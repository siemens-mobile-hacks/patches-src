/*--------------------------------------------------------------------------
MALLOC.C is part of the CARM Compiler package from Keil Software.
Copyright (c) 1995 - 2005 Keil Software.  All rights reserved.
--------------------------------------------------------------------------*/

#include <stdlib.h>


struct __mp__  {                   /* memory pool */
  struct __mp__   *next;           /* single-linked list */
  unsigned int      len;           /* length of following block */
};


/*  Addition   */

extern struct __mp__ *mpool;      /* Memory Pool Header */
extern void addstat(void *addr, int size);

/*  Addition   */


#define	HLEN	(sizeof(struct __mp__))

/*  Memory pool header:  __mp__ points to the first available.
 *
 *  Note that the list is maintained in address order.  __mp__ points to the
 *  block with the lowest address.  That block points to the block with the
 *  next higher address and so on.
 *
 *  Memory is laid out as follows:
 *
 *  {[NEXT | LEN] [BLOCK (LEN bytes)]} {[NEXT | LEN][BLOCK] } ...
 *
 *  Note that the size of a node is:
 *          mp.len + sizeof (struct mp_b)
 */


#define MIN_BLOCK	(HLEN * 4)

void *eh_malloc(unsigned int size)   {
  struct __mp__  *q;      /* ptr to free block */
  struct __mp__  *p;      /* q->next */
  unsigned int k;         /* space remaining in the allocated block */
 
/*  Make sure that block is word aligned                                    */
  size = (size + 3) & ~3L;

/*  Initialization:  Q is the pointer to the next available block.          */
  q = (struct __mp__ *) &mpool;

/*  End-Of-List:  P points to the next block.  If that block DNE (P==NULL),
 *  we are at the end of the list.                                          */

  while (1)  {
    p = q->next;
    if (!p)  return (NULL); /* FAILURE */

/*  Found Space:  If block is large enough, reserve if.  Otherwise, copy P
 *  to Q and try the next free block.                                       */
    if (p->len >= size) break;
    q = p;
  }

/*  Reserve P:  Use at least part of the P block to satisfy the allocation
 *  request.  At this time, the following pointers are setup:
 *  P points to the block from which we allocate Q->next points to P        */

  k = p->len - size;		/* calc. remaining bytes in block */

  if (k < MIN_BLOCK)  {		/* rem. bytes too small for new block */
    q->next = p->next;
    
    /*  Addition   */
    
    addstat((void *)&p[1], size);
    
    /*  Addition   */
    
    return (&p[1]);		    /* SUCCESS */
  }

/*  Split P Block:  If P is larger than we need, we split P into two blocks:
 *  the leftover space and the allocated space.  That means, we need to 
 *  create a header in the allocated space.                                 */

  k -= HLEN;
  p->len = k;

  q = (struct __mp__*) (((char *) (&p[1])) + k);
  q->len = size;
  
  /*  Addition   */
  
  addstat((void *)&q[1], size);
  
  /*  Addition   */
  
  return (&q[1]);           /* SUCCESS */
}
