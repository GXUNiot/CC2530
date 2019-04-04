#include "Timer.h"
#include <ioCC2530.h>

TIMEOUTTask TimeoutTask[TIMEOUT_TASK_MAX] = {{0,0,NULL}};
TICKERTask  TickerTask[TICKER_TASK_MAX]   = {{0,0,NULL}};

/****************************************
 * 函数名： T4_Init
 * 功能：   初始化定时器4
 *      
 * 参数:    void
 *      
 * 返回值： void
****************************************/
void T4_Init(void)
{
    T4CTL &= ~(0xFF);
  
  //T4CTL |= 0x01<<5;   //2
  //T4CTL |= 0x02<<5;   //4
  //T4CTL |= 0x03<<5;   //8
  //T4CTL |= 0x04<<5;   //16
  //T4CTL |= 0x05<<5;   //32
  T4CTL |= 0x06<<5;   //64
  //T4CTL |= 0x07<<5;   //128
  T4CTL |= 0x08;
  T4CTL |= 0x03;
    
  T4IE = 1;
  T4CC0 = 250;
  T4CTL |= 0x10;
  EA = 1;
}

/****************************************
 * 函数名： TimeOut
 * 功能：   定时调用函数
 *      
 * 参数:    *fun-函数指针 timeout-延时ms
 *      
 * 返回值： uint8_t 函数队列序号
****************************************/
uint8_t Timeout(void (*fun)(void),float timeout)
{
  uint8_t i;
  
  if( !(T4CTL&0x10) )
  {
    T4_Init();
  }
  
  for(i=0; i<TIMEOUT_TASK_MAX; i++)
  {
    if( TimeoutTask[i].flag ==0 )
    {
      TimeoutTask[i].flag = 1;
      TimeoutTask[i].count = (uint32_t)timeout*1000;
      TimeoutTask[i].callback = fun;
      return i+1;
    }
    else if( i == 15 )
    {
      return 0;
    }
  }
  return 0;
}

/****************************************
 * 函数名： TimeOutDel
 * 功能：   解除函数定时调用
 *      
 * 参数:    index-函数队列序号
 *      
 * 返回值： 0-失败 1-成功
****************************************/
uint8_t TimeoutDel(uint8_t index)
{
  if( TimeoutTask[index-1].flag )
  {
    TimeoutTask[index-1].count = 0;
    TimeoutTask[index-1].callback = NULL;
    return 1;
  }
  return 0;
}

/****************************************
 * 函数名： Ticker
 * 功能：   定时调用函数
 *      
 * 参数:    *fun-函数指针 timeout-延时ms
 *      
 * 返回值： uint8_t 函数队列序号
****************************************/
uint8_t Ticker(void (*fun)(void),float timeout)
{
  uint8_t i;
  
  if( !(T4CTL&0x10) )
  {
    T4_Init();
  }
  
  for(i=0; i<TICKER_TASK_MAX; i++)
  {
    if( TickerTask[i].reload ==0 )
    {
      TickerTask[i].reload = (uint32_t)timeout*1000;
      TickerTask[i].count = TickerTask[i].reload;
      TickerTask[i].callback = fun;
      return i+1;
    }
    else if( i == 15 )
    {
      return 0;
    }
  }
  return 0;
}

/****************************************
 * 函数名： TickerDel
 * 功能：   解除函数定时调用
 *      
 * 参数:    index-函数队列序号
 *      
 * 返回值： 0-失败 1-成功
****************************************/
uint8_t TickerDel(uint8_t index)
{
  if( TickerTask[index-1].reload )
  {
    TickerTask[index-1].reload = 0;
    TickerTask[index-1].count = 0;
    TickerTask[index-1].callback = NULL;
    return 1;
  }
  return 0;
}


#pragma vector = T4_VECTOR
__interrupt void T4_ISR(void)
{
  uint8_t i;
  
  for(i=0; i<TIMEOUT_TASK_MAX;i++)
  {
    if(TimeoutTask[i].flag)
    {
      if( --TimeoutTask[i].count == 0 )
      {
        TimeoutTask[i].callback();
        TimeoutTask[i].count = 0;
        TimeoutTask[i].callback = NULL;
      }        
    }
  }
  for(i=0; i<TICKER_TASK_MAX;i++)
  {
    if(TickerTask[i].reload)
    {
      if( --TickerTask[i].count == 0 )
      {
        TickerTask[i].callback();
        TickerTask[i].count = TickerTask[i].reload;
      } 
    }
  }
}