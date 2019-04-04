#include "IO.h"


/****************************************
 * 函数名： fPinMode
 * 功能??  初始化IO?? *      
 * 参数:    pin-io口序??mode-模式
 *      
 * 返回值： void
****************************************/
void fPinMode(GPIO_Pin pin, unsigned char mode)
{
  switch(mode)
  {
  case INPUT:           
                  if( (pin & GPIO_P0) == GPIO_P0 )
                  {
                    P0SEL &= ~(pin&0xFF);
                    P0DIR &= ~(pin&0xFF);
                    P0INP &= ~(pin&0xFF);
                  }else if( (pin & GPIO_P1) == GPIO_P1 )
                  {
                    P1SEL &= ~(pin&0xFF);
                    P1DIR &= ~(pin&0xFF);
                    P1INP &= ~(pin&0xFF);
                  }else if( (pin & GPIO_P2) == GPIO_P2 )
                  {
                    P2SEL &= ~(pin&0xFF);
                    P2DIR &= ~(pin&0xFF);
                    P2INP &= ~(pin&0xFF);
                  }
                    
    break;
  case INPUT_UP:
                  if( (pin & GPIO_P0) == GPIO_P0 )
                  {
                    P0SEL &= ~(pin&0xFF);
                    P0DIR &= ~(pin&0xFF);
                    P0INP &= ~(pin&0xFF);
                    P2INP &= ~(((pin>>8)&0xF)<<5);
                  }else if( (pin & GPIO_P1) == GPIO_P1 )
                  {
                    P1SEL &= ~(pin&0xFF);
                    P1DIR &= ~(pin&0xFF);
                    P1INP &= ~(pin&0xFF);
                    P2INP &= ~(((pin>>8)&0xF)<<5);
                  }else if( (pin & GPIO_P2) == GPIO_P2 )
                  {
                    P2SEL &= ~(pin&0xFF);
                    P2DIR &= ~(pin&0xFF);
                    P2INP &= ~(pin&0xFF);
                     P2INP &= ~(((pin>>8)&0xF)<<5);
                  }
    break;
  case INPUT_DOWN:
                  if( (pin & GPIO_P0) == GPIO_P0 )
                  {
                    P0SEL &= ~(pin&0xFF);
                    P0DIR &= ~(pin&0xFF);
                    P0INP &= ~(pin&0xFF);
                    P2INP |= (((pin>>8)&0xF)<<5);
                  }else if( (pin & GPIO_P1) == GPIO_P1 )
                  {
                    P1SEL &= ~(pin&0xFF);
                    P1DIR &= ~(pin&0xFF);
                    P1INP &= ~(pin&0xFF);
                    P2INP |= (((pin>>8)&0xF)<<5);
                  }else if( (pin & GPIO_P2) == GPIO_P2 )
                  {
                    P2SEL &= ~(pin&0xFF);
                    P2DIR &= ~(pin&0xFF);
                    P2INP &= ~(pin&0xFF);
                    P2INP |= (((pin>>8)&0xF)<<5);
                  }
    break;
  case INPUT_HRES:
                  if( (pin & GPIO_P0) == GPIO_P0 )
                  {
                    P0SEL &= ~(pin&0xFF);
                    P0DIR &= ~(pin&0xFF);
                    P0INP |= (pin&0xFF);
                  }else if( (pin & GPIO_P1) == GPIO_P1 )
                  {
                    P1SEL &= ~(pin&0xFF);
                    P1DIR &= ~(pin&0xFF);
                    P1INP |= (pin&0xFF);
                  }else if( (pin & GPIO_P2) == GPIO_P2 )
                  {
                    P2SEL &= ~(pin&0xFF);
                    P2DIR &= ~(pin&0xFF);
                    P2INP |= (pin&0xFF);
                  }
    break;
  case OUTPUT:  
                  if( (pin & GPIO_P0) == GPIO_P0 )
                  {
                    P0SEL &= ~(pin & 0xFF);
                    P0DIR |= (pin&0xFF);
                  }else if( (pin & GPIO_P1) == GPIO_P1 )
                  {
                    P1SEL &= ~(pin&0xFF);
                    P1DIR |= (pin&0xFF);
                  }else if( (pin & GPIO_P2) == GPIO_P2 )
                  {
                    P2SEL &= ~(pin&0xFF);
                    P2DIR |= (pin&0xFF);
                  }
                  
    break;
  default: ;
  }
}


IO_Interrupt_IRQ IO_Interrupt_Irq[21]={NULL};
uint16_t Interrupt_IO_Table[21]={0};
uint8_t Interrupt_IO_TableCnt = 0;

/****************************************
 * 函数名： fattachInterrupt
 * 功能??  初始化IO口中?? *      
 * 参数:    pin-io口序??*fun-中断响应函数 mode-模式
 *      
 * 返回值： void
****************************************/
void fattachInterrupt(GPIO_Pin pin, void (*fun)(void), uint8_t mode)
{
  if(mode)
    fPinMode(pin,INPUT_UP);
  else
    fPinMode(pin,INPUT_DOWN);
  
  if( (pin & GPIO_P0) == GPIO_P0 )
  {
    P0IEN |= (pin&0xFF);
    if(mode)
      PICTL |= 0x01;
    IEN1 |= 0x20;
    P0IFG &= ~(pin&0xFF);
  }
  else if( (pin & GPIO_P1) == GPIO_P1 )
  {
    P1IEN |= (pin&0xFF);
    if(mode)
      if( pin &0x0F )
        PICTL |= 0x02;
      else if( pin &0xF0 )
        PICTL |= 0x04;
    IEN2 |= 0x10;
    P1IFG &= ~(pin&0xFF);
  }
  else if( (pin & GPIO_P2) == GPIO_P2 )
  {
    P2IEN |= (pin&0x1F);
    if(mode)
      PICTL |= 0x01;
    IEN1 |= 0x02;
    P2IFG &= ~(pin&0x1F);
  }

  Interrupt_IO_Table[Interrupt_IO_TableCnt++] = pin;

  IO_Interrupt_Irq[(BitToNum((pin>>8)&0xFF)*8+BitToNum(pin&0xFF))].irq = fun;
  EA = 1;

}

#pragma vector = P0INT_VECTOR
__interrupt void P0_ISR(void)
{
  uint8_t index,i;
  if(P0IFG>0) //按键中断
  {
    //Printf(0,"P0IFG:%c\r\n",P0IFG);
    for(index=0; index<8; index++)
    {
      if( (P0IFG & (0x01<<index)) == (0x01<<index) )
      {
        for(i=0; i<Interrupt_IO_TableCnt; i++)
        if(Interrupt_IO_Table[i] == GPIO_P0|(0x01<<index) )
        {
          IO_Interrupt_Irq[(BitToNum((GPIO_P0_1>>8)&0xFF)*8+BitToNum(GPIO_P0_1&0xFF))].irq();
        }
        P0IFG &= ~(0x01<<index);
        
      }
    }
    //P0IFG = 0;
  }
  P0IF = 0; //清中断标??}
}

#pragma vector = P1INT_VECTOR
__interrupt void P1_ISR(void)
{
  if(P1IFG>0) //按键中断
  {
    /*
    switch(P1IFG)
    {
    case Pin_0: P1_0IRQ();      P1IFG &= ~(Pin_0);
      break;
    case Pin_1: P1_1IRQ();      P1IFG &= ~(Pin_1);
      break;
    case Pin_2: P1_2IRQ();      P1IFG &= ~(Pin_2);
      break;
    case Pin_3: P1_3IRQ();      P1IFG &= ~(Pin_3);
      break;
    case Pin_4: P1_4IRQ();      P1IFG &= ~(Pin_4);
      break;    
    case Pin_5: P1_5IRQ();      P1IFG &= ~(Pin_5);
      break;
    case Pin_6: P1_6IRQ();      P1IFG &= ~(Pin_6);
      break;
    case Pin_7: P1_7IRQ();      P1IFG &= ~(Pin_7);
      break;
    default:;
    }
    */
    //P1IFG = 0;
  }
  P1IF = 0; //清中断标??}
}

#pragma vector = P2INT_VECTOR
__interrupt void P2_ISR(void)
{
  if(P2IFG>0) //按键中断
  {
    /*
    switch(P2IFG)
    {
    case Pin_0: P2_0IRQ();      P2IFG &= ~(Pin_0);
      break;
    case Pin_1: P2_1IRQ();      P2IFG &= ~(Pin_1);
      break;
    case Pin_2: P2_2IRQ();      P2IFG &= ~(Pin_2);
      break;
    case Pin_3: P2_3IRQ();      P2IFG &= ~(Pin_3);
      break;
    case Pin_4: P2_4IRQ();      P2IFG &= ~(Pin_4);
      break;
    default:;
    }
    */
    //P2IFG = 0;
  }
  P2IF = 0; //清中断标??}
}