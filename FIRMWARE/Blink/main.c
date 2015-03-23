#include <msp430.h>
#include "../extlib/leds.h"

int main(void)
{
    volatile unsigned int i;
    
    WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
    ledInit();
    
    while(1)                                  // continuous loop
    {
        ledToggle(1);
        ledToggle(2);
        ledToggle(3);
        for(i=50000;i>0;i--);                   // Delay
    }
}
