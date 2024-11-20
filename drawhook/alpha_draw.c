//  Draw Hook //
//alpha_draw.c - ��������� �������������� ��������
//(c)Dimadze


//24 ������ ������� ����������� � 16 ������
#define RGB16(R,G,B) ((B>>3)+((G>>2)<<5)+((R>>3)<<11))

#define PIXEL16  2  //���� �� ���� ������� 16 ������� ������
#define PIXEL32  4  //���� �� ���� ������� 32 ������� ������
#define PIXEL32P 5  //���� �� ���� ���������� ������� ����������� 32 ������� ������

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
  int  trans;   // ������ 0xE000 - ������������ ������������, 0xFFFFFFFF - �� ������������
  char *bitmap;
}EIMGHDR; 


//��������� ��������� ������������ � ����������� � ����������� ��� ��� ����,
//� ���������� ��� ����� ���� ������ ...
//��� ������ ��������� �������� �� �, ������� �� ������� :)

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
  int    w;       // ������ ������
  int    h;       // ������ ������
  RECT   unk_rc;  // 
  RECT   rc;      // ���������� ������� ���������
  char   *buf;    // ����� ������ ������
  int    col;     // ���-�� � ���������� ������ 
}SCREEN_STRUCT;


__thumb unsigned short mixcolor(short bg, char *font) //���������� ����� ��� �����-������
{
 char r = (((bg&0xF800)>>8)*(0xFF-font[3])+font[0]*font[3])/0xFF;
 char g = (((bg&0x7E0)>>3)*(0xFF-font[3])+font[1]*font[3])/0xFF;
 char b = (((bg&0x1F)<<3)*(0xFF-font[3])+font[2]*font[3])/0xFF;
 return RGB16(r,g,b);
}


__thumb void DrawObject_0x05_0x0A(DRWOBJ_5 *obj, SCREEN_STRUCT *scr)
{
 //����� ����������� ������������ / ������ IMGHDR
 for (int h=0;h<obj->img->h;h++) 
  {
   for (int w=0;w<obj->img->w*PIXEL32;w+=PIXEL32) 
    {
      if (obj->rc.x+w/PIXEL32 <= scr->rc.x2 && obj->rc.x+w/PIXEL32 >= scr->rc.x && obj->rc.y+h <= scr->rc.y2 && obj->rc.y+h >= scr->rc.y)
       {
        char color[4];
       
        color[3]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 3]; 
        
        //���� ���������� == 0%, ������ ������ ���� ������� � ������?
        if (color[3]>0x00)  
         { 
          color[0]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 2];
          color[1]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 1];
          color[2]=obj->img->bitmap[w + obj->img->w*PIXEL32*h + 0];  
         
          //��� ���� ���������� == 100% (255), ������ ��������� ����?
          if (color[3]==0xFF) *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + w/2 + h*scr->w*PIXEL16) = RGB16(color[0],color[1],color[2]);
          else
           //��� ���� ���������� < 100% (255), �� �� ����� 0 (����� ����������� ������)
           *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + w/2 + h*scr->w*PIXEL16) = mixcolor(*(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + w/2 + h*scr->w*PIXEL16),color); 
         }
       }
    }
  }
}



__thumb void DrawObject_0x05_0x8A(DRWOBJ_5 *obj, SCREEN_STRUCT *scr)
{
 signed char repeat; //������� ���-�� ����������/������ ��������
 unsigned int n = 0; //������� ���� ���������
 unsigned int p = 0; //������� ��������
 short x = 0, y = 0; //������� ����������, ���������������� ��������
 
 //�����  ������������ / ������ IMGHDR
 while (n < 0xFFFFFFFF)
  {
   char color[4];
   //��������� ���-�� ����������
   repeat = obj->img->bitmap[n*PIXEL32P + p*4];
   //Ec�� ������������� �������
   if (repeat > 0)
    {
     //���������� ������������
     color[3]=obj->img->bitmap[n*PIXEL32P + p*4 +4];
     //��� �� ������ ������������ ���������� ������� ���� 
     if (color[3] > 0x00)
      {
       color[0]=obj->img->bitmap[n*PIXEL32P + p*4 + 3];
       color[1]=obj->img->bitmap[n*PIXEL32P + p*4 + 2];
       color[2]=obj->img->bitmap[n*PIXEL32P + p*4 + 1];
      }
     //��������� ������ ������������� ������� 
     while (repeat > 0)
      {
        //��������� ��������� ��������
        if (obj->rc.x+x <= scr->rc.x2 && obj->rc.x+x >= scr->rc.x && obj->rc.y+y <= scr->rc.y2 && obj->rc.y+y >= scr->rc.y && color[3]>0x00)
         {
           //��� ���� ���������� == 100% (255), ������ ��������� ����?
           if (color[3]==0xFF) *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = RGB16(color[0],color[1],color[2]);
           else
           //��� ���� ���������� < 100% (255), �� �� ����� 0 (����� ����������� ������)
           *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = mixcolor(*(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16),color); 
         }
        //���������� ������������ ����� ���������
        if (x < obj->img->w - 1) x++; else {y++; x = 0;}
        //��������� ����������
        repeat--;
      }
     } else 
         {
          //Ec�� ������ �������
          while (repeat < 0)
           {
             //���������� ������������
             color[3]=obj->img->bitmap[n*PIXEL32P + p*4 + 4];
             //��� �� ������ ������������ ���������� ������� ���� 
             if (color[3] > 0x00)
              {
               color[0]=obj->img->bitmap[n*PIXEL32P + p*4 + 3];
               color[1]=obj->img->bitmap[n*PIXEL32P + p*4 + 2];
               color[2]=obj->img->bitmap[n*PIXEL32P + p*4 + 1];
              }
             //��������� ��������� ��������
             if (obj->rc.x+x <= scr->rc.x2 && obj->rc.x+x >= scr->rc.x && obj->rc.y+y <= scr->rc.y2 && obj->rc.y+y >= scr->rc.y && color[3]>0x00)
              {
                //��� ���� ���������� == 100% (255), ������ ��������� ����?
                if (color[3]==0xFF) *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = RGB16(color[0],color[1],color[2]);
                else
                 //��� ���� ���������� < 100% (255), �� �� ����� 0 (����� ����������� ������)
                 *(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16) = mixcolor(*(unsigned short *)((char *)scr->buf + obj->rc.y*scr->w*PIXEL16 + PIXEL16*obj->rc.x + x*2 + y*scr->w*PIXEL16),color); 
              } 
            //���������� ������������ ����� ���������
            if (x < obj->img->w - 1) x++; else {y++; x = 0;}
            //����������� ��������
            if (repeat < -1) p++;
            //��������� ����������
            repeat++;
           }
         }
   //���������� ����������� �������� ����� ���������
   if ((x == 0 && y >= obj->img->h) || obj->rc.y + y > scr->h) n = 0xFFFFFFFF; else n++;
  }
}


__thumb void FuncDistributor_0x05(DRWOBJ_5 *obj, SCREEN_STRUCT *scr)  //�������������� ��� ��������� ������� #0x05
{
 if (obj->img->bpnum == 0x0A) DrawObject_0x05_0x0A(obj, scr);
 if (obj->img->bpnum == 0x8A) DrawObject_0x05_0x8A(obj, scr);
}

__thumb void FuncDistributor_0x17(DRWOBJ_17 *obj_17, SCREEN_STRUCT *scr) //��������������, ���������� � ��������� ������� #0x17 (Java)
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
