
#include "leds.h"

void ledInit(void)
{
    LED_1_OUT |= LED_1_BIT;
    LED_1_SEL &= ~LED_1_BIT;
    LED_1_DIR |= LED_1_BIT;
    
    LED_2_OUT |= LED_2_BIT;
    LED_2_SEL &= ~LED_2_BIT;
    LED_2_DIR |= LED_2_BIT;
    
    LED_3_OUT |= LED_3_BIT;
    LED_3_SEL &= ~LED_3_BIT;
    LED_3_DIR |= LED_3_BIT;
}

void ledOn(char ledID)
{
    switch(ledID)
    {
        case 1:
            LED_1_OUT &= ~LED_1_BIT;
            break;
        case 2:
            LED_2_OUT &= ~LED_2_BIT;
            break;
        case 3:
            LED_3_OUT &= ~LED_3_BIT;
            break;
        default:
            break;
    }
}

void ledOff(char ledID)
{
    switch(ledID)
    {
        case 1:
            LED_1_OUT |= LED_1_BIT;
            break;
        case 2:
            LED_2_OUT |= LED_2_BIT;
            break;
        case 3:
            LED_3_OUT |= LED_3_BIT;
            break;
        default:
            break;
    }
}

void ledToggle(char ledID)
{
    switch(ledID)
    {
        case 1:
            LED_1_OUT ^= LED_1_BIT;
            break;
        case 2:
            LED_2_OUT ^= LED_2_BIT;
            break;
        case 3:
            LED_3_OUT ^= LED_3_BIT;
            break;
        default:
            break;
    }
}