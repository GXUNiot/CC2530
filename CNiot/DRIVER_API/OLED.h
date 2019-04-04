/*****************************************
 * �ļ�����   OLED.h
 * 
 * ˵����     �Խ� CC2530 �Ĵ���ʵ�ֿ��ٿ���
 * 
 * 
 * ���ߣ�     �᷽(15977877715@qq.com)
 * �޸�ʱ�䣺   2019-03-13
 *****************************************/

#ifndef _OLED_H
#define _OLED_H

/*****************  ��  *****************/
#include <ioCC2530.h>



/***************** ���� *****************/


#define OLED_SCL P1_2       //SCLK  ʱ�� D0��SCLK��
#define OLED_SDA P1_3       //SDA   D1��MOSI�� ����
#define OLED_RST P1_7       //_RES  hardware reset   ��λ 
#define OLED_DC  P1_6       //A0  H/L ��������ѡͨ�ˣ�H�����ݣ�L:����

#define XLevelL        0x00
#define XLevelH        0x10
#define XLevel         ((XLevelH&0x0F)*16+XLevelL)
#define Max_Column     128
#define Max_Row        64
#define Brightness     0xCF 
#define X_WIDTH        128
#define Y_WIDTH        64

/***************** ���� *****************/

/****************************************
 * �������� OLED_Init
 * ���ܣ�   ��ʼ����ʱ��4
 *      
 * ����:    void
 *      
 * ����ֵ�� void
****************************************/
void OLED_Init(void);


/*********************OLED ��������************************************/
void OLED_Set_Pos(unsigned char x, unsigned char y);
/*********************OLEDȫ��************************************/
void OLED_Fill(unsigned char bmp_dat);
/*********************OLED��λ************************************/
void OLED_CLS(void);
/*********************OLED��ʼ��************************************/

/***************������������ʾ6*8һ���׼ASCII�ַ���    ��ʾ�����꣨x,y����yΪҳ��Χ0��7****************/
void OLED_P6x8Str(unsigned char x, unsigned char y,unsigned char ch[]);
/*******************������������ʾ8*16һ���׼ASCII�ַ���     ��ʾ�����꣨x,y����yΪҳ��Χ0��7****************/
void OLED_P8x16Str(unsigned char x, unsigned char y,unsigned char ch[]);
/*****************������������ʾ16*16����  ��ʾ�����꣨x,y����yΪҳ��Χ0��7****************************/
void OLED_P16x16Ch(unsigned char x, unsigned char y, unsigned char* F16x16, unsigned char N);
/***********������������ʾ��ʾBMPͼƬ128��64��ʼ������(x,y),x�ķ�Χ0��127��yΪҳ�ķ�Χ0��7*****************/
void Draw_BMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);

void OLED_welcome();

#endif //_OLED_H