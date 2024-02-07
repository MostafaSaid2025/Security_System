/* 
 * File:   mcal_interrupt_manager.h
 * Author: mostafa
 *
 * Created on January 30, 2024, 6:38 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* Section includes */
#include "mcal_interrupt_config.h"

/* Section Macro declarations */

/* Section Macro Function declarations */

/* Section Data types declarations  */

/* Section of Software interfaces*/
void __interrupt() InterruptManagerHigh(void);
void __interrupt(low_priority) InterruptManagerLOW(void);
void __interrupt() InterruptManager(void);

extern void INT0_ISR(void);
extern void INT1_ISR(void);
extern void INT2_ISR(void);
extern void RB4_HIGH_ISR(void);
extern void RB4_LOW_ISR(void);
extern void RB5_HIGH_ISR(void);
extern void RB5_LOW_ISR(void);
extern void RB6_HIGH_ISR(void);
extern void RB6_LOW_ISR(void);
extern void RB7_HIGH_ISR(void);
extern void RB7_LOW_ISR(void);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

