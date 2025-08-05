//EHeap - jhook.asm
//(C)Dimadze
//Вывод статистики в Dev Setup -> Mopi -> System Memory и в OverLay

#include "../eheap/eheap.h"

                    EXTERN  jhcs
                    EXTERN  JHeapHook

                    CODE32  // Врубаем режим ARM
                    
                    RSEG    JHC_SETJHVARI:CODE 
                    
                    BL      setHeapVars
                    

                    RSEG    JHC_GETJHADDR:CODE 
                    
                    BL      getHeapAddr
                    
                    
                    RSEG    CODE:CODE

       getHeapAddr:
       
                    BIC     R0, R0, #0x7F
                    
                    //Загружаем aдрес JavaHeap
                    LDR     R2, =jhcs
                    LDR     R2, [R2, #0x00]
                    
                    //Иначе его нужно немного "округлить", а то телефон пикоффит
                    MOV     R0, R2
                    BIC     R0, R0, #0xFF0
                    BIC     R0, R0, #0x00F
                    ADD     R0, R0, #0x1000
                    BX      LR
                    
                    
                    
       setHeapVars:

                    PUSH   {R1-R3, LR}

                    BLX     JHeapHook
                    
                    MOV     R11, R0 
                    
                    POP    {R1-R3, PC}
                    
                    END