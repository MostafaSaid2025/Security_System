/* 
 * File:   ecu_led.c
 * Author: mostafa
 *
 * Created on October 30, 2023, 11:47 AM
 */

#include "ecu_led.h"

Std_ReturnType led_initialize (const led_t *led)
{
     Std_ReturnType ret = E_NOT_OK;
     if (NULL == led)
     {
         ret = E_NOT_OK;
     }
     else
     {
         pin_config_t pin_obj = {.port = led->port , .pin = led->pin,
                                 .direction = GPIO_Direction_Output , .logic = led->led_status};
         gpio_pin_initialize (&pin_obj);
         ret = E_OK;
     }
     return ret;
    
    
}
Std_ReturnType led_turn_on    (const led_t *led)
{
     Std_ReturnType ret = E_NOT_OK;
     if (NULL == led)
     {
         ret = E_NOT_OK;
     }
     else
     {
         pin_config_t pin_obj = {.port = led->port , .pin = led->pin,
                                 .logic = led->led_status, .direction = GPIO_Direction_Output};
         gpio_pin_write_logic (&pin_obj , GPIO_HIGH);
         ret = E_OK;
        
     }
     return ret;
    
}
Std_ReturnType led_turn_off   (const led_t *led)
{
     Std_ReturnType ret = E_NOT_OK;
     if (NULL == led)
     {
         ret = E_NOT_OK;
     }
     else
     {
         pin_config_t pin_obj = {.port = led->port , .pin = led->pin,
                                 .logic = led->led_status, .direction = GPIO_Direction_Output};
         gpio_pin_write_logic (&pin_obj , GPIO_LOW);
         ret = E_OK;
     }
     return ret;
    
}
Std_ReturnType led_toggle     (const led_t *led)
{
     Std_ReturnType ret = E_NOT_OK;
     if (NULL == led)
     {
         ret = E_NOT_OK;
     }
     else
     {
         pin_config_t pin_obj = {.port = led->port , .pin = led->pin,
                                 .logic = led->led_status, .direction = GPIO_Direction_Output};
         gpio_pin_toggle_logic (&pin_obj);
         ret = E_OK;
     }
     return ret;
    
}
