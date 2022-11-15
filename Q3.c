#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    P1DIR |= BIT6 | BIT7;
    P1SEL1 |= BIT6 | BIT7;
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 8192-1;
    TB0CCTL1 = OUTMOD_7;
    TB0CCR1 = 1638;
    TB0CCTL2 = OUTMOD_7;
    TB0CCR2 = 14746;
    TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR;

    while(1)
    {
        P1OUT ^=BIT6;
    }
}



