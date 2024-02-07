/* 
 * File:   ECU_layer_initialization.c
 * Author: mostafa
 *
 * Created on December 20, 2023, 10:59 PM
 */

#include"ECU_layer_initialization.h"

keypad_t keypad1 = {.ECU_KEYPAD_ROWS_PINS[0].port = PORTD_INDEX , .ECU_KEYPAD_ROWS_PINS[0].pin = GPIO_PIN0,
                     .ECU_KEYPAD_ROWS_PINS[0].direction = GPIO_Direction_Output , .ECU_KEYPAD_ROWS_PINS[0].logic = GPIO_LOW,
                     .ECU_KEYPAD_ROWS_PINS[1].port = PORTD_INDEX , .ECU_KEYPAD_ROWS_PINS[1].pin = GPIO_PIN1,
                     .ECU_KEYPAD_ROWS_PINS[1].direction = GPIO_Direction_Output , .ECU_KEYPAD_ROWS_PINS[0].logic = GPIO_LOW,
                     .ECU_KEYPAD_ROWS_PINS[2].port = PORTD_INDEX , .ECU_KEYPAD_ROWS_PINS[2].pin = GPIO_PIN2,
                     .ECU_KEYPAD_ROWS_PINS[2].direction = GPIO_Direction_Output , .ECU_KEYPAD_ROWS_PINS[0].logic = GPIO_LOW,
                     .ECU_KEYPAD_ROWS_PINS[3].port = PORTD_INDEX , .ECU_KEYPAD_ROWS_PINS[3].pin = GPIO_PIN3,
                     .ECU_KEYPAD_ROWS_PINS[3].direction = GPIO_Direction_Output , .ECU_KEYPAD_ROWS_PINS[0].logic = GPIO_LOW,
                     .ECU_KEYPAD_COLUMNS_PINS[0].port = PORTD_INDEX , .ECU_KEYPAD_COLUMNS_PINS[0].pin = GPIO_PIN4,
                     .ECU_KEYPAD_COLUMNS_PINS[0].direction = GPIO_Direction_Input , .ECU_KEYPAD_COLUMNS_PINS[0].logic = GPIO_LOW,
                     .ECU_KEYPAD_COLUMNS_PINS[1].port = PORTD_INDEX , .ECU_KEYPAD_COLUMNS_PINS[1].pin = GPIO_PIN5,
                     .ECU_KEYPAD_COLUMNS_PINS[1].direction = GPIO_Direction_Input , .ECU_KEYPAD_COLUMNS_PINS[1].logic = GPIO_LOW,
                     .ECU_KEYPAD_COLUMNS_PINS[2].port = PORTD_INDEX , .ECU_KEYPAD_COLUMNS_PINS[2].pin = GPIO_PIN6,
                     .ECU_KEYPAD_COLUMNS_PINS[2].direction = GPIO_Direction_Input , .ECU_KEYPAD_COLUMNS_PINS[2].logic = GPIO_LOW,
                     .ECU_KEYPAD_COLUMNS_PINS[3].port = PORTD_INDEX , .ECU_KEYPAD_COLUMNS_PINS[3].pin = GPIO_PIN7,
                     .ECU_KEYPAD_COLUMNS_PINS[3].direction = GPIO_Direction_Input , .ECU_KEYPAD_COLUMNS_PINS[3].logic = GPIO_LOW,};
 

lcd_4bit_t LCD1 = 
{
    .lcd_rs.port = PORTC_INDEX , .lcd_rs.pin = GPIO_PIN0 , .lcd_rs.direction = GPIO_Direction_Output , .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX , .lcd_en.pin = GPIO_PIN1 , .lcd_en.direction = GPIO_Direction_Output , .lcd_en.logic = GPIO_LOW,
    .lcd_pin[0].port = PORTC_INDEX , .lcd_pin[0].pin = GPIO_PIN2 , 
    .lcd_pin[0].direction = GPIO_Direction_Output , .lcd_pin[0].logic = GPIO_LOW,
    .lcd_pin[1].port = PORTC_INDEX , .lcd_pin[1].pin = GPIO_PIN3 , 
    .lcd_pin[1].direction = GPIO_Direction_Output , .lcd_pin[1].logic = GPIO_LOW,
    .lcd_pin[2].port = PORTC_INDEX , .lcd_pin[2].pin = GPIO_PIN4 , 
    .lcd_pin[2].direction = GPIO_Direction_Output , .lcd_pin[2].logic = GPIO_LOW,
    .lcd_pin[3].port = PORTC_INDEX , .lcd_pin[3].pin = GPIO_PIN5 , 
    .lcd_pin[3].direction = GPIO_Direction_Output , .lcd_pin[3].logic = GPIO_LOW,
}; 

led_t green_led = {.led_status = GPIO_LOW , .port = PORTA_INDEX , .pin = GPIO_PIN0};
led_t red_led   = {.led_status = GPIO_LOW , .port = PORTA_INDEX , .pin = GPIO_PIN1};

motor_config_t motor1 = {.dc_motor[0].dc_motor_port = PORTA_INDEX , .dc_motor[0].dc_motor_pin = GPIO_PIN2,
                         .dc_motor[0].dc_motor_status_t = GPIO_LOW ,.dc_motor[1].dc_motor_port = PORTA_INDEX ,
                         .dc_motor[1].dc_motor_pin = GPIO_PIN3,.dc_motor[1].dc_motor_status_t = GPIO_LOW};


void ecu_initialization (void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret |= lcd_4bit_initialize(&LCD1);
    ret |= led_initialize(&green_led);
    ret |= led_initialize(&red_led);
    ret |= keypad_initialize(&keypad1);
    ret |= dc_motor_initialize (&motor1);
}