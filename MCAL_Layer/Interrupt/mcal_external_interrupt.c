/* 
 * File:   mcal_external_interrupt.c
 * Author: mostafa
 *
 * Created on January 30, 2024, 6:38 PM
 */
#include "mcal_external_interrupt.h"

static InterruptHandler INT0_InterruptHandler = NULL;
static InterruptHandler INT1_InterruptHandler = NULL;
static InterruptHandler INT2_InterruptHandler = NULL;

static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
static InterruptHandler RB4_InterruptHandler_LOW = NULL;
static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
static InterruptHandler RB5_InterruptHandler_LOW = NULL;
static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
static InterruptHandler RB6_InterruptHandler_LOW = NULL;
static InterruptHandler RB7_InterruptHandler_HIGH = NULL;
static InterruptHandler RB7_InterruptHandler_LOW = NULL;


static Std_ReturnType Interrupt_INTx_Enable (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Priority_INIT (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_INIT (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_INIT (const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_ClearFlag (const interrupt_INTx_t *int_obj);

static Std_ReturnType INT0_SetInterruptHandler (void (*InterruptHandler) (void));
static Std_ReturnType INT1_SetInterruptHandler (void (*InterruptHandler) (void));
static Std_ReturnType INT2_SetInterruptHandler (void (*InterruptHandler) (void));
static Std_ReturnType INTx_SetInterruptHandler (const interrupt_INTx_t *int_obj);

static Std_ReturnType RBx_Interrupt_Enable (const interrupt_RBx_t *int_obj);
static Std_ReturnType RBx_Interrupt_Disable (const interrupt_RBx_t *int_obj);
static Std_ReturnType RBx_Interrupt_Priority_INIT (const interrupt_RBx_t *int_obj);
static Std_ReturnType RBx_Interrupt_Pin_INIT (const interrupt_RBx_t *int_obj);
static Std_ReturnType RBx_SetInterruptHandler (const interrupt_RBx_t *int_obj);


static Std_ReturnType Interrupt_INTx_Enable (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
       Interrupt_Priority_Levels_Enable();         
       Global_InterruptEnable_HIGH();
#else
       Interrupt_Priority_Levels_Disable();
       Global_InterruptEnable();
       Peripheral_InterruptEnable();
                
#endif
            EXT_INT0_INTERRUPT_ENALBLE();
            ret = E_OK;
              break;
            case INTERRUPT_EXTERNAL_INT1:
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
          Interrupt_Priority_Levels_Enable();
          if(int_obj->priority == INTERRUPT_HIGH_PRIORITY)
          {
              Global_InterruptEnable_HIGH();
          }
          else if (int_obj->priority == INTERRUPT_LOW_PRIORITY)
          {
              Global_InterruptEnable_LOW();
          }
          else
          {
              ret = E_NOT_OK;
          }
#else
       Interrupt_Priority_Levels_Disable();
       Global_InterruptEnable();
       Peripheral_InterruptEnable();   
          
#endif 
       EXT_INT1_INTERRUPT_ENALBLE();
       ret = E_OK;
              break;
              
            case INTERRUPT_EXTERNAL_INT2:
            #if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
          Interrupt_Priority_Levels_Enable();
          if(int_obj->priority == INTERRUPT_HIGH_PRIORITY)
          {
              Global_InterruptEnable_HIGH();
          }
          else if (int_obj->priority == INTERRUPT_LOW_PRIORITY)
          {
              Global_InterruptEnable_LOW();
          }
          else
          {
              ret = E_NOT_OK;
          }
#else
       Interrupt_Priority_Levels_Disable();
       Global_InterruptEnable();
       Peripheral_InterruptEnable();   
          
#endif 
       EXT_INT2_INTERRUPT_ENALBLE();
       ret = E_OK;
              break;  
       default: ret = E_NOT_OK;        
        }
         
    }
    return ret;
    
}
static Std_ReturnType Interrupt_INTx_Disable (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
       ret = E_NOT_OK; 
    }
    else
    {
        ret = E_OK;
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
                EXT_INT0_INTERRUPT_DISALBLE();
                break;
            case INTERRUPT_EXTERNAL_INT1:
                EXT_INT1_INTERRUPT_DISALBLE();
                break;
            case INTERRUPT_EXTERNAL_INT2:
                EXT_INT2_INTERRUPT_DISALBLE();
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Priority_INIT (const interrupt_INTx_t *int_obj)
{
     Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
       ret = E_NOT_OK; 
    }
    else
    {
        ret = E_OK;
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT1:
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
                if (INTERRUPT_HIGH_PRIORITY == int_obj->priority)
                {
                    EXT_INT1_HIGH_PRIORITYSET();
                }
                else if (INTERRUPT_LOW_PRIORITY == int_obj->priority)
                {
                    EXT_INT1_LOW_PRIORITYSET();
                }
                else{/* Nothing */}
                
#endif
                break;
                
                case INTERRUPT_EXTERNAL_INT2:
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
                if (INTERRUPT_HIGH_PRIORITY == int_obj->priority)
                {
                    EXT_INT2_HIGH_PRIORITYSET();
                }
                else if (INTERRUPT_LOW_PRIORITY == int_obj->priority)
                {
                    EXT_INT2_LOW_PRIORITYSET();
                }
                else{/* Nothing */}

#endif
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Edge_INIT (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
                if (INTERRUPT_RISING_EDGE == int_obj->edge)
                {
                    EXT_INT0_INTERRUPT_RISING_EDGE();
                }
                
                else if (INTERRUPT_FALLING_EDGE == int_obj->edge)
                {
                    EXT_INT0_INTERRUPT_FALLING_EDGE();
                }
                else {/* NOTHING */}
                break;
            case INTERRUPT_EXTERNAL_INT1:
                if (INTERRUPT_RISING_EDGE == int_obj->edge)
                {
                    EXT_INT1_INTERRUPT_RISING_EDGE();
                }
                
                else if (INTERRUPT_FALLING_EDGE == int_obj->edge)
                {
                    EXT_INT1_INTERRUPT_FALLING_EDGE();
                }
                else {/* NOTHING */}
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if (INTERRUPT_RISING_EDGE == int_obj->edge)
                {
                    EXT_INT2_INTERRUPT_RISING_EDGE();
                }
                
                else if (INTERRUPT_FALLING_EDGE == int_obj->edge)
                {
                    EXT_INT2_INTERRUPT_FALLING_EDGE();
                }
                else {/* NOTHING */}
                break; 
            default: ret = E_NOT_OK;    
        }
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Pin_INIT (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else 
    {
       
       ret = gpio_pin_initialize(&(int_obj->mcu_pin));         
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_ClearFlag (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else 
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
                EXT_INT0_INTERRUPT_CLEAR_FLAG();
                break;
            case INTERRUPT_EXTERNAL_INT1:
                EXT_INT1_INTERRUPT_CLEAR_FLAG();
                break;
            case INTERRUPT_EXTERNAL_INT2:
                EXT_INT2_INTERRUPT_CLEAR_FLAG();
                break;    
        }
    }
}

static Std_ReturnType INT0_SetInterruptHandler (void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INT0_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}
static Std_ReturnType INT1_SetInterruptHandler (void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INT1_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
    
}
static Std_ReturnType INT2_SetInterruptHandler (void (*InterruptHandler)(void))
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INT2_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;

}
static Std_ReturnType INTx_SetInterruptHandler (const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (int_obj->source)
        {
            case INTERRUPT_EXTERNAL_INT0:
                INT0_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1:
                INT1_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT2:
                INT2_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;    
        }
    }
}

Std_ReturnType Interrupt_INTx_INIT(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret  = Interrupt_INTx_Disable(int_obj);
        ret |= Interrupt_INTx_ClearFlag(int_obj);
        ret |= Interrupt_INTx_Edge_INIT(int_obj);
        ret |= Interrupt_INTx_Pin_INIT(int_obj);
        ret |= Interrupt_INTx_Priority_INIT(int_obj);
        ret |= INTx_SetInterruptHandler(int_obj);
        ret |= Interrupt_INTx_Enable(int_obj);
    }
    return ret;
}
Std_ReturnType Interrupt_INTx_DEINIT(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        
    }
    

}

#if INTERRUPT_ON_CHANGE_ENABLE == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType RBx_Interrupt_Enable (const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
   {
        EXT_RBX_InterruptEnable();
        Global_InterruptEnable();
   }
    return ret;
}
#endif
static Std_ReturnType RBx_Interrupt_Disable (const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
   {
        EXT_RBX_InterruptDisable();
   }
    return ret;
}
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType RBx_Interrupt_Priority_INIT (const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
   {
        Interrupt_Priority_Levels_Enable();
        switch(int_obj->priority)
        {
            case INTERRUPT_HIGH_PRIORITY:
                EXT_RBx_HIGH_Priority();
                break;
            case INTERRUPT_LOW_PRIORITY:
                EXT_RBx_LOW_Priority();
                break;    
            default: ret = E_NOT_OK;    
        }    
   }
    return ret;
}
#endif
static Std_ReturnType RBx_Interrupt_Pin_INIT (const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
   {
        gpio_pin_initialize(&(int_obj->mcu_pin));
   }
    return ret;
}

Std_ReturnType Interrupt_RBx_INIT(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    } 
    else
    {
        ret  = RBx_Interrupt_Disable(int_obj);
        ret |= EXT_RBX_Interrupt_ClearFlag();
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
        ret |= RBx_Interrupt_Priority_INIT(int_obj);
#endif
        ret |= RBx_Interrupt_Pin_INIT(int_obj);
        ret |= RBx_SetInterruptHandler(int_obj);
        ret |= RBx_Interrupt_Enable(int_obj);   
        
    }
    return ret;
}

static Std_ReturnType RBx_SetInterruptHandler (const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (int_obj->interrupt_handler)
        {
            case EXT_RBx_INTERRUPT_HIGH_HANDLER:
                if (int_obj->source == EXT_RB4_INTERRUPT)
                {
                    RB4_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler;
                    
                }
                else if (int_obj->source == EXT_RB5_INTERRUPT)
                {
                    RB5_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler;
                    
                }
                else if (int_obj->source == EXT_RB6_INTERRUPT)
                {
                    RB6_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler;
                    
                }
                else if (int_obj->source == EXT_RB7_INTERRUPT)
                {
                    RB7_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler;
                    
                }
                else {/* NOTHING */}
                break;
                
            case EXT_RBx_INTERRUPT_LOW_HANDLER:
                if (int_obj->source == EXT_RB4_INTERRUPT)
                {
                    RB4_InterruptHandler_LOW = int_obj->EXT_InterruptHandler;
                    
                }
                else if (int_obj->source == EXT_RB5_INTERRUPT)
                {
                    RB5_InterruptHandler_LOW = int_obj->EXT_InterruptHandler;
                    
                }
                else if (int_obj->source == EXT_RB6_INTERRUPT)
                {
                    RB6_InterruptHandler_LOW = int_obj->EXT_InterruptHandler;
                    
                }
                else if (int_obj->source == EXT_RB7_INTERRUPT)
                {
                    RB7_InterruptHandler_LOW = int_obj->EXT_InterruptHandler;
                    
                }
                else {/* NOTHING */}
                break;
                
            default: ret = E_NOT_OK;
        
        }
        
    }
    return ret;

}

Std_ReturnType Interrupt_RBx_DEINIT(const interrupt_RBx_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        
    }

}

void INT0_ISR(void)
{
    EXT_INT0_INTERRUPT_CLEAR_FLAG();
    if (INT0_InterruptHandler){INT0_InterruptHandler();}
    else {/* NOTHING */}
}
void INT1_ISR(void)
{
    EXT_INT1_INTERRUPT_CLEAR_FLAG();
    if (INT1_InterruptHandler){INT1_InterruptHandler();}
    else {/* NOTHING */}
}
void INT2_ISR(void)
{
    EXT_INT2_INTERRUPT_CLEAR_FLAG();
    if (INT2_InterruptHandler){INT2_InterruptHandler();}
    else {/* NOTHING */}
}

void RB4_HIGH_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB4_InterruptHandler_HIGH) {RB4_InterruptHandler_HIGH();}
    else {/* NOTHING */}
}
void RB5_HIGH_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB5_InterruptHandler_HIGH) {RB5_InterruptHandler_HIGH();}
    else {/* NOTHING */}
}
void RB6_HIGH_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB6_InterruptHandler_HIGH) {RB6_InterruptHandler_HIGH();}
    else {/* NOTHING */}
}
void RB7_HIGH_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB7_InterruptHandler_HIGH) {RB7_InterruptHandler_HIGH();}
    else {/* NOTHING */}
}
void RB4_LOW_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB4_InterruptHandler_LOW) {RB4_InterruptHandler_LOW();}
    else {/* NOTHING */}
}
void RB5_LOW_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB5_InterruptHandler_LOW) {RB5_InterruptHandler_LOW();}
    else {/* NOTHING */}
}
void RB6_LOW_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB6_InterruptHandler_LOW) {RB6_InterruptHandler_LOW();}
    else {/* NOTHING */}
}
void RB7_LOW_ISR(void)
{
    EXT_RBX_Interrupt_ClearFlag();
    if (RB7_InterruptHandler_LOW) {RB7_InterruptHandler_LOW();}
    else {/* NOTHING */}
}