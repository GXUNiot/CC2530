#include "BitCalculation.h"

/****************************************
 * �������� T4_Init
 * ���ܣ�   ��ʼ����ʱ��4
 *      
 * ����:    bit-bit��
 *      
 * ����ֵ�� uint8_t-bit���ڵ�λ��
****************************************/
uint8_t BitToNum(uint8_t bit)
{
  uint8_t index=0;
  for(index=0; index<8; index++)
    if( (bit & (0x01<<index)) == (0x01<<index) )
      return index;
  return 0xFF;
}