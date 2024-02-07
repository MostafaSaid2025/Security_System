/* 
 * File:   mcal_interrupt_manager.c
 * Author: mostafa
 *
 * Created on January 30, 2024, 6:38 PM
 */
#include "mcal_interrupt_manager.h"
#include "../GPIO/hal_gpio.h"

static uint8 RB4_flag = 1;
static uint8 RB5_flag = 1;
static uint8 RB6_flag = 1;
static uint8 RB7_flag = 1;

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

void __interrupt() InterruptManagerHigh(void)
{
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    if ((INTERRUPT_FEATURE_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
    else{/* NOTHING */}
   if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_flag == 1) )
    {
        RB4_flag--;
        RB4_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_LOW) && (RB4_flag == 0))
    {
        RB4_flag++;
        RB4_LOW_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_flag == 1))
    {
        RB5_flag--;
        RB5_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_LOW)&& (RB5_flag == 0))
    {
        RB5_flag++;
        RB5_LOW_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_flag == 1))
    {
        RB6_flag--;
        RB6_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_LOW) && (RB6_flag == 0))
    {
        RB6_flag++;
        RB6_LOW_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_HIGH) && (RB7_flag == 1))
    {
        RB7_flag--;
        RB7_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_LOW) && (RB7_flag == 0))
    {
        RB7_flag++;
        RB7_LOW_ISR();
    }
    else{/* NOTHING */}
    
}
void __interrupt(low_priority) InterruptManagerLOW(void)
{
     if ((INTERRUPT_FEATURE_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
}

#else

void __interrupt() InterruptManager(void)
{
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF))
    {
        INT1_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_flag == 1) )
    {
        RB4_flag--;
        RB4_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_LOW) && (RB4_flag == 0))
    {
        RB4_flag++;
        RB4_LOW_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_flag == 1))
    {
        RB5_flag--;
        RB5_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_LOW)&& (RB5_flag == 0))
    {
        RB5_flag++;
        RB5_LOW_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_flag == 1))
    {
        RB6_flag--;
        RB6_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_LOW) && (RB6_flag == 0))
    {
        RB6_flag++;
        RB6_LOW_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_HIGH) && (RB7_flag == 1))
    {
        RB7_flag--;
        RB7_HIGH_ISR();
    }
    else{/* NOTHING */}
    if ((INTERRUPT_FEATURE_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_LOW) && (RB7_flag == 0))
    {
        RB7_flag++;
        RB7_LOW_ISR();
    }
    else{/* NOTHING */}
}


#endif