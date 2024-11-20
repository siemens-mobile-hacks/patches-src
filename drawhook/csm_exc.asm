//  Draw Hook //
//csm_exc.asm - Запрет работы патча на некоторых CSM для X75
//(c)Dimadze

#include "drawhook.h"

                    RSEG     CODE            

                    
                    CODE32   // Врубаем режим ARM
                    
                    PUBLIC   isCSMException
                    
    isCSMException:    
    
                    STMFD   SP!, {R1, LR}
                    SWI     0x8106
                    LDR     R0, [R0,#0x08]
                    LDR     R1, =EXC_CSM_MP
                    LDR     R0, [R0,#0x0C]
                    LDR     R0, [R0,#0x08]
                    CMP     R0, R1
                    LDRNE   R1, =EXC_CSM_ZP
                    CMPNE   R0, R1
                    MOVEQ   R0, #0x01
                    LDMEQFD SP!, {R1, PC}
                    MOV     R0, #0x00
                    LDMFD   SP!, {R1, PC}

                    END
