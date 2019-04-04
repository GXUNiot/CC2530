#include "BitCalculation.h"

/****************************************
 * 函数名： T4_Init
 * 功能：   初始化定时器4
 *      
 * 参数:    bit-bit数
 *      
 * 返回值： uint8_t-bit所在的位置
****************************************/
uint8_t BitToNum(uint8_t bit)
{
  uint8_t index=0;
  for(index=0; index<8; index++)
    if( (bit & (0x01<<index)) == (0x01<<index) )
      return index;
  return 0xFF;
}