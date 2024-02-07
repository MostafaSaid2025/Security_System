/* 
 * File:   mcal_interrupt_config.h
 * Author: mostafa
 *
 * Created on January 30, 2024, 6:45 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* Section includes */
#include "../mcal_std_types.h"
#include "../proc/pic18f4620.h"
#include "mcal_interrupt_gen_cfg.h"


/* Section Macro declarations */

/* Section Macro Function declarations */

/* Section Data types declarations  */
typedef enum 
{
    INTERRUPT_HIGH_PRIORITY = 0,
    INTERRUPT_LOW_PRIORITY        
}interrupt_priority;



#endif	/* MCAL_INTERRUPT_CONFIG_H */

