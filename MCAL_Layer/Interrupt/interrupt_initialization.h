/* 
 * File:   interrupt_initialization.h
 * Author: mostafa
 *
 * Created on February 5, 2024, 5:29 PM
 */

#ifndef INTERRUPT_INITIALIZATION_H
#define	INTERRUPT_INITIALIZATION_H

/* Section includes */

#include "mcal_external_interrupt.h"
#include "mcal_interrupt_internal.h"
#include "mcal_interrupt_manager.h"
#include "../../ECU_Layer/ECU_layer_initialization.h"

/* Section Macro declarations */
#define _XTAL_FREQ 8000000

/* Section Macro Function declarations */

/* Section Data types declarations  */

/* Section of Software interfaces */

void interrupt_initialization(void);

#endif	/* INTERRUPT_INITIALIZATION_H */

