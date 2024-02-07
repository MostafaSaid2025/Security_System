/* 
 * File:   ecu_dc_motor_cfg.h
 * Author: mosta
 *
 * Created on December 13, 2023, 2:18 AM
 */

#include "ecu_dc_motor.h"
static pin_config_t motor1;
static pin_config_t motor2;

Std_ReturnType dc_motor_initialize (const motor_config_t *_motor)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _motor)
    {
        ret = E_NOT_OK;
    }
    else
    {   
        motor1.port = _motor->dc_motor[0].dc_motor_port;
        motor1.pin = _motor->dc_motor[0].dc_motor_pin;
        motor1.direction = GPIO_Direction_Output;
        motor1.logic = _motor->dc_motor[0].dc_motor_status_t;
        motor2.port = _motor->dc_motor[1].dc_motor_port;
        motor2.pin = _motor->dc_motor[1].dc_motor_pin;
        motor2.direction = GPIO_Direction_Output;
        motor2.logic = _motor->dc_motor[1].dc_motor_status_t;
       
        gpio_pin_initialize(&motor1);
        gpio_pin_initialize(&motor2);
        
    
    }
    return ret;
}
Std_ReturnType dc_motor_right (const motor_config_t *_motor)
{
     Std_ReturnType ret = E_OK;
    if (NULL == _motor)
    {
        ret = E_NOT_OK;
    }
    else
    {   
        gpio_pin_write_logic(&motor1,GPIO_HIGH);
        gpio_pin_write_logic(&motor2,GPIO_LOW );
        
    }
    return ret;
     

}
Std_ReturnType dc_motor_left (const motor_config_t *_motor)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _motor)
    {
        ret = E_NOT_OK;
    }
    else
    {   

        gpio_pin_write_logic(&motor1,GPIO_LOW);
        gpio_pin_write_logic(&motor2,GPIO_HIGH );
        
    
    }
    return ret;

}
/**
 * 
 * @param _motor
 * @return 
 */
Std_ReturnType dc_motor_stop (const motor_config_t *_motor)
{ 
    Std_ReturnType ret = E_OK;
    if (NULL == _motor)
    {
        ret = E_NOT_OK;
    }
    else
    {   
        gpio_pin_write_logic(&motor1 ,GPIO_LOW);
        gpio_pin_write_logic(&motor2 ,GPIO_LOW );
        
    
    }
    return ret;

}