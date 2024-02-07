/* 
 * File:   eeprom.h
 * Author: mostafa
 *
 * Created on February 5, 2024, 4:45 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H



#endif	/* EEPROM_H */

/* Section includes */
#include "../mcal_std_types.h"
#include "../proc/pic18f4620.h"



/* Section Macro declarations */

#define ACCESS_FLASH_PROGRAM_MEMORY 1 
#define ACCESS_EEPROM_PROGRAM_MEMORY 0

#define ACCESS_CONGIFURATION_REGISETRS 1
#define ACCESS_FLASH_EEPROM_MEMORY     0

#define ALLOW_WRITE_CYCLE_FLASH_EEPROM 1 
#define INHIBITS_WRITE_CYCLE_FLASH_EEPROM 0

#define INITIATE_DATA_EEPROM_WRITE_ERASE 1
#define DATA_EEPROM_WRITE_ERASE_COMPLETED 0

#define INITIATE_DATA_EEPROM_READ 1

/* Section Macro Function declarations */

/* Section Data types declarations  */

/* Section of Software interfaces */

Std_ReturnType Data_EEPROM_Write_Byte(uint16 eeprom_adrress, uint8 eeprom_data);
Std_ReturnType Data_EEPROM_Read_Byte(uint16 eeprom_adrress , uint8 *eeprom_data);

