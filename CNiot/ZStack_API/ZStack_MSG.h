/*****************************************
 * 文件名：   ZStack_MSG.h
 * 
 * 说明：     对接 Z-Stack-CC2530-2.3.0-1.4.0 协议栈实现快速开发
 * 
 * 
 * 作者：     汜方(15977877715@qq.com)
 * 修改时间：   2019-02-27
 *****************************************/

#ifndef _ZSTACK_MSG_H
#define _ZSTACK_MSG_H

/*****************  库  *****************/
#include "..\CNiot.h"
#include "..\default_type.h"




/***************** 定义 *****************/






/****************************************
 * 函数名： SandAll
 * 功能：   广播数据
 *      
 * 参数:    *fmt-数据
 *      
 * 返回值： 1-成功  0-失败
****************************************/
uint8_t SandAll(char *fmt,...);

/****************************************
 * 函数名： SendGroup
 * 功能：   组播数据
 *      
 * 参数:    *fmt-数据
 *      
 * 返回值： 1-成功  0-失败
****************************************/
uint8_t SendGroup(char *fmt, ...);

/****************************************
 * 函数名： SendPoint
 * 功能：   单播数据
 *      
 * 参数:    trage-目标地址 *fmt-数据
 *      
 * 返回值： 1-成功  0-失败
****************************************/
uint8_t SendPoint(uint16 trage, char *fmt, ...);


/****************************************
 * 函数名： MessageProcess
 * 功能：   信息处理函数
 *      
 * 参数:    addr-地址 *data-数据
 *      
 * 返回值： 
****************************************/
void MessageProcess(uint16_t addr, uint8_t *data);

#endif //_ZSTACK_MSG_H