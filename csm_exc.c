//  Draw Hook //
//csm_exc.c - Запрет работы патча на некоторых CSM для X75
//(c)Dimadze

#include "drawhook.h"



typedef struct{
#ifdef NEWSGOLD
  int pid_from;
  int msg;
#else
  short pid_from;
  short msg;
#endif
  int submess;
  void *data0;
  void *data1;
} GBS_MSG;

typedef struct
{
  void *first;
  void *last;
  void (*data_mfree)(void *);
}LLQ;

typedef struct{
  void *next;
  void *prev;
  void /*CSM_DESC*/ *constr;
  int id;
  int state;
  int unk1;
  int unk2;
  LLQ gui_ll;
} CSM_RAM;

typedef struct{
  int (*onMessage)(CSM_RAM*,GBS_MSG*);
  void (*onCreate)(CSM_RAM*);
#ifdef NEWSGOLD
  int zero1;
  int zero2;
  int zero3;
  int zero4;
#endif
  void (*onClose)(CSM_RAM*);
  int datasize;
  int statesize;
  const int *states;
} CSM_DESC;


#ifdef NEWSGOLD
typedef struct{
  int id;
  CSM_RAM *current_msg_processing_csm;
  LLQ csm;
  LLQ cmd;
  LLQ csm_background;
} CSMQ;
#else
typedef struct{
  int id;
  CSM_RAM *current_msg_processing_csm;
  LLQ csm;
  LLQ cmd;
  int unk;
  int unk1;
  void *methods;
  int unk2;
  void *tmr;
  short cepid;
} CSMQ;
#endif

typedef struct{
  int under_idle_id;
  int idle_id;
  CSMQ *csm_q;
} CSMROOT;

#pragma swi_number=0x8106
__swi __arm CSMROOT *CSM_root();

__arm int isCSMException() //CSM = addr CSM of CSMList.txt, 1 = CSM on top
{
  asm("PUSH {R1}");
  CSM_RAM *csm = CSM_root()->csm_q->csm.last;
  CSM_DESC *desc = csm->constr;
  if (EXC_CSM_MP == (int)desc || EXC_CSM_ZP == (int)desc)
   {
     asm("POP {R1}");
     return 1;
   }  else
       {
        asm("POP {R1}");
        return 0;
       }
}
