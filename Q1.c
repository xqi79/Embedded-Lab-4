#include <msp430.h>

int main(void)
{
    WDTCTL = WDT_ADLY_250;
    P6OUT &= ~BIT6;
    P6DIR |= BIT6;
    PM5CTL0 &= ~LOCKLPM5;
    SFRIE1 |= WDTIE;
    _enable_interrupts();

    while (1)
        ;
}

#pragma vector=WDT_VECTOR
__interrupt void wdtled(void)

{

    P6OUT ^= BIT6;
}
