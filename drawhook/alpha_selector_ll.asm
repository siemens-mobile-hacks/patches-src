//  Draw Hook //
//alpha_selector_ll.asm - ����� �������������� �������� (LONG LINK) �� ��������, ��� ������ �� ������� �� ���� �����
//(c)Dimadze

#include "drawhook.h"

                    EXTERN FuncDistributor_0x05
                    EXTERN FuncDistributor_0x17
#ifdef X75
                    EXTERN isCSMException
#endif
                    
                    CODE16  // ������� ����� THUMB
                    
// ����� ���� ����������� IMGHDR

                    RSEG    PATCH_DRAWOBJECT_OBJ05:CODE
                    
                    PUSH   {R4-R7,LR} // ���������������  ������� ������� 
                    BLX     img_05_check_j32 
                   
                    
// ����� ���� ����������� EIMGHDR

                    RSEG    PATCH_DRAWOBJECT_OBJ17:CODE 
                    
                    PUSH   {R4-R7,LR} // ���������������  ������� ������� 
                    BLX     img_17_check_j32
                    
// ��������
                    
                    CODE32
                    
                    RSEG    PATCH_DRAWOBJECT_OBJ05_J32:CODE 
                    
  img_05_check_j32:
                    
                    B       img_05_check
                    
                    
                    RSEG    PATCH_DRAWOBJECT_OBJ17_J32:CODE 
                    
  img_17_check_j32:
                    
                    B       img_17_check
                    
                    
//��������������
                    
                    RSEG    PATCH_REPAIRJUMP100:CODE 
                    
                    B       loc_jump_swi100
                    
                    RSEG    PATCH_REPAIRJUMP145:CODE 
                    
                    B       loc_jump_swi145
                    
                    
                    RSEG    PATCH_LOCALJUMP100:CODE 

   loc_jump_swi100:    
                    
                    
                    RSEG    PATCH_LOCALJUMP145:CODE 

   loc_jump_swi145:    

                           

// ��, � ��� � ��� ��������� ��������
// ����� ���������� ���������� ����������� �� �������������� � �������
// ���������� ���������� ��� ����� �-�� ��������� 

       
                    RSEG PATCH_BODY:CODE
                    
       img_05_check: // �������� �� ����������� ������ �������� � ������
    
                    MOV    R5, R0          // ������������� ��������
                    MOV    R4, R1          // ������������� ��������
                    
                    // R0 = SCREEN_STRUCT
                    // R1 = DRAWOBJ_05
                    
 
                    PUSH  {R0-R2,LR}       // ������ ���� �����������, ���� �� ��� ...
    
#ifdef X75
                    BL     isCSMException  // ���������, � CSM ������� "�� �����" �� ����������?
                    CMP    R0, #0x01
                    MOV    R0, R5 
                    BEQ    is_csm_exc_05   // ����������, ����� ��������� ...
#endif
    
                    LDR    R2, [R1, #0x14] // R2 = IMGHDR *img
                    LDRB   R2, [R2, #0x02] // R2 = img->bpnum 
                    
                    BIC    R2, R2, #0xF0   // ������� 4-8 ����, �.�. ����� ����� 0xXA ����� ��� 0x0A
                    
                    CMP    R2, #0x0A       // ���������, ��� �� �����-������?
                    BNE    not_alpha_05    // � ����������� �� �������� ������
                    
                    // ���, �����-����� ����! ������ ����� ����-������� ...
                    MOV    R1, R0          // ������ ����� ��������� SCREEN_STRUCT
                    MOV    R0, R4          // ������ ����� ��������� DRWOBJ_05
                    LDR    R2, =FuncDistributor_0x05            
 	            BLX    R2              // ����� �� ��������������
                    
#ifdef X75  
                    MOV    R2, #0x00       // �������� ��� ����������, ������ ������ � ���������,
                    STR    R2, [R4, #0x14] // ����� ��� ������� � ����� �� ���������
#endif
                    
     not_alpha_05:
    is_csm_exc_05: 
     
                    POP   {R0-R2,LR}        // ��� ������ ������ ����������
    
                    CMP    R0, #0x00         // ������������� ��������
                    BX     LR
 
 
       img_17_check: // �������� ��������
   
                    SUB    SP, SP, #0x14   // ������������� ��������
                    MOV    R6, R0          // ������������� ��������
                    
                    // R0 = SCREEN_STRUCT
                    // R1 = DRAWOBJ_17
                    
                    PUSH  {R0-R2,LR}       // ������ ���� �����������, ���� �� ��� ...
                    
#ifdef X75
                    BL     isCSMException  // ���������, � CSM ������� "�� �����" �� ����������?
                    CMP    R0, #0x01
                    MOV    R0, R6 
                    BEQ    is_csm_exc_17   // ����������, ����� ��������� ...
#endif
                     
                    LDR    R2, [R1, #0x14] // R2 = EIMGHDR *eimg
                    LDR    R2, [R2, #0x00] // R2 = eimg->bpnum 
                    
                    BIC    R2, R2, #0xF0   // ������� 4-8 ����, �.�. ����� ����� 0xXA ����� ��� 0x0A
                    
                    CMP    R2, #0x0A       // ���������, ��� �� �����-������?
                    BNE    not_alpha_17    // � ����������� �� �������� ������
                    
                    // ���, �����-����� ����! ������ ����� ����-������� ... 
                    MOV    R1, R0          // ������ ����� ��������� SCREEN_STRUCT
                    MOV    R0, R4          // ������ ����� ��������� DRWOBJ_17
                    LDR    R5, =FuncDistributor_0x17            
 	            BLX    R5              // ����� �� ��������������
                    
#ifdef X75  
                    MOV    R2, #0x00       // �������� ��� ����������, ������ ������ � ���������,
                    STR    R2, [R4, #0x14] // ����� ��� ������� � ����� �� ���������
#endif
                    
      not_alpha_17: 
     is_csm_exc_17:
     
                    POP   {R0-R2,PC}       // ��� ������ ������ ����������
                    
                    
                    END
                    
                    
                    
