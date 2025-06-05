// an Embedded C programming language to generate a delay of one secondusing FOR loop condition.
#include "msp.h"
int main(void)
{
  volatile uint32_t i;
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // Stop watch dog timer
  P2->DIR |= 0xff;
  while(1)
  {
    P2->OUT ^= 0xff;
    for (i=1000; i>0; i--);
  }
}
