// example-5 : an Embedded C programming language to generate a delay of one secondusing Timer32.
#include "msp.h"
#include <stdint.h>

void Timer32_1_Init(void);

int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // Stop watchdog timer

    P1->DIR |= BIT0;       // Set P1.0 as output
    P1->OUT &= ~BIT0;      // Turn off LED

    Timer32_1_Init();      // Initialize Timer32_1

    __enable_irq();        // Enable global interrupts
    while (1)
    {
        __sleep();         // Enter low power mode
        __no_operation();  // For debugger
    }
}

// Initialize Timer32_1 for 1 second delay with interrupt
void Timer32_1_Init(void)
{
    // Timer clock = MCLK = 3 MHz assumed
    TIMER32_1->CONTROL = 0;                         // Stop timer
    TIMER32_1->LOAD = 3000000 - 1;                  // 1 second @ 3 MHz
    TIMER32_1->INTCLR = 0;                          // Clear interrupt flag
    TIMER32_1->CONTROL = TIMER32_CONTROL_ENABLE     // Enable timer
                       | TIMER32_CONTROL_MODE       // Periodic mode
                       | TIMER32_CONTROL_SIZE       // 32-bit mode
                       | TIMER32_CONTROL_IE;        // Enable interrupt

    NVIC_EnableIRQ(T32_INT1_IRQn);                  // Enable NVIC interrupt
}

// Timer32_1 ISR
void T32_INT1_IRQHandler(void)
{
    TIMER32_1->INTCLR = 0;  // Clear interrupt
    P1->OUT ^= BIT0;        // Toggle LED on P1.0
}
