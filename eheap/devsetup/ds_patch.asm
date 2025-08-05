//EHeap - ds_patch.asm
//(C)Dimadze
//Вывод статистики в Dev Setup -> Mopi -> System Memory и в OverLay
                    
                    EXTERN   GetFreeMemOfEHeapAvail
                    EXTERN   eheap_info
                    
                    CODE32
                    
                    RSEG     PATCH_DS_MOPI_SM:CODE
                    
                    BLX      eheap_info
                    
                    RSEG     PATCH_DS_OVERLAY_S:CODE 
                    
                    DC8      "EHeap Mem Avail"
                    
                    RSEG     PATCH_DS_OVERLAY_F:CODE 
                    
                    DC32     GetFreeMemOfEHeapAvail

                    
                    END