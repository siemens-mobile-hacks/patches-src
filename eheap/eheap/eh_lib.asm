//EHeap - eh_lib.asm
//(C)Dimadze
//Библиотека необходимых прошивочных и сопроцессорных ф-ий

#include "eheap.h"
                 
                    CODE32
                    
                    RSEG     CODE:CODE
                    
                    PUBLIC   malloc_old
                    
        malloc_old:
       
                    LDR     R12, =MALLOC_ADDR
                    BX      R12
                     
                    PUBLIC   mfree_old
                    
         mfree_old:
       
                    LDR     R12, =MFREE_ADDR
                    BX      R12
                    
                    PUBLIC  sprintf
                    
           sprintf:
       
                    LDR     R12, =SPRINTF
                    BX      R12
                    
                  
                    //Возвращает адрес базы трансляции
                    PUBLIC   GetTBaseAddr
            
     GetTBaseAddr:
              
 	            STR	     LR, [SP, #-0x04]!
	            MRS	     R2,  CPSR
            
#ifdef NEWSGOLD
	            SWI      0x04
#else
	            SWI      0x00
#endif

	            MRS      R1, CPSR
	            ORR      R1, R1,#0xC0
	            MSR      CPSR_c, R1
           
                    MOV      R0, #0
                    MRC      p15, 0, R0, c2, c0 //R0 = 0x90000 (SGold), R0 = 0x8C000 (ELKA) 
                  
	            MSR	     CPSR_c,R2
	            LDR	     PC,[SP], #+0x04
                  
            
            

                  
                    PUBLIC   UnLockAccess
                  
      UnLockAccess:
     
 	            STR	     LR, [SP, #-0x04]!
	            MRS	     R2,  CPSR
            
#ifdef NEWSGOLD
	            SWI      0x04
#else
	            SWI      0x00
#endif

	            MRS      R1, CPSR
	            ORR      R1, R1,#0xC0
	            MSR      CPSR_c, R1
           
                    MOV      R0, #0xFFFFFFFF
                    MCR      p15, 0, R0, c3, c0 
                  
                    NOP
	            NOP
	            NOP
	            NOP
                    NOP
	            NOP
	            NOP
	            NOP
                    NOP
	            NOP
	            NOP
	            NOP
                    NOP
	            NOP
	            NOP
	            NOP
                   
	            MSR	     CPSR_c,R2
	            LDR	     PC,[SP], #+0x04
                    
                    
                    END