/*****************************************
 * �ļ�����   IO.h
 * 
 * ˵����     �Խ� CC2530 �Ĵ���ʵ�ֿ��ٿ���
 * 
 * 
 * ���ߣ�     �᷽(15977877715@qq.com)
 * �޸�ʱ�䣺   2019-03-13
 *****************************************/

#ifndef _IO_H
#define _IO_H

/*****************  ��  *****************/
#include "CNiot.h"
#include <ioCC2530.h>
#include "BitCalculation.h"
#include "default_type.h"



/***************** ���� *****************/

#define HIGH    1
#define LOW     0

#define GPIO_P0         0x0100
#define GPIO_P1         0x0200
#define GPIO_P2         0x0400

#define Pin_0           0x01 << 0 
#define Pin_1           0x01 << 1
#define Pin_2           0x01 << 2
#define Pin_3           0x01 << 3
#define Pin_4           0x01 << 4
#define Pin_5           0x01 << 5
#define Pin_6           0x01 << 6
#define Pin_7           0x01 << 7

#define GPIO_P0_0       (Pin_0 | GPIO_P0)
#define GPIO_P0_1       (Pin_1 | GPIO_P0)
#define GPIO_P0_2       (Pin_2 | GPIO_P0)
#define GPIO_P0_3       (Pin_3 | GPIO_P0)
#define GPIO_P0_4       (Pin_4 | GPIO_P0)
#define GPIO_P0_5       (Pin_5 | GPIO_P0)
#define GPIO_P0_6       (Pin_6 | GPIO_P0)
#define GPIO_P0_7       (Pin_7 | GPIO_P0)

#define GPIO_P1_0       (Pin_0 | GPIO_P1)
#define GPIO_P1_1       (Pin_1 | GPIO_P1)
#define GPIO_P1_2       (Pin_2 | GPIO_P1)
#define GPIO_P1_3       (Pin_3 | GPIO_P1)
#define GPIO_P1_4       (Pin_4 | GPIO_P1)
#define GPIO_P1_5       (Pin_5 | GPIO_P1)
#define GPIO_P1_6       (Pin_6 | GPIO_P1)
#define GPIO_P1_7       (Pin_7 | GPIO_P1)

#define GPIO_P2_0       (Pin_0 | GPIO_P2)
#define GPIO_P2_1       (Pin_1 | GPIO_P2)
#define GPIO_P2_2       (Pin_2 | GPIO_P2)
#define GPIO_P2_3       (Pin_3 | GPIO_P2)
#define GPIO_P2_4       (Pin_4 | GPIO_P2)

#define INPUT           0x00
#define INPUT_UP        0x01
#define INPUT_DOWN      0x02
#define INPUT_HRES      0x04
#define OUTPUT          0x08

#define RISE    0x00
#define FALL    0x01


typedef unsigned int GPIO_Pin;

#define PinMode(x,y)            fPinMode( GPIO_##x, y)

#define digitalWrite(x, y)       x = y

#define digitalRead(x)          x == HIGH ?  HIGH :  LOW

typedef struct IO_INTERRUPT_IRQ
{
  void (*irq)(void);
}IO_Interrupt_IRQ;

#define attachInterrupt(x,y,z)  fattachInterrupt(GPIO_##x, y, z)

/***************** ���� *****************/

/****************************************
 * �������� fPinMode
 * ���ܣ�   ��ʼ��IO��
 *      
 * ����:    pin-io����� mode-ģʽ
 *      
 * ����ֵ�� void
****************************************/
void fPinMode(GPIO_Pin pin, unsigned char mode);

/****************************************
 * �������� fattachInterrupt
 * ���ܣ�   ��ʼ��IO���ж�
 *      
 * ����:    pin-io����� *fun-�ж���Ӧ���� mode-ģʽ
 *      
 * ����ֵ�� void
****************************************/
void fattachInterrupt(GPIO_Pin pin, void (*fun)(void), uint8_t mode);


#endif //_IO_H