#include "CNiot.h"

void Flash(void);

#ifdef ZDO_COORDINATOR


#else


#endif 

void setup(void)
{
  Init_Serial(1,115200);

  //初始化T4用于支持 TimeOut
  T4_Init();

  Ticker(Flash,1);

  //初始化LED
  PinMode(P1_0,OUTPUT);
  PinMode(P1_1,OUTPUT);
  PinMode(P1_4,OUTPUT);

#ifdef ZDO_COORDINATOR

  OLED_Init();                      //oled 初始化  
  OLED_CLS();                      //屏全亮 
  OLED_welcome();

#else



#endif 

  Printf(0," Sys is ready\r\n");
}

void loop(void)
{
#ifdef ZDO_COORDINATOR
  

#else 



#endif 
}

void Flash(void)
{
  LED1 = !LED1;
  
}



void Serial_CallBack(uint8_t port, uint8_t* buf)
{
  Printf(port,"OK\r\n");
}


void MessageProcess(uint16_t addr, uint8_t *data)
{
  LED3 =!LED3;
  Printf(0,"Receive:%d>_%s\r\n",addr,data);
#ifdef ZDO_COORDINATOR
  
 
#else

  
#endif
}

void NETState_Process(devStates_t devState)
{
  switch (devState)
  {
    //作为协调   
    case DEV_ZB_COORD:    Printf(0,"This is Coordinator\r\n");
      break;
    //作为路由
    case DEV_ROUTER:      Printf(0,"This is Route\r\n");
      break;
    //作为终端
    case DEV_END_DEVICE:  Printf(0,"This is EndDevice\r\n");
                          
      break;

    default:
      break;
  }
}