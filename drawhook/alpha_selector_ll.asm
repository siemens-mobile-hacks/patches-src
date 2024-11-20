//  Draw Hook //
//alpha_selector_ll.asm - Отлов полупрозрачной картинки (LONG LINK) на телефоны, где врезки не достают до тела патча
//(c)Dimadze

#include "drawhook.h"

                    EXTERN FuncDistributor_0x05
                    EXTERN FuncDistributor_0x17
#ifdef X75
                    EXTERN isCSMException
#endif
                    
                    CODE16  // Врубаем режим THUMB
                    
// Отлов всех изображений IMGHDR

                    RSEG    PATCH_DRAWOBJECT_OBJ05:CODE
                    
                    PUSH   {R4-R7,LR} // Восстанавливаем  затёртую команду 
                    BLX     img_05_check_j32 
                   
                    
// Отлов всех изображений EIMGHDR

                    RSEG    PATCH_DRAWOBJECT_OBJ17:CODE 
                    
                    PUSH   {R4-R7,LR} // Восстанавливаем  затёртую команду 
                    BLX     img_17_check_j32
                    
// Переходы
                    
                    CODE32
                    
                    RSEG    PATCH_DRAWOBJECT_OBJ05_J32:CODE 
                    
  img_05_check_j32:
                    
                    B       img_05_check
                    
                    
                    RSEG    PATCH_DRAWOBJECT_OBJ17_J32:CODE 
                    
  img_17_check_j32:
                    
                    B       img_17_check
                    
                    
//Восстановление
                    
                    RSEG    PATCH_REPAIRJUMP100:CODE 
                    
                    B       loc_jump_swi100
                    
                    RSEG    PATCH_REPAIRJUMP145:CODE 
                    
                    B       loc_jump_swi145
                    
                    
                    RSEG    PATCH_LOCALJUMP100:CODE 

   loc_jump_swi100:    
                    
                    
                    RSEG    PATCH_LOCALJUMP145:CODE 

   loc_jump_swi145:    

                           

// Ну, а это у нас процессор проверки
// Здесь происходит сортировка изображений на полупрозрачные и обычные
// Вычисление аргументов для нашей ф-ии отрисовки 

       
                    RSEG PATCH_BODY:CODE
                    
       img_05_check: // Проверка на присутствии именно картинки в тексте
    
                    MOV    R5, R0          // Востановление комманды
                    MOV    R4, R1          // Востановление комманды
                    
                    // R0 = SCREEN_STRUCT
                    // R1 = DRAWOBJ_05
                    
 
                    PUSH  {R0-R2,LR}       // Теперь надо сохраниться, мало ли что ...
    
#ifdef X75
                    BL     isCSMException  // Посмотрим, а CSM которая "на верху" не исключение?
                    CMP    R0, #0x01
                    MOV    R0, R5 
                    BEQ    is_csm_exc_05   // Исключение, тогда сваливаем ...
#endif
    
                    LDR    R2, [R1, #0x14] // R2 = IMGHDR *img
                    LDRB   R2, [R2, #0x02] // R2 = img->bpnum 
                    
                    BIC    R2, R2, #0xF0   // Очищаем 4-8 биты, т.е. любое число 0xXA будет как 0x0A
                    
                    CMP    R2, #0x0A       // Проверяем, нет ли альфа-канала?
                    BNE    not_alpha_05    // В зависимости от проверки уходим
                    
                    // Ага, альфа-канал есть! Рисуем через спец-функцию ...
                    MOV    R1, R0          // Возьмём адрес структуры SCREEN_STRUCT
                    MOV    R0, R4          // Возьмём адрес структуры DRWOBJ_05
                    LDR    R2, =FuncDistributor_0x05            
 	            BLX    R2              // Пойдём на распределитель
                    
#ifdef X75  
                    MOV    R2, #0x00       // Картинку уже нарисовали, теперь ломаем её структуру,
                    STR    R2, [R4, #0x14] // чтобы сам телефон её снова не нарисовал
#endif
                    
     not_alpha_05:
    is_csm_exc_05: 
     
                    POP   {R0-R2,LR}        // Вот теперь грузим сохранение
    
                    CMP    R0, #0x00         // Востановление комманды
                    BX     LR
 
 
       img_17_check: // Проверка картинки
   
                    SUB    SP, SP, #0x14   // Востановление комманды
                    MOV    R6, R0          // Востановление комманды
                    
                    // R0 = SCREEN_STRUCT
                    // R1 = DRAWOBJ_17
                    
                    PUSH  {R0-R2,LR}       // Теперь надо сохраниться, мало ли что ...
                    
#ifdef X75
                    BL     isCSMException  // Посмотрим, а CSM которая "на верху" не исключение?
                    CMP    R0, #0x01
                    MOV    R0, R6 
                    BEQ    is_csm_exc_17   // Исключение, тогда сваливаем ...
#endif
                     
                    LDR    R2, [R1, #0x14] // R2 = EIMGHDR *eimg
                    LDR    R2, [R2, #0x00] // R2 = eimg->bpnum 
                    
                    BIC    R2, R2, #0xF0   // Очищаем 4-8 биты, т.е. любое число 0xXA будет как 0x0A
                    
                    CMP    R2, #0x0A       // Проверяем, нет ли альфа-канала?
                    BNE    not_alpha_17    // В зависимости от проверки уходим
                    
                    // Ага, альфа-канал есть! Рисуем через спец-функцию ... 
                    MOV    R1, R0          // Возьмём адрес структуры SCREEN_STRUCT
                    MOV    R0, R4          // Возьмём адрес структуры DRWOBJ_17
                    LDR    R5, =FuncDistributor_0x17            
 	            BLX    R5              // Пойдём на распределитель
                    
#ifdef X75  
                    MOV    R2, #0x00       // Картинку уже нарисовали, теперь ломаем её структуру,
                    STR    R2, [R4, #0x14] // чтобы сам телефон её снова не нарисовал
#endif
                    
      not_alpha_17: 
     is_csm_exc_17:
     
                    POP   {R0-R2,PC}       // Вот теперь грузим сохранение
                    
                    
                    END
                    
                    
                    
