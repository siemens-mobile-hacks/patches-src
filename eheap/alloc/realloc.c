/*--------------------------------------------------------------------------
REALLOC.C is part of the CARM Compiler package from Keil Software.
Copyright KEIL ELEKTRONIK GmbH 1995 - 2005
--------------------------------------------------------------------------*/

#include <string.h>
#include <stdlib.h>

struct __mp__  {                   /* memory pool */
  struct __mp__   *next;           /* single-linked list */
  unsigned int      len;           /* length of following block */
};

extern struct __mp__ *mpool;      /* Memory Pool Header */
#define	HLEN	(sizeof(struct __mp__))

/*  Memory pool header:  __mp__ points to the first available.
 *
 *  Note that the list is maintained in address order.  __mp__ points to the
 *  block with the lowest address.  That block points to the block with the
 *  next higher address and so on.                                          */

#define MIN_BLOCK	(HLEN * 4)

extern void *eh_malloc (unsigned int size);
extern void  eh_free (void *memp);

void *eh_realloc (void *oldp, unsigned int size)  {
#define p   ((struct __mp__ *) oldp)   
#define p0  ((struct __mp__ *)&p[-1]) /* block to realloc */
  void *newp;

/*  Make sure that block is word aligned                                    */
  size = (size + 3) & ~3L;
  newp = eh_malloc (size);
  if (!newp) return (NULL);
  if (oldp)  {
    if (size > p0->len)  size = p0->len;
    memcpy (newp, oldp, size);
    eh_free (oldp);
  }
  return (newp);
}

