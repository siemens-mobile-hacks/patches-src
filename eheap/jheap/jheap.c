//EHeap - jheap.c
//(C)Dimadze
//Java Heap Control для EHeap

#include "../eheap/eheap.h"
#include "string.h"

/* heap - functions */
extern void init_mempool(void *pool, unsigned int size);

extern void *eh_malloc (unsigned int size);
extern void  eh_free (void *memp);
extern void *eh_realloc (void *oldp, unsigned int size);
extern void *eh_calloc (unsigned int size, unsigned int len);

extern unsigned int CONFIG_CUR_JH_SIZE;


extern void InitConfig();

#pragma swi_number=0x4E
__swi __arm int MsgBoxError(int flag, int LgpId);



typedef struct {
  void *umalloc;  // Адрес пользовательского JavaHeap в EHeap
  void *rmalloc;  // Адрес резервного JavaHeap в EHeap
  int  *size_p1;  // Первый системный указатель на размер JavaHeap
  int  *size_p2;  // Второй системный указатель на размер JavaHeap
  int   size;     // Размер JavaHeap
  int   mode;     // Режим активности патча  /// 0xF00FF00F - патч установлен
                                            /// Все остальные значения -> патч не установлен
}JHC_STRUCT;

JHC_STRUCT jhcs = 
{
 (void *)-1,
 (void *)-1,
  0,
  0,
  JHC_SIZE,
  JHC_NULL
};

#define JALIGN(A) (char *)(((int)A&0xFFFFF000) + 0x1000)


__thumb int JHeapHook(int jh1, int *jheap_s1, int jh2, int *jheap_s2)
{
 InitConfig();
 
 char *jhm = 0;
 
 //Первая инициализация структуры JHC_STRUCT
 if (jhcs.mode != JHC_PATCH)
  {
   jhm = eh_malloc(CONFIG_CUR_JH_SIZE + 0x2000);
     
   if (jhm)
    {
     //Память на JHeap выделена
     jhcs.umalloc = (void *)jhm;
     jhcs.size_p1 = jheap_s1;
     jhcs.size_p2 = jheap_s2;
     
    *jheap_s1 = CONFIG_CUR_JH_SIZE;
    *jheap_s2 = CONFIG_CUR_JH_SIZE;
     
     jhcs.mode    = JHC_PATCH;
     jhcs.size    = CONFIG_CUR_JH_SIZE;
     
     return jhcs.size;
    } else 
      {
      RESERVED_HEAP_CREATE: 
        
       asm("NOP");
             
       jhm = eh_malloc(JHC_SIZE + 0x10000);
       if (jhm)
        {
           if (jhcs.umalloc != (void *)-1)
            {
             memcpy( JALIGN(jhm), JALIGN(jhcs.umalloc), JHC_SIZE);
             eh_free(jhcs.umalloc);
            }
          
          //Требуемая память на JHeap не выделена, резервный захват памяти
          jhcs.umalloc = (void *)jhm;
          jhcs.rmalloc = (void *)jhm;
          jhcs.size_p1 = jheap_s1;
          jhcs.size_p2 = jheap_s2;
     
         *jheap_s1 = JHC_SIZE;
         *jheap_s2 = JHC_SIZE;
     
          jhcs.mode    = JHC_PATCH;
          jhcs.size    = JHC_SIZE;
          
          MsgBoxError(1, (int)"EHeap:\nUsed reserved space!");
          return jhcs.size;
        } 
        // Ошибка системы => Крах
         else
           {
            jhcs.umalloc  = 0;
            jhcs.rmalloc  = 0;
            jhcs.size_p1  = 0;
            jhcs.size_p2  = 0;
     
           *jheap_s1 = 0;
           *jheap_s2 = 0;
     
            jhcs.mode    = 0;
            jhcs.size    = 0;
            
            MsgBoxError(1, (int)"EHeap:\nNo space - Crash!");
            return jhcs.size;
           }
      }
  }
   //Последующие действия
   else 
     {
      jhcs.size_p1 = jheap_s1;
      jhcs.size_p2 = jheap_s2;
      jhcs.mode    = JHC_PATCH;

      if ((int)jhcs.umalloc == (int)jhcs.rmalloc)
       {
         if (CONFIG_CUR_JH_SIZE > JHC_SIZE)
          {
           jhm = eh_malloc(CONFIG_CUR_JH_SIZE + 0x10000);
           if (jhm)
            {
             //Память на JHeap выделена
             jhcs.umalloc = (void *)jhm;

            *jheap_s1 = CONFIG_CUR_JH_SIZE;
            *jheap_s2 = CONFIG_CUR_JH_SIZE;

             jhcs.size    = CONFIG_CUR_JH_SIZE;
  
             return jhcs.size;
            }
            else
             {
              //Требуемая память на JHeap не выделена, резервное использование памяти
              jhcs.umalloc = jhcs.rmalloc;

             *jheap_s1 = JHC_SIZE;
             *jheap_s2 = JHC_SIZE;
      
              jhcs.size    = JHC_SIZE;
              
              MsgBoxError(1, (int)"EHeap:\nUsed reserved space!");   
          
              return jhcs.size;
             }
          }
       }
       else
        {
         if (CONFIG_CUR_JH_SIZE != jhcs.size)
          {
           if (CONFIG_CUR_JH_SIZE <= JHC_SIZE)
            {
             if (jhcs.rmalloc == (void *)-1) goto RESERVED_HEAP_CREATE;
             else 
              {
               // Резервное использование памяти
               jhcs.umalloc = jhcs.rmalloc;
  
              *jheap_s1 = JHC_SIZE;
              *jheap_s2 = JHC_SIZE;
      
               jhcs.size    = JHC_SIZE;
               
               MsgBoxError(1, (int)"EHeap:\nUsed reserved space!");          
               
               return jhcs.size;
              }
            } else 
               {
                char *jhm = eh_malloc(CONFIG_CUR_JH_SIZE + 0x10000);
                if (jhm)
                 {
                  memcpy( JALIGN(jhm), JALIGN(jhcs.umalloc),  jhcs.size);
                  eh_free(jhcs.umalloc);
                  
                  jhcs.umalloc = (void *)jhm;

                 *jheap_s1 = CONFIG_CUR_JH_SIZE;
                 *jheap_s2 = CONFIG_CUR_JH_SIZE;

                  jhcs.size   = CONFIG_CUR_JH_SIZE;
  
                  return jhcs.size;
                 } else
                   {
                     MsgBoxError(1, (int)"EHeap:\nNo Memory - old mode!");
                     return jhcs.size;
                   }
               }
          }
        }
     }
 return jhcs.size;
}

