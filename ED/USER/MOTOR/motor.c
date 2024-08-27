#include "motor.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_timer.h"
#include "ti/driverlib/dl_timera.h"
#include "ti_msp_dl_config.h"



void GO(int f1, int f2)
{
    if(f1>100&&f2>100)
    {    

        DL_TimerA_setLoadValue(MOTOR_R_INST,f2);
        DL_TimerA_setLoadValue(MOTOR_L_INST,f1);
        DL_TimerA_setCaptureCompareValue(MOTOR_L_INST,f1/2,DL_TIMER_CC_0_INDEX);
        DL_TimerA_setCaptureCompareValue(MOTOR_R_INST,f2/2,DL_TIMER_CC_0_INDEX);
        
        DL_GPIO_setPins(GPIO_CTRL_PORT, GPIO_CTRL_PIN_CTRL_L_PIN);
        DL_GPIO_clearPins(GPIO_CTRL_PORT, GPIO_CTRL_PIN_CTRL_R_PIN);

    }
     
}

void Around(int f)
{
    if(f>100)
    {
        DL_TimerA_setLoadValue(MOTOR_R_INST,f);
        DL_TimerA_setLoadValue(MOTOR_R_INST,f);
    }
    DL_GPIO_setPins(GPIO_CTRL_PORT, GPIO_CTRL_PIN_CTRL_L_PIN);
    DL_GPIO_setPins(GPIO_CTRL_PORT, GPIO_CTRL_PIN_CTRL_R_PIN);
} 

void Stop()
{
    DL_TimerA_setCaptureCompareValue(MOTOR_L_INST,0,DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareValue(MOTOR_R_INST,0,DL_TIMER_CC_0_INDEX);    

}


