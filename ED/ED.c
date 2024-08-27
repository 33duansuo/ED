/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti/devices/msp/m0p/mspm0g350x.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_timera.h"
#include "ti/driverlib/dl_uart_main.h"
#include "ti_msp_dl_config.h"
#include "delay.h"
#include "motor.h"
#include "pid.h"
#include "openmv.h"
#include "print.h"
#include "keyboard.h"
#include "Blueteeth.h"
#include "sonic.h"
#include "stdio.h"
#include "stdint.h"
#define mid_p 90
#define P1 (DL_GPIO_readPins(GPIO_TRACE_PORT,GPIO_TRACE_PIN_L_PIN))
#define P2 (DL_GPIO_readPins(GPIO_TRACE_PORT,GPIO_TRACE_PIN_ML_PIN))
#define P3 (DL_GPIO_readPins(GPIO_TRACE_PORT,GPIO_TRACE_PIN_M_PIN))
#define P4 (DL_GPIO_readPins(GPIO_TRACE_PORT,GPIO_TRACE_PIN_MR_PIN))
#define P5 (DL_GPIO_readPins(GPIO_TRACE_PORT,GPIO_TRACE_PIN_R_PIN))

volatile uint8_t KeyValue = 0;
uint32_t count2 = 0;
uint32_t count3 = 0;
uint32_t F_time = 0;
uint32_t K = 5;
uint32_t error = 0;
uint32_t dist = 0;
pid_t encoder_lb;
pid_t encoder_rb;
uint8_t Receive[3] = {0};
uint8_t BT_Buffer[3] = {0};
uint8_t BT = 0;
//Variables
void ResetPWM();
void test1();
void test2();
void test3();
void LEDOn();
void LEDOff();
void BuzzerOn();
void BuzzerOff();
//Functions
int main(void)
{
    SYSCFG_DL_init();
    NVIC_ClearPendingIRQ(UART_BT_INST_INT_IRQN);
    NVIC_ClearPendingIRQ(UART_JY61P_INST_INT_IRQN);
    NVIC_ClearPendingIRQ(UART_SCREEN_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_BT_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_JY61P_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_SCREEN_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_Sonic_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    DL_TimerA_startCounter(MOTOR_L_INST);
    DL_TimerA_startCounter(MOTOR_R_INST);
    KeyInit();
    PidInit(&encoder_lb, 5, 0.5, 1.5, 100, 500);
    PidInit(&encoder_rb, 5, 0.5, 1.5, 100, 500);
    while (1) 
    {
        
        // switch(KeyValue)
        // {
        //     case 1:
        //     {
        //         Forward(F, F);
        //         break;
        //     }
        //     case 2:
        //     {
        //         TurnLeft(MIN, MAX);
        //         break;
        //     }
        //     case 3:
        //     {
        //         TurnRight(MIN, MAX);
        //         break;
        //     }
        //     case 4:
        //     {
        //         break;
        //     }
        //     default:
        //         break;     
        // }
        // test3();
        // F_time = 0;


        // if(!P3)
        //     Forward(F, F);
        // if(!P2) 
        //     TurnLeft(MIN, MID);
        // if(!P4)
        //     TurnRight(MIN, MID);
        // if(!P1)
        //     TurnLeft(MIN, MAX);
        // if(!P5)
        //     TurnRight(MIN, MAX);

        printf("Angle:%.3f %.3f %.3f\r\n",angle[0],angle[1],angle[2]);
        printf("Anglespeed:%.3f %.3f %.3f\r\n",angleSpeed[0],angleSpeed[1],angleSpeed[2]);
        Delay_ms(1);

    }

}

void UART_SCREEN_INST_IRQHandler()
{
    switch(DL_UART_getPendingInterrupt(UART_SCREEN_INST))
    {
        case DL_UART_IIDX_RX:
        {
            Receive[count3++] = DL_UART_Main_receiveData(UART_SCREEN_INST);
            if(Receive[0] != 0x0a)
            {
                count3 = 0;
            }
            else if(Receive[0]==0x0a&&Receive[count3-1]==0x0d)
            {
                KeyValue = Receive[1] - '0';
                count3 = 0;
            }
            if(count3>=3)
            {
                count3 = 0;
            }
            break;
        }
        default:
            break;
    }    
    DL_UART_clearInterruptStatus(UART_SCREEN_INST,DL_UART_INTERRUPT_RX);
}

void UART_BT_INST_IRQHandler()
{
    switch(DL_UART_getPendingInterrupt(UART_BT_INST))
    {
        case DL_UART_IIDX_RX:
        {
            BT_Buffer[count2++] = DL_UART_Main_receiveData(UART_BT_INST);
            if(BT_Buffer[0] != 0x0a)
            {
                count2 = 0;
            }
            else if(BT_Buffer[0]==0x0a&&BT_Buffer[count2-1]==0x0d)
            {
                BT = BT_Buffer[1];
                count2 = 0;
            }
            if(count2>=3)
            {
                count2 = 0;
            }
            break;
        }
        default:
            break;
    }    
    DL_UART_clearInterruptStatus(UART_BT_INST,DL_UART_INTERRUPT_RX);
}



void LEDOn()
{
    DL_GPIO_setPins(GPIO_LED_PORT,GPIO_LED_PIN_LED_PIN);
}

void LEDOff()
{
    DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_PIN);
}

void BuzzerOn()
{
    DL_GPIO_clearPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_BUZZER_PIN);
}

void BuzzerOff()
{
    DL_GPIO_setPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_BUZZER_PIN);    
}

void test1()
{

}

void test2()
{

}

void test3()
{

}

void TIMER_0_INST_IRQHandler()
{
    F_time++;    
}
