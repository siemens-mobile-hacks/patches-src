//EHeap
//(c)Dimadze

#include "../eheap/eheap.h"

                    EXTERN   eh_malloc
                    EXTERN   mfree_new
                    
                    CODE32
                    
                    RSEG     PATCH_MALLOC
                    
                    BL       malloc_handler
                    
                   
                    RSEG     PATCH_MFREE
                    
                    BL       mfree_handler
                    
                    CODE16

                    RSEG     CODE:CODE 
                    
                    PUBLIC  AllocWS
                    
           AllocWS:
                    
                    LSL     R2, R0, #0x10
                    LSR     R2, R2, #0x10
                    LDR     R0, =eh_malloc
                    LDR     R1, =mfree_new
                    LDR     R3, =WS_BRANCH
                    BX      R3
                    
                    
                    CODE32
                    
                    RSEG     CODE:CODE 

   malloc_handler:
    
                    PUSH    {R1-R3, LR}
                    
                    BLX      eh_malloc
                    
                    POP     {R1-R3, PC}
                    
         
     mfree_handler:
     
                    PUSH    {R0-R3, LR}
                    
                    AND      R1, R0, #0xFF000000
                    LSR      R1, R1, #0x18
                    CMP      R1, #0xA9
                    BNE      mfh_skip
                    BLX      mfree_new  
                    
                    POP     {R0-R3, LR}
                    LDMFD    SP!, {R3-R7,PC}
                    
                    
          mfh_skip:
          
                    MOV      R5, #0
                    POP     {R0-R3, PC}

                    
                    
                    END
