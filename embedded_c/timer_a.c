// an Embedded C code to demonstrate the operation of OUTMODS with Control Modes (UP, Continuous, UP/DOWN).
#include "msp.h"

void TimerA0_Config(void);

int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;  // Stop WDT

    P1->DIR |= BIT0;          // P1.0 as output (LED)
    P1->OUT &= ~BIT0;

    P2->DIR |= BIT4;          // P2.4 as output (TA0.1)
    P2->SEL0 |= BIT4;         // Select TA0.1 functionality
    P2->SEL1 &= ~BIT4;

    TimerA0_Config();         // Configure Timer_A0

    __enable_irq();           // Enable global interrupts

    NVIC->ISER[0] |= 1 << ((TA0_0_IRQn) & 31);   // Enable CCR0 interrupt
    NVIC->ISER[0] |= 1 << ((TA0_N_IRQn) & 31);   // Enable CCR1, TAIFG interrupt

    while (1)
    {
        __sleep();            // Sleep until interrupt
        __no_operation();     // For debugger
    }
}

void TimerA0_Config(void)
{
    // Set TimerA0 to Up mode, SMCLK ~3MHz, divide by 1
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK |      // SMCLK
                    TIMER_A_CTL_MC__UP |           // Up Mode
                    TIMER_A_CTL_CLR;               // Clear TAR

    TIMER_A0->CCR[0] = 30000 - 1;                  // PWM period (~10ms)
    TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE;        // Enable interrupt for CCR0

    TIMER_A0->CCR[1] = 15000;                      // 50% duty cycle
    TIMER_A0->CCTL[1] = TIMER_A_CCTLN_OUTMOD_7;    // OUTMOD_7: Reset/Set
}

/* CCR0 interrupt (TA0.0) — used to toggle LED */
void TA0_0_IRQHandler(void)
{
    TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;     // Clear interrupt flag
    P1->OUT ^= BIT0;                               // Toggle LED
}

/* TA0_N interrupt (CCR1, TAIFG) — not used much here but necessary if needed */
void TA0_N_IRQHandler(void)
{
    if (TIMER_A0->CCTL[1] & TIMER_A_CCTLN_CCIFG)
    {
        TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG; // Clear CCR1 interrupt flag
        // Optional additional logic
    }

    if (TIMER_A0->CTL & TIMER_A_CTL_IFG)
    {
        TIMER_A0->CTL &= ~TIMER_A_CTL_IFG;         // Clear TAIFG
        // Optional logic for overflow
    }
}

// Up Mode:
TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR;

// Continuous Mode:
TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__CONTINUOUS | TIMER_A_CTL_CLR;

// Up/Down Mode:
TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UPDOWN | TIMER_A_CTL_CLR;
