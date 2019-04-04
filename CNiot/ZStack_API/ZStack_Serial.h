/*****************************************
 * �ļ�����   ZStack_Serial.h
 * 
 * ˵��??    �Խ� Z-Stack-CC2530-2.3.0-1.4.0 Э��ջʵ�ֿ��ٿ�?? * 
 * 
 * ���ߣ�     �᷽(15977877715@qq.com)
 * �޸�ʱ��??  2019-02-27
 *****************************************/

#ifndef _ZSTACK_SERIAL_H
#define _ZSTACK_SERIAL_H

/*****************  ?? *****************/
#include "CNiot.h"
#include "..\default_type.h"

#include "MT_UART.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/***************** ���� *****************/

#define SERIAL_THRESH  64
#define SERIAL_RX_SZ  128
#define SERIAL_TX_SZ  128
#define SERIAL_IDLE  6

#define Serial_CallBack_Enable 1


/****************************************
 * �������� Init_Serial
 * ����??  ��ʼ������
 * ����:    port-�˿�
 *      
 * ����ֵ�� void
****************************************/
void Init_Serial(uint8_t port, uint32_t boud);


/****************************************
 * �������� Printf
 * ����??  ���ڷ��ͺ���
 * ����:    port-�˿� *fmt-����
 *      
 * ����ֵ�� void
****************************************/
int Printf(uint8_t port, const char*fmt, ...);


/****************************************
 * �������� Serial_CallBack
 * ����??  Ӳ���㴮�ڻص�����
 * ����:    port-�˿� event-�¼�
 *      
 * ����ֵ�� void
****************************************/
void HAL_Serial_CallBack(uint8 port, uint8 event);


/****************************************
 * �������� Serial_CallBack
 * ����??  �û����ڻص�����
 *      
 * ����:    port-�˿� *buf-����
 *      
 * ����ֵ�� void
****************************************/
void Serial_CallBack(uint8_t port, uint8_t* buf);






#endif //_ZSTACK_SERIAL_H