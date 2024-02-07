/* 
 * File:   interrupt_initialization.c
 * Author: mostafa
 *
 * Created on February 5, 2024, 5:29 PM
 */

#include "interrupt_initialization.h"

extern motor_config_t motor1;
extern led_t green_led , red_led;
void INT0_Handler(void)
 {
    dc_motor_stop(&motor1);
    led_turn_off(&green_led);
    led_turn_on(&red_led);
 }
void INT1_Handler(void)
 {
     
 }
void INT2_Handler(void)
 {
    
 }

void RB4_HIGH_Handler (void)
{
    
}
void RB5_HIGH_Handler (void)
{
    
}
void RB6_HIGH_Handler (void)
{
   
}
void RB7_HIGH_Handler (void)
{
 
}


interrupt_INTx_t INT0_obj = {.edge = INTERRUPT_RISING_EDGE , .priority = INTERRUPT_HIGH_PRIORITY ,
                          .source = INTERRUPT_EXTERNAL_INT0 ,.mcu_pin.pin =GPIO_PIN0 , .mcu_pin.port = PORTB_INDEX,
                          .mcu_pin.direction = GPIO_Direction_Input,
                          .EXT_InterruptHandler = INT0_Handler };

interrupt_INTx_t INT1_obj = {.edge = INTERRUPT_RISING_EDGE , .priority = INTERRUPT_LOW_PRIORITY ,
                          .source = INTERRUPT_EXTERNAL_INT1 ,.mcu_pin.pin =GPIO_PIN1 , .mcu_pin.port = PORTB_INDEX,
                          .mcu_pin.direction = GPIO_Direction_Input,
                          .EXT_InterruptHandler = INT1_Handler };

interrupt_INTx_t INT2_obj = {.edge = INTERRUPT_RISING_EDGE , .priority = INTERRUPT_HIGH_PRIORITY ,
                          .source = INTERRUPT_EXTERNAL_INT2 ,.mcu_pin.pin =GPIO_PIN2 , .mcu_pin.port = PORTB_INDEX,
                          .mcu_pin.direction = GPIO_Direction_Input,
                          .EXT_InterruptHandler = INT2_Handler }; 

interrupt_RBx_t RB4_obj = {.EXT_InterruptHandler = RB4_HIGH_Handler , .interrupt_handler = EXT_RBx_INTERRUPT_HIGH_HANDLER,
                           .mcu_pin.direction = GPIO_Direction_Input, .mcu_pin.pin = GPIO_PIN4,
                           .mcu_pin.port = PORTB_INDEX,.priority =INTERRUPT_HIGH_PRIORITY ,.source = EXT_RB4_INTERRUPT};

interrupt_RBx_t RB5_obj = {.EXT_InterruptHandler = RB5_HIGH_Handler , .interrupt_handler = EXT_RBx_INTERRUPT_HIGH_HANDLER,
                           .mcu_pin.direction = GPIO_Direction_Input, .mcu_pin.pin = GPIO_PIN5,
                           .mcu_pin.port = PORTB_INDEX,.priority =INTERRUPT_HIGH_PRIORITY ,.source = EXT_RB5_INTERRUPT};

interrupt_RBx_t RB6_obj = {.EXT_InterruptHandler = RB6_HIGH_Handler , .interrupt_handler = EXT_RBx_INTERRUPT_HIGH_HANDLER,
                           .mcu_pin.direction = GPIO_Direction_Input, .mcu_pin.pin = GPIO_PIN6,
                           .mcu_pin.port = PORTB_INDEX,.priority =INTERRUPT_HIGH_PRIORITY ,.source = EXT_RB6_INTERRUPT};

interrupt_RBx_t RB7_obj = {.EXT_InterruptHandler = RB7_HIGH_Handler , .interrupt_handler = EXT_RBx_INTERRUPT_HIGH_HANDLER,
                           .mcu_pin.direction = GPIO_Direction_Input, .mcu_pin.pin = GPIO_PIN7,
                           .mcu_pin.port = PORTB_INDEX,.priority =INTERRUPT_HIGH_PRIORITY ,.source = EXT_RB7_INTERRUPT};



void interrupt_initialization(void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = Interrupt_INTx_INIT(&(INT0_obj));
    ret = Interrupt_INTx_INIT(&(INT1_obj));
    ret = Interrupt_INTx_INIT(&(INT2_obj));
    ret = Interrupt_RBx_INIT(&RB4_obj);
    ret = Interrupt_RBx_INIT(&RB5_obj);
    ret = Interrupt_RBx_INIT(&RB6_obj);
    ret = Interrupt_RBx_INIT(&RB7_obj);

}
