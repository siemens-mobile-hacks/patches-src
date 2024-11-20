//  Draw Hook //
//alpha_draw.c - Отрисовка полупрозрачной картинки
//(c)Dimadze


//24 битный пиксель преобразуем в 16 битный
#define RGB16(R,G,B) ((B>>3)+((G>>2)<<5)+((R>>3)<<11))

#define PIXEL16  2  //Байт на один пиксель 16 битного буфера
#define PIXEL32  4  //Байт на один пиксель 32 битного буфера
#define PIXEL32P 5  //Байт на один одинаковый пиксель пакованного 32 битного буфера

#include "drawhook.h"


typedef struct{
  short x;
  short y;
  short x2;
  short y2;
}RECT;

typedef struct{
  unsigned char w;
  unsigned char h;
  unsigned short bpnum; //For BW=1, 8bit=5, 16bit=8, 32bit=0x0A, 0x80 - packed
  char *bitmap;
}IMGHDR;

typedef struct{
  unsigned int  bpnum;   // 16bit = 8, 32bit = 0x0A, 0x80 - packed
  unsigned int  w; 
  unsigned int  h;     
  int  zero;    // 0x00000000
  int  trans;   // Бывает 0xE000 - Используется прозрачность, 0xFFFFFFFF - не используется
  char *bitmap;
}EIMGHDR; 


//Следующие структуры представлены в укороченном и достаточном для нас виде,
//в реальности они могут быть длинее ...
//Эти кривые структуры придумал не я, поэтому не ругайте :)

typedef struct{
  char    id_5;    // 0x05 (ID)
  char    cbyte;   // 0x00, 0x10
  char    zero;    // 0x00
  int     pen;     
  int     brush;
  RECT    rc;  
  IMGHDR  *img;
}DRWOBJ_5;

typedef struct{
  char    id_17;   // 0x17 (ID)
  char    cbyte;   // 0x00, 0x10
  char    zero;    // 0x00
  int     pen;          
  int     brush;
  RECT    rc;  
  EIMGHDR *eimg;
}DRWOBJ_17;

typedef struct{
  int    w;       // Ширина экрана
  int    h;       // Высота экрана
  RECT   unk_rc;  // 
  RECT   rc;      // Глобальные границы отрисовки
  char   *buf;    // Адрес буфера экрана
  int    col;     // Что-то с цветностью экрана 
}SCREEN_STRUCT;


__thumb unsigned short mixcolor(short bg, char *font) //Вычисление цвета при альфа-канале
{
 char r = (((bg&0xF800)>>8)*(0xFF-font[3])+font[0]*font[3])/0xFF;
 char g = (((bg&0x7E0)>>3)*(0xFF-font[3])+font[1]*font[3])/0xFF;
 char b = (((bg&0x1F)<<3)*(0xFF-font[3])+font[2]*font[3])/0xFF;
 return RGB16(r,g,b);
}


__thumb void DrawObject_0x05_0x0A(DRWOBJ_5 *obj, SCREEN_STRUCT *scr)
{
 //Здесь попиксельно обрабатываем / рисуем IMGHDR
 for (int h=0;h<obj->img->h;h++) 
  {
   for (int w=0;w<obj->img->w*PIXEL32;w+=PIXEL32) 
    {
      if (obj->rc.x+w/PIXEL32 <= scr->rc.x2 && obj->rc.x+w/PIXEL32 >= scr->rc.x && obj->rc.y+h <= scr->rc.y2 && obj->rc.y+h >= scr->rc.y)
       {
        char color[4];
       
        color[3]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 3]; 
        
        //Если альфаканал == 0%, нахрен писать этот пиксель в буффер?
        if (color[3]>0x00)  
         { 
          color[0]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 2];
          color[1]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 1];
          color[2]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 0];  
         
          //Это если альфаканал == 100% (255), нахрен вычислять цвет?
          if (color[3]==0xFF) *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + w/2 + h*scr->w*PIXEL16) = RGB16(color[0],color[1],color[2]);
          else
           //Это если альфаканал < 100% (255), но не равен 0 (Самый ресурсоёмкий случай)
           *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + w/2 + h*scr->w*PIXEL16) = mixcolor(*(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + w/2 + h*scr->w*PIXEL16),color); 
         }
       }
    }
  }
}



__thumb void DrawObject_0x05_0x8A(DRWOBJ_5 *obj, SCREEN_STRUCT *scr)
{
 signed char repeat; //Текущее кол-во повторений/разных пикселей
 unsigned int n = 0; //Текущий цикл отрисовки
 unsigned int p = 0; //Текущая поправка
 short x = 0, y = 0; //Текущие координаты, отрисовывающейся картинки
 
 //Здесь  обрабатываем / рисуем IMGHDR
 while (n < 0xFFFFFFFF)
  {
   char color[4];
   //Считываем кол-во повторений
   repeat = obj->img->bitmap[n*PIXEL32P + p*4];
   //Ecли повторяющиеся пиксели
   if (repeat > 0)
    {
     //Коэффецент прозрачности
     color[3]=obj->img->bitmap[n*PIXEL32P + p*4 +4];
     //При не полной прозрачности потрудимся считать цвет 
     if (color[3] > 0x00)
      {
       color[0]=obj->img->bitmap[n*PIXEL32P + p*4 + 3];
       color[1]=obj->img->bitmap[n*PIXEL32P + p*4 + 2];
       color[2]=obj->img->bitmap[n*PIXEL32P + p*4 + 1];
      }
     //Отрисовка одного повторяющегся пикселя 
     while (repeat > 0)
      {
        //Различные граничные проверки
        if (obj->rc.x+x <= scr->rc.x2 && obj->rc.x+x >= scr->rc.x && obj->rc.y+y <= scr->rc.y2 && obj->rc.y+y >= scr->rc.y && color[3]>0x00)
         {
           //Это если альфаканал == 100% (255), нахрен вычислять цвет?
           if (color[3]==0xFF) *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = RGB16(color[0],color[1],color[2]);
           else
           //Это если альфаканал < 100% (255), но не равен 0 (Самый ресурсоёмкий случай)
           *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = mixcolor(*(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16),color); 
         }
        //Управление координатами точки отрисовки
        if (x < obj->img->w - 1) x++; else {y++; x = 0;}
        //Уменьшаем повторения
        repeat--;
      }
     } else 
         {
          //Ecли разные пиксели
          while (repeat < 0)
           {
             //Коэффецент прозрачности
             color[3]=obj->img->bitmap[n*PIXEL32P + p*4 + 4];
             //При не полной прозрачности потрудимся считать цвет 
             if (color[3] > 0x00)
              {
               color[0]=obj->img->bitmap[n*PIXEL32P + p*4 + 3];
               color[1]=obj->img->bitmap[n*PIXEL32P + p*4 + 2];
               color[2]=obj->img->bitmap[n*PIXEL32P + p*4 + 1];
              }
             //Различные граничные проверки
             if (obj->rc.x+x <= scr->rc.x2 && obj->rc.x+x >= scr->rc.x && obj->rc.y+y <= scr->rc.y2 && obj->rc.y+y >= scr->rc.y && color[3]>0x00)
              {
                //Это если альфаканал == 100% (255), нахрен вычислять цвет?
                if (color[3]==0xFF) *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = RGB16(color[0],color[1],color[2]);
                else
                 //Это если альфаканал < 100% (255), но не равен 0 (Самый ресурсоёмкий случай)
                 *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = mixcolor(*(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16),color); 
              } 
            //Управление координатами точки отрисовки
            if (x < obj->img->w - 1) x++; else {y++; x = 0;}
            //Увеличиваем поправку
            if (repeat < -1) p++;
            //Уменьшаем повторения
            repeat++;
           }
         }
   //Управление завершением главного цикла отрисовки
   if ((x == 0 && y >= obj->img->h) || obj->rc.y + y > scr->h) n = 0xFFFFFFFF; else n++;
  }
}


__thumb void FuncDistributor_0x05(DRWOBJ_5 *obj, SCREEN_STRUCT *scr)  //Распределитель для отрисовки Объекта #0x05
{
 if (obj->img->bpnum == 0x0A) DrawObject_0x05_0x0A(obj, scr);
 if (obj->img->bpnum == 0x8A) DrawObject_0x05_0x8A(obj, scr);
}

__thumb void FuncDistributor_0x17(DRWOBJ_17 *obj_17, SCREEN_STRUCT *scr) //Распределитель, подготовка и отрисовка Объекта #0x17 (Java)
{
  IMGHDR img;
  DRWOBJ_5 *obj_5;
 
  img.w = obj_17->eimg->w;
  img.h = obj_17->eimg->h;
  img.bpnum = obj_17->eimg->bpnum;
  img.bitmap = obj_17->eimg->bitmap;
 
  obj_5 = (DRWOBJ_5 *)obj_17;
  obj_5->img = &img;
  
  if (obj_5->img->bpnum == 0x0A) DrawObject_0x05_0x0A(obj_5, scr);
  if (obj_5->img->bpnum == 0x8A) DrawObject_0x05_0x8A(obj_5, scr);
}
