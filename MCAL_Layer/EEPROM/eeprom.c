/* 
 * File:   eeprom.h
 * Author: mostafa
 *
 * Created on February 5, 2024, 4:45 PM
 */

#include "eeprom.h"

/**
 * @brief Writes a byte of data to the EEPROM of PIC18F4620
 * @param eeprom_adrress: The address in EEPROM where the data will be written
 * @param eeprom_data: The data to be written to the specified EEPROM address
 * @return Std_ReturnType: Returns E_OK if the write operation is successful, otherwise an error code
 */
Std_ReturnType Data_EEPROM_Write_Byte(uint16 eeprom_adrress, uint8 eeprom_data)
{
    // Store the current state of global interrupts
    uint8 Global_interrupt_status = INTCONbits.GIE;

    // Set the upper address bits of the EEPROM address
    EEADRH = (uint8)(eeprom_adrress >> 8) & (0x03);

    // Set the lower address bits of the EEPROM address
    EEADR = (uint8)(eeprom_adrress & 0xff);

    // Set the data to be written to the EEPROM
    EEDATA = eeprom_data;

    // Configure EEPROM Control Register 1
    EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY; // Point to EEPROM data memory
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;    // Access flash program or data memory
    EECON1bits.WREN = ALLOW_WRITE_CYCLE_FLASH_EEPROM; // Enable write to EEPROM

    // Disable global interrupts during EEPROM write operation
    INTCONbits.GIE = 0;

    // Perform the unlock sequence as required by the datasheet
    EECON2 = 0x55;
    EECON2 = 0xAA;

    // Start the EEPROM write operation
    EECON1bits.WR = INITIATE_DATA_EEPROM_WRITE_ERASE;

    // Wait for the write operation to complete
    while (EECON1bits.WR);

    // Disable write to EEPROM after write operation
    EECON1bits.WREN = INHIBITS_WRITE_CYCLE_FLASH_EEPROM;

    // Restore the global interrupt state to its original value
    INTCONbits.GIE = Global_interrupt_status;

    // Return the status of the write operation
    return E_OK; // Assuming success; you may want to add error handling and return appropriate error code if needed
}

/**
 * @brief Reads a byte of data from the EEPROM of PIC18F4620
 * @param eeprom_adrress: The address in EEPROM from where the data will be read
 * @param eeprom_data: Pointer to store the read data
 * @return Std_ReturnType: Returns E_OK if the read operation is successful, otherwise E_NOT_OK
 */
Std_ReturnType Data_EEPROM_Read_Byte(uint16 eeprom_adrress, uint8 *eeprom_data)
{
    Std_ReturnType ret = E_NOT_OK;

    // Check if the provided pointer for storing data is valid
    if (NULL == eeprom_data)
    {
        ret = E_NOT_OK; // Invalid pointer, return error
    }
    else
    {
        // Set the upper address bits of the EEPROM address
        EEADRH = (uint8)(eeprom_adrress >> 8) & (0x03);

        // Set the lower address bits of the EEPROM address
        EEADR = (uint8)(eeprom_adrress & 0xff);

        // Configure EEPROM Control Register 1
        EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY; // Point to EEPROM data memory
        EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;    // Access flash program or data memory
        EECON1bits.RD = INITIATE_DATA_EEPROM_READ;        // Start the EEPROM read operation

        NOP();
        NOP(); // Delay for data to be available

        // Read the data from EEPROM and store it at the provided memory location
        *eeprom_data = EEDATA;

        ret = E_OK; // Set return status to success
    }

    return ret;
}
