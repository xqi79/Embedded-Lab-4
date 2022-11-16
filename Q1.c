/*Problem 1
 * Using the WDT timer interrupt process, Toggle your Green LED with a 250msec interval.
 */

#include <msp430.h>

int main(void)
{
    WDTCTL = WDT_ADLY_250;      //WDT 250 ms, SMCLK, interval timer
    P6OUT &= ~BIT6;             //Green LED light
    P6DIR |= BIT6;              //Green LED light
    PM5CTL0 &= ~LOCKLPM5;       //Ends low power-mode
    SFRIE1 |= WDTIE;
    _enable_interrupts();

    while (1);
}

  #pragma vector = WDT_VECTOR
__interrupt void wdtled(void)
{
    P6OUT ^= BIT6; //Activates Green LED light after
}
