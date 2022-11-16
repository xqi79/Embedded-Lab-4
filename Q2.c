/*
 *Generate a PWM with a 10% duty cycle and 500ms period using polling process.
*/

#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       //Stop WDT
    P1DIR |= BIT6;                  //P1.6 output
    P1SEL1 |= BIT6;                 //P1.6 option select
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 16384 - 1;            //PWM period
    TB0CCTL1 = OUTMOD_7;            //CCR1 reset/set
    TB0CCR1 = 1638;               //CCR1 PWM Duty Cycle
    TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR;         //ACLK, up-mode, clear TBR

    while (1)
    {
        P1OUT ^= BIT6;      //For debugger
    }
}

