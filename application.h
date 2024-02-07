/* 
 * File:   application.h
 * Author: mostafa
 *
 * Created on October 30, 2023, 11:51 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H



/* Section includes */

#include "ECU_Layer/ECU_layer_initialization.h"
#include "MCAL_Layer/Interrupt/interrupt_initialization.h"
#include "MCAL_Layer/EEPROM/eeprom.h"

/* Section Macro declarations */

#define _XTAL_FREQ 8000000

/* Section Macro Function declarations */

/* Section Data types declarations  */

extern keypad_t keypad1;
extern lcd_4bit_t LCD1 ;
extern led_t green_led , red_led;
extern motor_config_t motor1;

/* Section of Software interfaces */

void application_initialize (void);
Std_ReturnType Change_Password(void);
Std_ReturnType Get_Number(void);
void Welcome_Fn(void);
Std_ReturnType Check_Password(void);
Std_ReturnType Get_One_Number(uint8 *Number);

#endif	/* APPLICATION_H */

