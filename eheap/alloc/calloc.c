/*--------------------------------------------------------------------------
CALLOC.C is part of the CARM Compiler package from Keil Software.
Copyright (c) 1995 - 2005 Keil Software.  All rights reserved.
--------------------------------------------------------------------------*/

#include <string.h>
#include <stdlib.h>

extern void *eh_malloc (unsigned int size);

void *eh_calloc(unsigned int size, unsigned int len)  {
  void *p;

  size *= len;
  p = eh_malloc (size);
  if (p) memset (p, 0, size);
  return (p);
}

