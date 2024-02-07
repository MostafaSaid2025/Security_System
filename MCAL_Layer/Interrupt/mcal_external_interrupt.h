/* 
 * File:   mcal_external_interrupt.h
 * Author: mosta
 *
 * Created on January 30, 2024, 6:38 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Section includes */
#include "mcal_interrupt_config.h"
#include "../GPIO/hal_gpio.h"


/* Section Macro declarations */

/* Section Macro Function declarations */

#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* INT0 */
#define EXT_INT0_INTERRUPT_ENALBLE()      (INTCONbits.INT0IE = 1)
#define EXT_INT0_INTERRUPT_DISALBLE()     (INTCONbits.INT0IE = 0)
#define EXT_INT0_INTERRUPT_CLEAR_FLAG()   (INTCONbits.INT0IF = 0)
#define EXT_INT0_INTERRUPT_RISING_EDGE()  (INTCON2bits.INTEDG0= 1)
#define EXT_INT0_INTERRUPT_FALLING_EDGE() (INTCON2bits.INTEDG0= 0)
/**************/
/* INT1 */
#define EXT_INT1_INTERRUPT_ENALBLE()      (INTCON3bits.INT1IE = 1)
#define EXT_INT1_INTERRUPT_DISALBLE()     (INTCON3bits.INT1IE = 0)
#define EXT_INT1_INTERRUPT_CLEAR_FLAG()   (INTCON3bits.INT1IF = 0)
#define EXT_INT1_INTERRUPT_RISING_EDGE()  (INTCON2bits.INTEDG1= 1)
#define EXT_INT1_INTERRUPT_FALLING_EDGE() (INTCON2bits.INTEDG1= 0)
/**************/
/* INT2 */
#define EXT_INT2_INTERRUPT_ENALBLE()      (INTCON3bits.INT2IE = 1)
#define EXT_INT2_INTERRUPT_DISALBLE()     (INTCON3bits.INT2IE = 0)
#define EXT_INT2_INTERRUPT_CLEAR_FLAG()   (INTCON3bits.INT2IF = 0)
#define EXT_INT2_INTERRUPT_RISING_EDGE()  (INTCON2bits.INTEDG2= 1)
#define EXT_INT2_INTERRUPT_FALLING_EDGE() (INTCON2bits.INTEDG2= 0)
/**************/
#endif

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

#define Interrupt_Priority_Levels_Enable()   (RCONbits.IPEN = 1)

/* INT1 */
#define EXT_INT1_HIGH_PRIORITYSET()       (INTCON3bits.INT1IP = 1)   
#define EXT_INT1_LOW_PRIORITYSET()        (INTCON3bits.INT1IP = 0) 
/* INT2 */
#define EXT_INT2_HIGH_PRIORITYSET()       (INTCON3bits.INT2IP= 1)   
#define EXT_INT2_LOW_PRIORITYSET()        (INTCON3bits.INT2IP = 0) 

#else 

#define Interrupt_Priority_Levels_Disable()   (RCONbits.IPEN = 0)

#endif

#if INTERRUPT_ON_CHANGE_ENABLE == INTERRUPT_FEATURE_ENABLE

#define EXT_RBX_InterruptEnable()  (INTCONbits.RBIE = 1)
#define EXT_RBX_InterruptDisable()  (INTCONbits.RBIE = 0)
#define EXT_RBX_Interrupt_ClearFlag()  (INTCONbits.RBIF = 0)

#endif

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

#define EXT_RBx_HIGH_Priority()     (INTCON2bits.RBIP = 1)
#define EXT_RBx_LOW_Priority()     (INTCON2bits.RBIP = 0)

#endif


#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

#define Global_InterruptEnable()  (INTCONbits.GIE = 1)
#define Global_InterruptEnable_HIGH()  (INTCONbits.GIEH = 1)
#define Global_InterruptEnable_LOW()  (INTCONbits.GIEL = 1)
#define Global_InterruptDisable()  (INTCONbits.GIE = 0)

#else 

#define Global_InterruptEnable()  (INTCONbits.GIE = 1)
#define Peripheral_InterruptEnable()  (INTCONbits.PEIE = 1)

#endif 

/* Section Data types declarations  */
typedef enum
{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE        
} interrupt_INTx_edge;

typedef enum
{
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2,        
           
}interrupt_INTx_source;

typedef enum
{
    EXT_RBx_INTERRUPT_LOW_HANDLER = 0,
    EXT_RBx_INTERRUPT_HIGH_HANDLER        
}EXT_RBx_HANDLER;

typedef enum 
{
    EXT_RB4_INTERRUPT = 0,
    EXT_RB5_INTERRUPT,
    EXT_RB6_INTERRUPT,        
    EXT_RB7_INTERRUPT        
}interrupt_RBx_source;



typedef struct
{
    void (*EXT_InterruptHandler)(void);
    interrupt_INTx_edge edge;
    interrupt_INTx_source source;
    pin_config_t mcu_pin;
    interrupt_priority priority;
   
}interrupt_INTx_t;

typedef struct
{
    void (*EXT_InterruptHandler)(void);
    pin_config_t mcu_pin;
    interrupt_priority priority;
    interrupt_RBx_source source;
    EXT_RBx_HANDLER interrupt_handler;

}interrupt_RBx_t;

/* section of software interfaces */

typedef void (*InterruptHandler) (void);

Std_ReturnType Interrupt_INTx_INIT(const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_INTx_DEINIT(const interrupt_INTx_t *int_obj);
Std_ReturnType Interrupt_RBx_INIT(const interrupt_RBx_t *int_obj);
Std_ReturnType Interrupt_RBx_DEINIT(const interrupt_RBx_t *int_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

