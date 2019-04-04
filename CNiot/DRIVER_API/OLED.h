/*****************************************
 * 文件名：   OLED.h
 * 
 * 说明：     对接 CC2530 寄存器实现快速开发
 * 
 * 
 * 作者：     汜方(15977877715@qq.com)
 * 修改时间：   2019-03-13
 *****************************************/

#ifndef _OLED_H
#define _OLED_H

/*****************  库  *****************/
#include <ioCC2530.h>



/***************** 定义 *****************/


#define OLED_SCL P1_2       //SCLK  时钟 D0（SCLK）
#define OLED_SDA P1_3       //SDA   D1（MOSI） 数据
#define OLED_RST P1_7       //_RES  hardware reset   复位 
#define OLED_DC  P1_6       //A0  H/L 命令数据选通端，H：数据，L:命令

#define XLevelL        0x00
#define XLevelH        0x10
#define XLevel         ((XLevelH&0x0F)*16+XLevelL)
#define Max_Column     128
#define Max_Row        64
#define Brightness     0xCF 
#define X_WIDTH        128
#define Y_WIDTH        64

/***************** 函数 *****************/

/****************************************
 * 函数名： OLED_Init
 * 功能：   初始化定时器4
 *      
 * 参数:    void
 *      
 * 返回值： void
****************************************/
void OLED_Init(void);


/*********************OLED 设置坐标************************************/
void OLED_Set_Pos(unsigned char x, unsigned char y);
/*********************OLED全屏************************************/
void OLED_Fill(unsigned char bmp_dat);
/*********************OLED复位************************************/
void OLED_CLS(void);
/*********************OLED初始化************************************/

/***************功能描述：显示6*8一组标准ASCII字符串    显示的坐标（x,y），y为页范围0～7****************/
void OLED_P6x8Str(unsigned char x, unsigned char y,unsigned char ch[]);
/*******************功能描述：显示8*16一组标准ASCII字符串     显示的坐标（x,y），y为页范围0～7****************/
void OLED_P8x16Str(unsigned char x, unsigned char y,unsigned char ch[]);
/*****************功能描述：显示16*16点阵  显示的坐标（x,y），y为页范围0～7****************************/
void OLED_P16x16Ch(unsigned char x, unsigned char y, unsigned char* F16x16, unsigned char N);
/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void Draw_BMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);

void OLED_welcome();

#endif //_OLED_H