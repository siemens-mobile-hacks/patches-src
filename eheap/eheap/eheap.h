//(c)Dimadze
// EHeap

#ifdef CX75sw25

//Default Apps Setup

//#define BROWSER
//#define MMSCLIENT

//CutHeap Setup

#define CHEAP_ADDR  0xA8000000
#define CHEAP_SIZE  0x00000400

//System Heap Configuration

#ifndef MMSCLIENT
#define MMSC_FREEHEAP 0x20000
#else
#define MMSC_FREEHEAP 0x00000
#endif

#ifdef  BROWSER
#define SHEAP_NSIZ  0x00400000
#define EHEAP_BSUB  0x00100000
#else
#define SHEAP_NSIZ  0x00300000
#define EHEAP_BSUB  0x00000000
#endif

#define SHEAP_ADDR  CHEAP_ADDR+CHEAP_SIZE
#define SHEAP_SIZE  SHEAP_NSIZ-CHEAP_SIZE+MMSC_FREEHEAP
#define SHEAP_PSIZE 0x000E8000-MMSC_FREEHEAP


//Functions

#define MALLOC_ADDR 0xA0203C24
#define MFREE_ADDR  0xA0203C8C
#define WS_BRANCH   0xA07BD4BB
#define SPRINTF     0xA0EF3899


//EHeap Settings

#define EHEAP_ADDR  0xA9000000
#define EHEAP_SIZE  0x00AF0000-EHEAP_BSUB

//JHeap Settinhs

#define JHC_NULL  0xFEDCBA98
#define JHC_PATCH 0xF00FF00F
#define JHC_SIZE  0x0004B000
#define JHEAPSIZE_MIN 0x0004B000 // 300   κα
#define JHEAPSIZE_NRM 0x00177000 // 1500  κα
#define JHEAPSIZE_MAX 0x009C4000 // 10000 κα

#endif
