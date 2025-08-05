//EHeap
//(c)Dimadze

#include "eheap.h"

                    CODE16
#ifndef BROWSER
                    RSEG     PATCH_BROWSER_CREATE:CODE 
                    
                    NOP
                    NOP     
#endif

#ifndef MMSCLIENT
                    RSEG     PATCH_MMSCLIENT_CREATE:CODE 
                    
                    NOP
                    NOP              
#endif           
                    END