/*****************************************
 * 文件名：   ZStack_Serial.h
 * 
 * 说明??    对接 Z-Stack-CC2530-2.3.0-1.4.0 协议栈实现快速开?? * 
 * 
 * 作者：     汜方(15977877715@qq.com)
 * 修改时间??  2019-02-27
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

/***************** 定义 *****************/

#define SERIAL_THRESH  64
#define SERIAL_RX_SZ  128
#define SERIAL_TX_SZ  128
#define SERIAL_IDLE  6

#define Serial_CallBack_Enable 1


/****************************************
 * 函数名： Init_Serial
 * 功能??  初始化串口
 * 参数:    port-端口
 *      
 * 返回值： void
****************************************/
void Init_Serial(uint8_t port, uint32_t boud);


/****************************************
 * 函数名： Printf
 * 功能??  串口发送函数
 * 参数:    port-端口 *fmt-数据
 *      
 * 返回值： void
****************************************/
int Printf(uint8_t port, const char*fmt, ...);


/****************************************
 * 函数名： Serial_CallBack
 * 功能??  硬件层串口回调函数
 * 参数:    port-端口 event-事件
 *      
 * 返回值： void
****************************************/
void HAL_Serial_CallBack(uint8 port, uint8 event);


/****************************************
 * 函数名： Serial_CallBack
 * 功能??  用户串口回调函数
 *      
 * 参数:    port-端口 *buf-数据
 *      
 * 返回值： void
****************************************/
void Serial_CallBack(uint8_t port, uint8_t* buf);






#endif //_ZSTACK_SERIAL_H