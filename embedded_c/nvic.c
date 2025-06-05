// example-2 : an Embedded C code to turn on LED P1.0 when P1.1 switch is pressed. Map P1.1 switch as a handler.
#include "msp.h"

#define LED1 BIT0      // P1.0
#define S1   BIT1      // P1.1

void main(void)
{
    // Stop Watchdog Timer
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // Configure P1.0 as output (LED)
    P1DIR |= LED1;        // Set P1.0 as output
    P1OUT &= ~LED1;       // Initially LED OFF

    // Configure P1.1 as input with pull-up resistor (switch)
    P1DIR &= ~S1;         // Set P1.1 as input
    P1REN |= S1;          // Enable pull-up/down resistor
    P1OUT |= S1;          // Select pull-up

    // Enable interrupt on P1.1
    P1IE  |= S1;          // Enable interrupt for P1.1
    P1IES |= S1;          // Interrupt on high-to-low transition (press)
    P1IFG &= ~S1;         // Clear interrupt flag

    // Enable Port 1 interrupt in NVIC (Position 35 = bit 3 of ISER[1])
    NVIC->ISER[1] = 1 << (PORT1_IRQn & 31);

    // Enable global interrupts
    __enable_irq();

    while (1);  // Infinite loop
}

// Port 1 ISR
void PORT1_IRQHandler(void)
{
    if (P1IFG & S1)        // If interrupt is due to P1.1
    {
        P1OUT |= LED1;     // Turn ON LED at P1.0
        P1IFG &= ~S1;      // Clear the interrupt flag
    }
}
