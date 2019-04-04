#include "ZStack_MSG.h"

uint8_t SandAll(char *fmt,...)
{
  return GenericApp_SendBroadcastMessage(fmt);
}


uint8_t SendGroup(char *fmt, ...)
{
  return GenericApp_SendMulticastMessage(fmt);
}


uint8_t SendPoint(uint16 trage, char *fmt, ...)
{
  return GenericApp_SendOnDemandMessage(trage,fmt);
}