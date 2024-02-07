/* 
 * File:   ecu_button.c
 * Author: mostafa
 *
 * Created on December 1, 2023, 5:53 PM
 */

#include "../button/ecu_button.h"

Std_ReturnType button_initialize (const button_t *button)
{
     Std_ReturnType ret = E_NOT_OK;
     if (NULL == button)
     {
         ret = E_NOT_OK;
     }
     else
     {
         gpio_pin_initialize (&(button->button_pin));
         ret = E_OK;
     }
     return ret;

}
Std_ReturnType button_read    (const button_t *button , button_status *button_state)
{
    Std_ReturnType ret = E_NOT_OK;
    logic_t btn_result = GPIO_LOW;
     if (NULL == button || NULL == button_state)
     {
         ret = E_NOT_OK;
     }
     else
     {
        ret = gpio_pin_read_logic (&(button->button_pin) , &btn_result);
         if (ACTIVE_HIGH == (button->button_connection))
         {
             if (1 == btn_result)
             {
                 *button_state = BUTTON_PRESSED;
             }
             else
             {
                 *button_state = BUTTON_RELEASED;
                 
             }
         
         }
         else if (ACTIVE_LOW == (button->button_connection))
         {
              if (0 == btn_result)
             {
                 *button_state = BUTTON_PRESSED;
             }
             else
             {
                 *button_state = BUTTON_RELEASED;
                 
             }
         }
         
         ret = E_OK;
     }
     return ret;

}
