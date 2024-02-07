/* 
 * File:   application.c
 * Author: mostafa
 *
 * Created on October 30, 2023, 11:24 AM
 */

#include "application.h"


Std_ReturnType ret = E_NOT_OK;
uint8 failed_flag = 1;



void main() 
{
    uint8 number = 0;
    application_initialize();   
    Welcome_Fn();
    Again:
    lcd_4bit_send_string_pos(&LCD1 , 1 , 1 , " Enter Password: ");
    ret |= Get_Number();
    if (E_NOT_OK == ret)
    {
        goto Again;
    }
    __delay_ms(200);
    lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
    lcd_4bit_send_string_pos(&LCD1 , 1 , 1 , " Loading");
    __delay_ms(10);
    lcd_4bit_send_char_data(&LCD1 , '.');
    __delay_ms(10);
    lcd_4bit_send_char_data(&LCD1 , '.');
    __delay_ms(10);
    lcd_4bit_send_char_data(&LCD1 , '.');
    __delay_ms(300);
    ret = Check_Password();
    if ((ret == E_OK))
    {
        ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
        ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 1 , " Entry Successfully!!");
        ret |= led_turn_on(&green_led);
        ret |= led_turn_off(&red_led);
        Again2:
        __delay_ms(500);
        ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
        ret |= lcd_4bit_send_string_pos(&LCD1 , 1 , 1 , " 1- Change Password");
        ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 1 , " 2- Turn Right");
        ret |= lcd_4bit_send_string_pos(&LCD1 , 3 , 1 , " 3- Turn Left");
        ret |= lcd_4bit_send_string_pos(&LCD1 , 4 , 1 , " 4- Stop");
        ret |= Get_One_Number(&number);
        if (ret == E_NOT_OK || number == '#')
        {
               goto Again2;
        }
        switch (number)
        {
            case 1:
                ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
                lcd_4bit_send_string_pos(&LCD1 , 1 , 1 , " Enter New Password: ");
                ret |= Change_Password();
                __delay_ms(500);
                ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
                ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 1 , " Change successfully!!");
                goto Again2;
                break;
            case 2:
                ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
                ret |= dc_motor_right(&motor1);
                ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 1 , " Moving Right");
                goto Again2; 
                break;
            case 3:
                ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
                ret |= dc_motor_left(&motor1);
                ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 1 , " Moving Left");
                goto Again2; 
                break;
            case 4:
                ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
                ret |= dc_motor_stop(&motor1);
                ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 1 , " Moving Stopped");
                __delay_ms(500);
                break;  
            default: 
                ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
                ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 1 , " Invalid Number!!");
                goto Again2; 
                
        }

    }
    else
    {
        ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
        ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , " Entry Failed!!");
        __delay_ms(300);
        ret |= lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
        ret |= led_turn_on(&red_led);
        failed_flag++;
        if (failed_flag <= 3)
        {
            goto Again;
        }
        ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , " System Locked!!");
    }
    
    while(1)
    {
        ret |= Get_One_Number(&number);
        if ('#' == number)
        {
            goto Again2;
        }
        else {/* NOTHING */}
        
    }

}
    


void application_initialize (void)
{
    ecu_initialization();  
    interrupt_initialization();
}

Std_ReturnType Change_Password(void)
{   
   uint8 str1[3] , str2[3] , str3[3];
   uint8 num1 = 10 , num2 = 10 , num3 = 10;
        while (num1 == 10)
    {
        ret = keypad_get_value(&keypad1 , &num1);
       if (num1 == '*' || num1 == '/' || num1 == '-' 
            || num1 == '+' || num1 == '=')
        {
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , "Invalid Number!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            __delay_ms(100);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 5 , "Try Again!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= E_NOT_OK;
            return ret; 
        }
        else  
        {/* NOTHING*/} 
    }
    ret |= Data_EEPROM_Write_Byte(0x3F9 ,num1);
    ret |= convert_uint8_to_string(num1 , str1);
    ret |= lcd_4bit_send_string(&LCD1 , str1);
    __delay_ms(220);
    while (num2 == 10)
    {
        ret = keypad_get_value(&keypad1 , &num2);
        if (num2 == '*' || num2 == '/' || num2 == '-' 
            || num2 == '+' || num2 == '=')
        {
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , "Invalid Number!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            __delay_ms(100);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 5 , "Try Again!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= E_NOT_OK;
            return ret; 
        }
        else  
        {/* NOTHING*/} 
    }
    ret |= Data_EEPROM_Write_Byte(0x3FA ,num2);
    ret |= convert_uint8_to_string(num2 , str2);
    ret |= lcd_4bit_send_string(&LCD1 , str2);
    __delay_ms(220);
    while (num3 == 10)
    {
        ret = keypad_get_value(&keypad1 , &num3);
        if (num3 == '*' || num3 == '/' || num3 == '-' 
            || num3 == '+' || num3 == '=')
        {
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , "Invalid Number!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            __delay_ms(100);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 5 , "Try Again!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= E_NOT_OK;
            return ret; 
        }
        else  
        {/* NOTHING*/} 
    }
    ret |= Data_EEPROM_Write_Byte(0x3FB ,num3);
    ret |= convert_uint8_to_string(num3 , str3);
    ret |= lcd_4bit_send_string(&LCD1 , str3);
    return ret;
}

Std_ReturnType Get_Number(void)
{
    uint8 str1[3] , str2[3] , str3[3];
    uint8 num1 = 10 , num2 = 10 , num3 = 10;
        while (num1 == 10)
    {
        ret = keypad_get_value(&keypad1 , &num1);
       if (num1 == '*' || num1 == '/' || num1 == '-' 
            || num1 == '+' || num1 == '=')
        {
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , "Invalid Number!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            __delay_ms(100);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 5 , "Try Again!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= E_NOT_OK;
            return ret; 
            
        }
        else  
        {/* NOTHING*/} 
    }
    ret |= Data_EEPROM_Write_Byte(0x00 ,num1);
    ret |= convert_uint8_to_string(num1 , str1);
    ret |= lcd_4bit_send_string(&LCD1 , str1);
    __delay_ms(220);
    while (num2 == 10)
    {
        ret = keypad_get_value(&keypad1 , &num2);
        if (num2 == '*' || num2 == '/' || num2 == '-' 
            || num2 == '+' || num2 == '=')
        {
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , "Invalid Number!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            __delay_ms(100);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 5 , "Try Again!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= E_NOT_OK;
            return ret; 
        }
        else  
        {/* NOTHING*/} 
    }
    ret |= Data_EEPROM_Write_Byte(0x01 ,num2);
    ret |= convert_uint8_to_string(num2 , str2);
    ret |= lcd_4bit_send_string(&LCD1 , str2);
    __delay_ms(220);
    while (num3 == 10)
    {
        ret = keypad_get_value(&keypad1 , &num3);
        if (num3 == '*' || num3 == '/' || num3 == '-' 
            || num3 == '+' || num3 == '=')
        {
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , "Invalid Number!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            __delay_ms(100);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 5 , "Try Again!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= E_NOT_OK;
            return ret; 
        }
        else  
        {/* NOTHING*/} 
    }
    ret |= Data_EEPROM_Write_Byte(0x02 ,num3);
    ret |= convert_uint8_to_string(num3 , str3);
    ret |= lcd_4bit_send_string(&LCD1 , str3);
    return ret;
}

void Welcome_Fn(void)
{
    lcd_4bit_send_string_pos(&LCD1 , 2 , 7 , "Welcome");
    __delay_ms(1000);
    lcd_4bit_send_command(&LCD1 , _LCD_CLEAR);
}

Std_ReturnType Check_Password(void)
{
    Std_ReturnType check_val = E_NOT_OK;
    uint8 number1 = 0 , number2 = 0;
    uint8 value1=0 , value2 = 0;
    /* collect number from users entry individual numbers */
    ret |= Data_EEPROM_Read_Byte(0x00 , &value1);
    number1 = number1*10 + value1;
    ret |= Data_EEPROM_Read_Byte(0x01 , &value1);
    number1 = number1*10 + value1;
    ret |= Data_EEPROM_Read_Byte(0x02 , &value1);
    number1 = number1*10 + value1;
    /* collect number from Password numbers */
    ret |= Data_EEPROM_Read_Byte(0x3F9 , &value2);
    number2 = number2*10 + value2;
    ret |= Data_EEPROM_Read_Byte(0x3FA , &value2);
    number2 = number2*10 + value2;
    ret |= Data_EEPROM_Read_Byte(0x3FB , &value2);
    number2 = number2*10 + value2;
    
    if (number2 == number1)
    {
        check_val = E_OK;
    }
    return check_val;
}
Std_ReturnType Get_One_Number(uint8 *Number)
{
    uint8 str1[3];
    uint8 num1 = 10;
        while (num1 == 10)
    {
        ret = keypad_get_value(&keypad1 , &num1);
       if (num1 == '*' || num1 == '/' || num1 == '-' 
            || num1 == '+' || num1 == '=')
        {
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 3 , " Invalid Number!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            __delay_ms(100);
            ret |= lcd_4bit_send_string_pos(&LCD1 , 2 , 5 , "Try Again!!"); 
            __delay_ms(500);
            ret |= lcd_4bit_send_command( &LCD1 , _LCD_CLEAR);
            ret |= E_NOT_OK;
            return ret; 
            
        }
        else  
        {/* NOTHING*/} 
    }
    *Number = num1;
    __delay_ms(220);
    return ret;
}
