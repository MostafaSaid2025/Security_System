/* 
 * File:   ECU_layer_initialization.h
 * Author: mostafa
 *
 * Created on December 20, 2023, 10:59 PM
 */

#ifndef ECU_LAYER_INITIALIZATION_H
#define	ECU_LAYER_INITIALIZATION_H

/* Section includes */

#include "LED/ecu_led.h"
#include "button/ecu_button.h"
#include "Relay/ecu_relay.h"
#include "ecu_dc_motor/ecu_dc_motor.h"
#include "Seven_Segments/ecu_seven_seg.h"
#include "../../Interfacing_Application/MCAL_Layer/../ECU_Layer/Keypad/keypad.h"
#include "LCD/LCD.h"


/* Section Macro declarations */

/* Section Macro Function declarations */

/* Section Data types declarations  */

/* Section of software interfaces */


void ecu_initialization (void);


#endif	/* ECU_LAYER_INITIALIZATION_H */

