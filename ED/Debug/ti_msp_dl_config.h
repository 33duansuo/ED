/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for MOTOR_L */
#define MOTOR_L_INST                                                       TIMA0
#define MOTOR_L_INST_IRQHandler                                 TIMA0_IRQHandler
#define MOTOR_L_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define MOTOR_L_INST_CLK_FREQ                                            1000000
/* GPIO defines for channel 0 */
#define GPIO_MOTOR_L_C0_PORT                                               GPIOB
#define GPIO_MOTOR_L_C0_PIN                                        DL_GPIO_PIN_8
#define GPIO_MOTOR_L_C0_IOMUX                                    (IOMUX_PINCM25)
#define GPIO_MOTOR_L_C0_IOMUX_FUNC                   IOMUX_PINCM25_PF_TIMA0_CCP0
#define GPIO_MOTOR_L_C0_IDX                                  DL_TIMER_CC_0_INDEX

/* Defines for MOTOR_R */
#define MOTOR_R_INST                                                       TIMA1
#define MOTOR_R_INST_IRQHandler                                 TIMA1_IRQHandler
#define MOTOR_R_INST_INT_IRQN                                   (TIMA1_INT_IRQn)
#define MOTOR_R_INST_CLK_FREQ                                            1000000
/* GPIO defines for channel 0 */
#define GPIO_MOTOR_R_C0_PORT                                               GPIOB
#define GPIO_MOTOR_R_C0_PIN                                        DL_GPIO_PIN_2
#define GPIO_MOTOR_R_C0_IOMUX                                    (IOMUX_PINCM15)
#define GPIO_MOTOR_R_C0_IOMUX_FUNC                   IOMUX_PINCM15_PF_TIMA1_CCP0
#define GPIO_MOTOR_R_C0_IDX                                  DL_TIMER_CC_0_INDEX



/* Defines for TIMER_Sonic */
#define TIMER_Sonic_INST                                                 (TIMG0)
#define TIMER_Sonic_INST_IRQHandler                             TIMG0_IRQHandler
#define TIMER_Sonic_INST_INT_IRQN                               (TIMG0_INT_IRQn)
#define TIMER_Sonic_INST_LOAD_VALUE                                     (64999U)
/* Defines for TIMER_Encoder */
#define TIMER_Encoder_INST                                               (TIMG6)
#define TIMER_Encoder_INST_IRQHandler                           TIMG6_IRQHandler
#define TIMER_Encoder_INST_INT_IRQN                             (TIMG6_INT_IRQn)
#define TIMER_Encoder_INST_LOAD_VALUE                                   (39999U)
/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG8)
#define TIMER_0_INST_IRQHandler                                 TIMG8_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG8_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (15624U)



/* Defines for UART_BT */
#define UART_BT_INST                                                       UART0
#define UART_BT_INST_IRQHandler                                 UART0_IRQHandler
#define UART_BT_INST_INT_IRQN                                     UART0_INT_IRQn
#define GPIO_UART_BT_RX_PORT                                               GPIOA
#define GPIO_UART_BT_TX_PORT                                               GPIOB
#define GPIO_UART_BT_RX_PIN                                       DL_GPIO_PIN_11
#define GPIO_UART_BT_TX_PIN                                        DL_GPIO_PIN_0
#define GPIO_UART_BT_IOMUX_RX                                    (IOMUX_PINCM22)
#define GPIO_UART_BT_IOMUX_TX                                    (IOMUX_PINCM12)
#define GPIO_UART_BT_IOMUX_RX_FUNC                     IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_BT_IOMUX_TX_FUNC                     IOMUX_PINCM12_PF_UART0_TX
#define UART_BT_BAUD_RATE                                               (115200)
#define UART_BT_IBRD_4_MHZ_115200_BAUD                                       (2)
#define UART_BT_FBRD_4_MHZ_115200_BAUD                                      (11)
/* Defines for UART_ANGLE */
#define UART_ANGLE_INST                                                    UART1
#define UART_ANGLE_INST_IRQHandler                              UART1_IRQHandler
#define UART_ANGLE_INST_INT_IRQN                                  UART1_INT_IRQn
#define GPIO_UART_ANGLE_RX_PORT                                            GPIOB
#define GPIO_UART_ANGLE_TX_PORT                                            GPIOA
#define GPIO_UART_ANGLE_RX_PIN                                     DL_GPIO_PIN_5
#define GPIO_UART_ANGLE_TX_PIN                                    DL_GPIO_PIN_17
#define GPIO_UART_ANGLE_IOMUX_RX                                 (IOMUX_PINCM18)
#define GPIO_UART_ANGLE_IOMUX_TX                                 (IOMUX_PINCM39)
#define GPIO_UART_ANGLE_IOMUX_RX_FUNC                  IOMUX_PINCM18_PF_UART1_RX
#define GPIO_UART_ANGLE_IOMUX_TX_FUNC                  IOMUX_PINCM39_PF_UART1_TX
#define UART_ANGLE_BAUD_RATE                                              (9600)
#define UART_ANGLE_IBRD_4_MHZ_9600_BAUD                                     (26)
#define UART_ANGLE_FBRD_4_MHZ_9600_BAUD                                      (3)
/* Defines for UART_SCREEN */
#define UART_SCREEN_INST                                                   UART2
#define UART_SCREEN_INST_IRQHandler                             UART2_IRQHandler
#define UART_SCREEN_INST_INT_IRQN                                 UART2_INT_IRQn
#define GPIO_UART_SCREEN_RX_PORT                                           GPIOB
#define GPIO_UART_SCREEN_TX_PORT                                           GPIOB
#define GPIO_UART_SCREEN_RX_PIN                                   DL_GPIO_PIN_16
#define GPIO_UART_SCREEN_TX_PIN                                   DL_GPIO_PIN_15
#define GPIO_UART_SCREEN_IOMUX_RX                                (IOMUX_PINCM33)
#define GPIO_UART_SCREEN_IOMUX_TX                                (IOMUX_PINCM32)
#define GPIO_UART_SCREEN_IOMUX_RX_FUNC                 IOMUX_PINCM33_PF_UART2_RX
#define GPIO_UART_SCREEN_IOMUX_TX_FUNC                 IOMUX_PINCM32_PF_UART2_TX
#define UART_SCREEN_BAUD_RATE                                             (9600)
#define UART_SCREEN_IBRD_32_MHZ_9600_BAUD                                  (208)
#define UART_SCREEN_FBRD_32_MHZ_9600_BAUD                                   (21)





/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOB)

/* Defines for PIN_LED: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_LED_PIN_LED_PIN                                    (DL_GPIO_PIN_22)
#define GPIO_LED_PIN_LED_IOMUX                                   (IOMUX_PINCM50)
/* Port definition for Pin Group GPIO_BUZZER */
#define GPIO_BUZZER_PORT                                                 (GPIOB)

/* Defines for PIN_BUZZER: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_BUZZER_PIN_BUZZER_PIN                               (DL_GPIO_PIN_1)
#define GPIO_BUZZER_PIN_BUZZER_IOMUX                             (IOMUX_PINCM13)
/* Port definition for Pin Group GPIO_SONIC */
#define GPIO_SONIC_PORT                                                  (GPIOB)

/* Defines for PIN_TX: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_SONIC_PIN_TX_PIN                                   (DL_GPIO_PIN_13)
#define GPIO_SONIC_PIN_TX_IOMUX                                  (IOMUX_PINCM30)
/* Defines for PIN_RX: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_SONIC_PIN_RX_PIN                                    (DL_GPIO_PIN_7)
#define GPIO_SONIC_PIN_RX_IOMUX                                  (IOMUX_PINCM24)
/* Defines for PIN_0: GPIOB.3 with pinCMx 16 on package pin 51 */
#define GPIO_SONIC_PIN_0_PIN                                     (DL_GPIO_PIN_3)
#define GPIO_SONIC_PIN_0_IOMUX                                   (IOMUX_PINCM16)
/* Port definition for Pin Group GPIO_CTRL */
#define GPIO_CTRL_PORT                                                   (GPIOA)

/* Defines for PIN_CTRL_L: GPIOA.8 with pinCMx 19 on package pin 54 */
#define GPIO_CTRL_PIN_CTRL_L_PIN                                 (DL_GPIO_PIN_8)
#define GPIO_CTRL_PIN_CTRL_L_IOMUX                               (IOMUX_PINCM19)
/* Defines for PIN_CTRL_R: GPIOA.18 with pinCMx 40 on package pin 11 */
#define GPIO_CTRL_PIN_CTRL_R_PIN                                (DL_GPIO_PIN_18)
#define GPIO_CTRL_PIN_CTRL_R_IOMUX                               (IOMUX_PINCM40)
/* Port definition for Pin Group GPIO_TRACE */
#define GPIO_TRACE_PORT                                                  (GPIOA)

/* Defines for PIN_L: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_TRACE_PIN_L_PIN                                    (DL_GPIO_PIN_12)
#define GPIO_TRACE_PIN_L_IOMUX                                   (IOMUX_PINCM34)
/* Defines for PIN_ML: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_TRACE_PIN_ML_PIN                                   (DL_GPIO_PIN_13)
#define GPIO_TRACE_PIN_ML_IOMUX                                  (IOMUX_PINCM35)
/* Defines for PIN_M: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_TRACE_PIN_M_PIN                                    (DL_GPIO_PIN_25)
#define GPIO_TRACE_PIN_M_IOMUX                                   (IOMUX_PINCM55)
/* Defines for PIN_MR: GPIOA.27 with pinCMx 60 on package pin 31 */
#define GPIO_TRACE_PIN_MR_PIN                                   (DL_GPIO_PIN_27)
#define GPIO_TRACE_PIN_MR_IOMUX                                  (IOMUX_PINCM60)
/* Defines for PIN_R: GPIOA.31 with pinCMx 6 on package pin 39 */
#define GPIO_TRACE_PIN_R_PIN                                    (DL_GPIO_PIN_31)
#define GPIO_TRACE_PIN_R_IOMUX                                    (IOMUX_PINCM6)
/* Port definition for Pin Group GPIO_KEYBOARD */
#define GPIO_KEYBOARD_PORT                                               (GPIOB)

/* Defines for PIN_ROW_0: GPIOB.4 with pinCMx 17 on package pin 52 */
#define GPIO_KEYBOARD_PIN_ROW_0_PIN                              (DL_GPIO_PIN_4)
#define GPIO_KEYBOARD_PIN_ROW_0_IOMUX                            (IOMUX_PINCM17)
/* Defines for PIN_ROW_1: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_KEYBOARD_PIN_ROW_1_PIN                              (DL_GPIO_PIN_6)
#define GPIO_KEYBOARD_PIN_ROW_1_IOMUX                            (IOMUX_PINCM23)
/* Defines for PIN_COL_0: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_KEYBOARD_PIN_COL_0_PIN                              (DL_GPIO_PIN_9)
#define GPIO_KEYBOARD_PIN_COL_0_IOMUX                            (IOMUX_PINCM26)
/* Defines for PIN_COL_1: GPIOB.10 with pinCMx 27 on package pin 62 */
#define GPIO_KEYBOARD_PIN_COL_1_PIN                             (DL_GPIO_PIN_10)
#define GPIO_KEYBOARD_PIN_COL_1_IOMUX                            (IOMUX_PINCM27)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_MOTOR_L_init(void);
void SYSCFG_DL_MOTOR_R_init(void);
void SYSCFG_DL_TIMER_Sonic_init(void);
void SYSCFG_DL_TIMER_Encoder_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_BT_init(void);
void SYSCFG_DL_UART_ANGLE_init(void);
void SYSCFG_DL_UART_SCREEN_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
