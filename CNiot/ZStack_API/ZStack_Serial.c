#include "ZStack_Serial.h"


/****************************************
 * 函数名： Init_Serial
 * 功能：   初始化串口
 *      
 * 参数:    port-端口
 *      
 * 返回值： void
****************************************/
void Init_Serial(uint8_t port, uint32_t baud)
{
  halUARTCfg_t uartConfig;
  uartConfig.configured           = TRUE;

  switch (baud)
  {
    case 9600:    uartConfig.baudRate = HAL_UART_BR_9600;
      break;
    case 19200:   uartConfig.baudRate = HAL_UART_BR_19200;
      break;
    case 38400:   uartConfig.baudRate = HAL_UART_BR_38400;
      break;
    case 57600:   uartConfig.baudRate = HAL_UART_BR_57600;
      break;
    case 115200:  uartConfig.baudRate = HAL_UART_BR_115200;
      break;
    default:      uartConfig.baudRate = HAL_UART_BR_9600;
      break;
  }

  uartConfig.flowControl          = FALSE;
  uartConfig.flowControlThreshold = SERIAL_THRESH;
  uartConfig.rx.maxBufSize        = SERIAL_RX_SZ;
  uartConfig.tx.maxBufSize        = SERIAL_TX_SZ;
  uartConfig.idleTimeout          = SERIAL_IDLE;
  uartConfig.intEnable            = TRUE;
  uartConfig.callBackFunc         = HAL_Serial_CallBack;
  HalUARTOpen (MT_UART_DEFAULT_PORT, &uartConfig);  /* Start UART */   

}


int Printf(uint8_t port, const char*fmt, ...)
{
  char buffer[SERIAL_RX_SZ+1];

  va_list arg_ptr;
  va_start(arg_ptr, fmt);
  vsprintf(buffer, fmt, arg_ptr);
  va_end(arg_ptr);
  
  HalUARTWrite(port, (uint8*)buffer, strlen(buffer));
  
  return strlen(buffer);
}


void HAL_Serial_CallBack(uint8 port, uint8 event)
{
  uint8 buf[SERIAL_RX_SZ];
  //(void)port;
  if (event & (HAL_UART_RX_FULL | HAL_UART_RX_ABOUT_FULL | HAL_UART_RX_TIMEOUT))
  {
    HalUARTRead(port, buf,SERIAL_RX_SZ);
    #if Serial_CallBack_Enable
    Serial_CallBack(port, buf);
    #else
    HalUARTWrite(port, (uint8*)buf,strlen((char*)buf));
    #endif
    
  }
}