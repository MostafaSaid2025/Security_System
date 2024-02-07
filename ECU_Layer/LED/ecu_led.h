/* 
 * File:   ecu_led.h
 * Author: mostafa
 *
 * Created on October 30, 2023, 11:47 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H



/* Section includes */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"

/* Section Macro declarations */

/* Section Macro Function declarations */

/* Section Data types declarations  */

typedef enum 
{
    LED_OFF,
    LED_ON        
}led_status;

typedef struct 
{
    uint8 port : 4;
    uint8 pin  : 3;
    uint8 led_status: 1;
    
}led_t;


/* Section Function declarations */

Std_ReturnType led_initialize (const led_t *led);
Std_ReturnType led_turn_on    (const led_t *led);
Std_ReturnType led_turn_off   (const led_t *led);
Std_ReturnType led_toggle     (const led_t *led);


#endif	/* ECU_LED_H */

