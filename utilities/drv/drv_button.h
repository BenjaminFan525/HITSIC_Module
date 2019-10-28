#ifndef _DRV_BUTTON_H_
#define _DRV_BUTTON_H_
#include "stdafx.h"
#include "hitsic_common.h"
#include "sys_extint.h"
#include "sys_pitmgr.h"

#ifdef __cplusplus
extern "C"{
#endif


#define BUTTON_TIME_SHRT 10u     //short press
#define BUTTON_SHRT_TOUT 200u	//short timeout
#define BUTTON_TIME_LONG 250u   //long press
#define BUTTON_TIME_LRPT 100u   //long press repeat, time calculated from key press. the actual time for repeat will be REPT-LONG
#define BUTTON_REPT_TOUT 300u   //repeat timeout
#define BUTTON_TIME_INTV 50u

#define BUTTON_PRESSDN_LOGIC 0u
#define BUTTON_RELEASE_LOGIC 1u
#define BUTTON_PRESSDN_EXTINT kPORT_InterruptFallingEdge //define which edge indicates button pressed.
#define BUTTON_RELEASE_EXTINT kPORT_InterruptRisingEdge  //define which edge indicates button release.

#define BUTTON_PITMGR_TIME_MS 10

#define BUTTON_TIMER_MS     (PITMGR_GetLTC_ms()) 

    typedef enum 
    {
        BUTTON_STAT_NONE = 0, //button no operation
        BUTTON_SHRT_PRES = 1, //button short press
        BUTTON_SHRT_CLER = 2, //service responded short press
        BUTTON_LONG_PRES = 3, //button long press
        BUTTON_LONG_CLER = 4, //service responded long press
        BUTTON_LRPT_PRES = 5, //button long_repeat press
        BUTTON_LRPT_CLER = 6, //service responded long_repeat press
    }button_status_t;

    //typedef struct button_t;

    typedef void(*button_handler_t)(void* _inst);       //TODO: fix this void*

    typedef struct 
    {
        GPIO_Type *gpio;
        //PORT_Type* port;
        uint32_t pin;
        port_interrupt_t intCfg;
        uint64_t msCnt;
        button_status_t status;
        button_handler_t handler;
    }button_t;

    
    
    //#ifdef CPU_MK66FX1M0VLQ18
    PORT_Type *BUTTON_GetPortInst(GPIO_Type *gpio);

    //#endif // ! CPU_MK66FX1M0VLQ18

    void BUTTON_Setup(button_t* _inst, GPIO_Type *_gpio, uint32_t _pin);

    button_t *BUTTON_Construct(GPIO_Type *_gpio, uint32_t _pin);

    void BUTTON_InstallHandler(button_t* _inst, button_handler_t _handler);

    void BUTTON_UninstallHandler(button_t* _inst);

    void BUTTON_SetInterrupt(button_t *_inst, port_interrupt_t _int);

    uint32_t BUTTON_ReadPin(button_t *_inst);

    void BUTTON_ExtIsr(button_t *_inst);

    void BUTTON_PitIsr(button_t *_inst);




#ifdef __cplusplus
}
#endif


#endif // ! _DRV_BUTTON_H_