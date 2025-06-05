// example-4 : an Embedded C programming language to generate a delay of one second using SysTick Timer.
#include "msp.h"
void SysTick_Init(void);
int main(void)
{
    // Stop watchdog timer
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // Configure P1.0 as output (LED)
    P1->DIR |= BIT0;
    P1->OUT &= ~BIT0;

    // Initialize SysTick Timer
    SysTick_Init();

    __enable_irq();  // Enable global interrupts

    while (1)
    {
        __sleep();   // Enter low power mode until interrupt occurs
    }
}

// SysTick Initialization: 1-second delay with 3 MHz clock
void SysTick_Init(void)
{
    SysTick->CTRL = 0;                 // Disable SysTick during setup
    SysTick->LOAD = 3000000 - 1;       // 1 second @ 3 MHz system clock
    SysTick->VAL = 0;                  // Clear current value register
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |  // Use system clock
                    SysTick_CTRL_TICKINT_Msk   |  // Enable interrupt
                    SysTick_CTRL_ENABLE_Msk;      // Enable SysTick timer
}

// SysTick Interrupt Handler
void SysTick_Handler(void)
{
    P1->OUT ^= BIT0;  // Toggle LED
}
