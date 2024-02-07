/* 
 * File:   ecu_dc_motor.h
 * Author: mosta
 *
 * Created on December 13, 2023, 2:18 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section includes */
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section Macro declarations */




/* Section Macro Function declarations */

/* Section Data types declarations  */

typedef enum
{
    DC_MOTOR_OFF,
    DC_MOTOR_ON       
}dc_motor_status_t;

typedef struct 
{
    uint8 dc_motor_port : 4;
    uint8 dc_motor_pin  : 3;
    uint8 dc_motor_status_t : 1;
}motor_t;

typedef struct
{
    motor_t dc_motor[2];
    
}motor_config_t;





/* Section Function declarations */

Std_ReturnType dc_motor_initialize (const motor_config_t *_motor);
Std_ReturnType dc_motor_right (const motor_config_t *_motor);
Std_ReturnType dc_motor_left (const motor_config_t *_motor);
Std_ReturnType dc_motor_stop (const motor_config_t *_motor);


#endif	/* ECU_DC_MOTOR_H */

