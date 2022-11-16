/*
 *Generate a PWM with a 20% duty cycle and 250ms period.
 */

#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    P1DIR |= BIT6;
    P1SEL1 |= BIT6;
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 8192 - 1;
    TB0CCTL1 = OUTMOD_7;
    TB0CCR1 = 1638;
    TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR;

    while(1)
    {
        P1OUT ^= BIT6;
    }
}



