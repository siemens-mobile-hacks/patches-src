//EHeap
//(c)Dimadze

#include "eheap.h"

                    EXTERN   RAMReMaping

                    EXTERN   eh_malloc
                    EXTERN   mfree_new

                    
                    EXTERN   zeroheap
                    
                    
                    CODE32
                    

                    RSEG     PATCH_SHEAP_SETUP:CODE 
                    
                    BL       sheap_setup


                    RSEG     CODE:CODE 
                    
                    PUBLIC   sheap_setup
                    
        sheap_setup:

                    PUSH    {R0-R4, LR}
                    
                    LDR      R3, =SHEAP_ADDR
                    STR      R3, [R0]
                    LDR      R0, =SHEAP_SIZE
                    STR      R0, [R1]
                    LDR      R0, =SHEAP_PSIZE
                    STR      R0, [R2]
                    
                    BLX      zeroheap
                    BLX      RAMReMaping

                    POP     {R0-R4, PC}
                    


                    END
                    
                    
                    
