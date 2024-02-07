/* 
 * File:   ecu_button.h
 * Author: mostafa
 *
 * Created on December 1, 2023, 5:53 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H


/* Section includes */

#include "../button/ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/* Section Macro declarations */

/* Section Macro Function declarations */

/* Section Data types declarations  */

typedef enum 
{
    BUTTON_PRESSED,
    BUTTON_RELEASED        
}button_status;

typedef enum 
{   
    ACTIVE_HIGH,
    ACTIVE_LOW       
}btn_active_t;

typedef struct 
{
    pin_config_t button_pin;
    button_status button_state;
    btn_active_t button_connection;
    
}button_t;


/* Section Function declarations */

Std_ReturnType button_initialize (const button_t *button);
Std_ReturnType button_read    (const button_t *button , button_status *button_state);
#endif	/* ECU_BUTTON_H */

