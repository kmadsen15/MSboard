#ifndef TIMERS_H
#define TIMERS_H

typedef struct
{
  char tickDivider;
  char tickThresh;
  void (*isrPtr)(void);
} timer34Config_t;

void timer3Init(timer34Config_t config);
void timer3Start(void);
void timer3Stop(void);

void timer4Init(timer34Config_t config);
void timer4Start(void);
void timer4Stop(void);

#endif

