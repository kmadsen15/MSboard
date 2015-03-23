#include "msp430.h"
#include "timers.h"

void (*timer3IsrPtr)(void);
void (*timer4IsrPtr)(void);
char tickThreshSave3, tickThreshSave4;

#pragma vector=0x5B
__interrupt void timer3Isr(void)
{
  timer3IsrPtr();
}

#pragma vector=0x63
__interrupt void timer4Isr(void)
{
  timer4IsrPtr();
}

void timer3Init(timer34Config_t config)
{
  
  //Clear timer count
  T3CTL |= 1 << 2;
  
  //Set up tick divider
  T3CTL = config.tickDivider << 5;
  
  //Turn on interrupt enable
  T3CTL |= 1 << 3;
  IEN1 |= 1 << 3;
  //T3CCTL0 |= 1 << 6;
  
  //Set to "down" mode, must restart after ISR
  T3CTL |= 0x01;
  
  //Set the tick threshold count in T3CC0
  T3CC0 = config.tickThresh;
  tickThreshSave3 = config.tickThresh;
  
  //Set up ISR
  timer3IsrPtr = config.isrPtr;
}

void timer3Start(void)
{
  //Reset timer count
  T3CC0 = tickThreshSave3;
  T3CTL |= 1<<4; //Start timer
}

void timer3Stop(void)
{
  T3CTL &= ~(1<<4); //Stop timer
}


void timer4Init(timer34Config_t config)
{
  
  //Clear timer count
  T4CTL |= 1 << 2;
  
  //Set up tick divider
  T4CTL = config.tickDivider << 5;
  
  //Turn on interrupt enable
  T4CTL |= 1 << 3;
  IEN1 |= 1 << 4;
  //T3CCTL0 |= 1 << 6;
  
  //Set to "down" mode, must restart after ISR
  T4CTL |= 0x01;
  
  //Set the tick threshold count in T3CC0
  T4CC0 = config.tickThresh;
  tickThreshSave4 = config.tickThresh;
  
  //Set up ISR
  timer4IsrPtr = config.isrPtr;
}
void timer4Start(void)
{
  //Reset timer count
  T4CC0 = tickThreshSave4;
  T4CTL |= 1<<4; //Start timer
}

void timer4Stop(void)
{
  T4CTL &= ~(1<<4); //Stop timer
}



