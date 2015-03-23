#ifndef LEDS_H
#define LEDS_H

// Include
#include <msp430.h>

// Defines
#define LED_1_SEL             P1SEL
#define LED_1_DIR             P1DIR
#define LED_1_OUT             P1OUT
#define LED_1_BIT             BIT4

#define LED_2_SEL             P1SEL
#define LED_2_DIR             P1DIR
#define LED_2_OUT             P1OUT
#define LED_2_BIT             BIT5

#define LED_3_SEL             P1SEL
#define LED_3_DIR             P1DIR
#define LED_3_OUT             P1OUT
#define LED_3_BIT             BIT6

// Declarations
void ledInit(void);
void ledOn(char ledID);
void ledOff(char ledID);
void ledToggle(char ledID);

#endif