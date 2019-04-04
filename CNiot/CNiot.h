/*****************************************
 * 文件名：   CNiot.h
 * 
 * 说明：     对接 Z-Stack-CC2530-2.3.0-1.4.0 协议栈实现快速开发
 * 
 * 
 * 作者：     汜方(15977877715@qq.com)
 * 修改时间：   2019-02-27
 *****************************************/

#ifndef _CNIOT_H
#define _CNIOT_H

/*****************  库  *****************/
#include <GenericApp.h>
#include "ZDApp.h"
#include "hal_led.h"

#include "default_type.h"
#include "ZStack_API\ZStack_MSG.h"
#include "ZStack_API\ZStack_Serial.h"

#include "CC2530_API\Timer.h"
#include "CC2530_API\IO.h"
#include "CC2530_API\BitCalculation.h"

#ifdef ZDO_COORDINATOR
#include "DRIVER_API\RC522.h"
#include "DRIVER_API\OLED.h"
#endif
/***************** 定义 *****************/


#define LED1    P1_0
#define LED1_ON     0
#define LED1_OFF    1

#define LED2    P1_1
#define LED2_ON     0
#define LED2_OFF    1

#define LED3    P1_4
#define LED3_ON     0
#define LED3_OFF    1


#define KEY1    P0_1
#define KEY2    P2_0


/***************** 函数 *****************/

/****************************************
 * 函数名： setup
 * 功能：   用户初始化函数
 *      
 * 参数:    void
 *      
 * 返回值： void
****************************************/
void setup(void);


/****************************************
 * 函数名： loop
 * 功能：   用户循环函数
 *      
 * 参数:    void
 *      
 * 返回值： void
****************************************/
void loop(void);


/****************************************
 * 函数名： NETState_Process
 * 功能：   网络状态变化用户处理函数
 *      
 * 参数:    devState-设备状态
 *      
 * 返回值： void
****************************************/
void NETState_Process(devStates_t devState);


/****************************************
 * 函数名： GetNETState
 * 功能：   获取网络状态
 *      
 * 参数:    void
 *      
 * 返回值： devStates_t-网络状态
****************************************/
devStates_t GetNETState(void);

#endif //_template_H