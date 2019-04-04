/*****************************************
 * 文件名：   Timer.h
 * 
 * 说明：     对接 CC2530 寄存器实现快速开发
 * 
 * 
 * 作者：     汜方(15977877715@qq.com)
 * 修改时间：   2019-03-13
 *****************************************/

#ifndef _TIMER_H
#define _TIMER_H

/*****************  库  *****************/
#include <GenericApp.h>

#include "default_type.h"




/***************** 定义 *****************/

typedef struct TimeOutTaskType
{
  uint8_t flag;
  uint32_t count;
  void (*callback)(void);
}TIMEOUTTask;

typedef struct TickerTaskType
{
  uint32_t reload,count;
  void (*callback)(void);
}TICKERTask;

#define TIMEOUT_TASK_MAX    8
#define TICKER_TASK_MAX     8

/***************** 函数 *****************/

/****************************************
 * 函数名： T4_Init
 * 功能：   初始化定时器4
 *      
 * 参数:    void
 *      
 * 返回值： void
****************************************/
void T4_Init(void);

/****************************************
 * 函数名： TimeOut
 * 功能：   延时调用函数
 *      
 * 参数:    *fun-函数指针 timeout-延时ms
 *      
 * 返回值： uint8_t 函数队列序号
****************************************/
uint8_t Timeout(void (*fun)(void),float timeout);

/****************************************
 * 函数名： TimeOutDel
 * 功能：   解除函数延时调用
 *      
 * 参数:    index-函数队列序号
 *      
 * 返回值： 0-失败 1-成功
****************************************/
uint8_t TimeoutDel(uint8_t index);

/****************************************
 * 函数名： Ticker
 * 功能：   定时调用函数
 *      
 * 参数:    *fun-函数指针 timeout-延时ms
 *      
 * 返回值： uint8_t 函数队列序号
****************************************/
uint8_t Ticker(void (*fun)(void),float timeout);

/****************************************
 * 函数名： TickerDel
 * 功能：   解除函数定时调用
 *      
 * 参数:    index-函数队列序号
 *      
 * 返回值： 0-失败 1-成功
****************************************/
uint8_t TickerDel(uint8_t index);

#endif //_TIMER_H