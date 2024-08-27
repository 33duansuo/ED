/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gMOTOR_LBackup;
DL_TimerA_backupConfig gMOTOR_RBackup;
DL_TimerG_backupConfig gTIMER_EncoderBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_MOTOR_L_init();
    SYSCFG_DL_MOTOR_R_init();
    SYSCFG_DL_TIMER_Sonic_init();
    SYSCFG_DL_TIMER_Encoder_init();
    SYSCFG_DL_TIMER_0_init();
    SYSCFG_DL_UART_BT_init();
    SYSCFG_DL_UART_ANGLE_init();
    SYSCFG_DL_UART_SCREEN_init();
    /* Ensure backup structures have no valid state */
	gMOTOR_LBackup.backupRdy 	= false;
	gMOTOR_RBackup.backupRdy 	= false;
	gTIMER_EncoderBackup.backupRdy 	= false;


}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(MOTOR_L_INST, &gMOTOR_LBackup);
	retStatus &= DL_TimerA_saveConfiguration(MOTOR_R_INST, &gMOTOR_RBackup);
	retStatus &= DL_TimerG_saveConfiguration(TIMER_Encoder_INST, &gTIMER_EncoderBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(MOTOR_L_INST, &gMOTOR_LBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(MOTOR_R_INST, &gMOTOR_RBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(TIMER_Encoder_INST, &gTIMER_EncoderBackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(MOTOR_L_INST);
    DL_TimerA_reset(MOTOR_R_INST);
    DL_TimerG_reset(TIMER_Sonic_INST);
    DL_TimerG_reset(TIMER_Encoder_INST);
    DL_TimerG_reset(TIMER_0_INST);
    DL_UART_Main_reset(UART_BT_INST);
    DL_UART_Main_reset(UART_ANGLE_INST);
    DL_UART_Main_reset(UART_SCREEN_INST);

    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(MOTOR_L_INST);
    DL_TimerA_enablePower(MOTOR_R_INST);
    DL_TimerG_enablePower(TIMER_Sonic_INST);
    DL_TimerG_enablePower(TIMER_Encoder_INST);
    DL_TimerG_enablePower(TIMER_0_INST);
    DL_UART_Main_enablePower(UART_BT_INST);
    DL_UART_Main_enablePower(UART_ANGLE_INST);
    DL_UART_Main_enablePower(UART_SCREEN_INST);
    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{
    const uint8_t unusedPinIndexes[] =
    {
        IOMUX_PINCM31, IOMUX_PINCM36, IOMUX_PINCM37, IOMUX_PINCM38,
        IOMUX_PINCM43, IOMUX_PINCM44, IOMUX_PINCM45, IOMUX_PINCM46,
        IOMUX_PINCM47, IOMUX_PINCM48, IOMUX_PINCM49, IOMUX_PINCM51,
        IOMUX_PINCM52, IOMUX_PINCM53, IOMUX_PINCM54, IOMUX_PINCM56,
        IOMUX_PINCM57, IOMUX_PINCM58, IOMUX_PINCM59, IOMUX_PINCM1,
        IOMUX_PINCM2, IOMUX_PINCM3, IOMUX_PINCM4, IOMUX_PINCM5,
        IOMUX_PINCM7, IOMUX_PINCM8, IOMUX_PINCM9, IOMUX_PINCM10,
        IOMUX_PINCM11, IOMUX_PINCM14, IOMUX_PINCM20, IOMUX_PINCM21,
        IOMUX_PINCM28, IOMUX_PINCM29
    };

    for(int i = 0; i < sizeof(unusedPinIndexes)/sizeof(unusedPinIndexes[0]); i++)
    {
        DL_GPIO_initDigitalOutput(unusedPinIndexes[i]);
    }

    DL_GPIO_clearPins(GPIOA,
        (DL_GPIO_PIN_14 | DL_GPIO_PIN_15 | DL_GPIO_PIN_16 | DL_GPIO_PIN_21 |
        DL_GPIO_PIN_22 | DL_GPIO_PIN_23 | DL_GPIO_PIN_24 | DL_GPIO_PIN_26 |
        DL_GPIO_PIN_0 | DL_GPIO_PIN_1 | DL_GPIO_PIN_28 | DL_GPIO_PIN_29 |
        DL_GPIO_PIN_30 | DL_GPIO_PIN_2 | DL_GPIO_PIN_3 | DL_GPIO_PIN_4 |
        DL_GPIO_PIN_5 | DL_GPIO_PIN_6 | DL_GPIO_PIN_7 | DL_GPIO_PIN_9 |
        DL_GPIO_PIN_10));
    DL_GPIO_enableOutput(GPIOA,
        (DL_GPIO_PIN_14 | DL_GPIO_PIN_15 | DL_GPIO_PIN_16 | DL_GPIO_PIN_21 |
        DL_GPIO_PIN_22 | DL_GPIO_PIN_23 | DL_GPIO_PIN_24 | DL_GPIO_PIN_26 |
        DL_GPIO_PIN_0 | DL_GPIO_PIN_1 | DL_GPIO_PIN_28 | DL_GPIO_PIN_29 |
        DL_GPIO_PIN_30 | DL_GPIO_PIN_2 | DL_GPIO_PIN_3 | DL_GPIO_PIN_4 |
        DL_GPIO_PIN_5 | DL_GPIO_PIN_6 | DL_GPIO_PIN_7 | DL_GPIO_PIN_9 |
        DL_GPIO_PIN_10));
    DL_GPIO_clearPins(GPIOB,
        (DL_GPIO_PIN_14 | DL_GPIO_PIN_17 | DL_GPIO_PIN_18 | DL_GPIO_PIN_19 |
        DL_GPIO_PIN_20 | DL_GPIO_PIN_21 | DL_GPIO_PIN_23 | DL_GPIO_PIN_24 |
        DL_GPIO_PIN_25 | DL_GPIO_PIN_26 | DL_GPIO_PIN_27 | DL_GPIO_PIN_11 |
        DL_GPIO_PIN_12));
    DL_GPIO_enableOutput(GPIOB,
        (DL_GPIO_PIN_14 | DL_GPIO_PIN_17 | DL_GPIO_PIN_18 | DL_GPIO_PIN_19 |
        DL_GPIO_PIN_20 | DL_GPIO_PIN_21 | DL_GPIO_PIN_23 | DL_GPIO_PIN_24 |
        DL_GPIO_PIN_25 | DL_GPIO_PIN_26 | DL_GPIO_PIN_27 | DL_GPIO_PIN_11 |
        DL_GPIO_PIN_12));

    DL_GPIO_initPeripheralOutputFunction(GPIO_MOTOR_L_C0_IOMUX,GPIO_MOTOR_L_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_MOTOR_L_C0_PORT, GPIO_MOTOR_L_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_MOTOR_R_C0_IOMUX,GPIO_MOTOR_R_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_MOTOR_R_C0_PORT, GPIO_MOTOR_R_C0_PIN);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_BT_IOMUX_TX, GPIO_UART_BT_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_BT_IOMUX_RX, GPIO_UART_BT_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_ANGLE_IOMUX_TX, GPIO_UART_ANGLE_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_ANGLE_IOMUX_RX, GPIO_UART_ANGLE_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_SCREEN_IOMUX_TX, GPIO_UART_SCREEN_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_SCREEN_IOMUX_RX, GPIO_UART_SCREEN_IOMUX_RX_FUNC);

    DL_GPIO_initDigitalOutput(GPIO_LED_PIN_LED_IOMUX);

    DL_GPIO_initDigitalOutputFeatures(GPIO_BUZZER_PIN_BUZZER_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalOutput(GPIO_SONIC_PIN_TX_IOMUX);

    DL_GPIO_initDigitalInputFeatures(GPIO_SONIC_PIN_RX_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInput(GPIO_SONIC_PIN_0_IOMUX);

    DL_GPIO_initDigitalOutputFeatures(GPIO_CTRL_PIN_CTRL_L_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalOutputFeatures(GPIO_CTRL_PIN_CTRL_R_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_TRACE_PIN_L_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_TRACE_PIN_ML_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_TRACE_PIN_M_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_TRACE_PIN_MR_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_TRACE_PIN_R_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_KEYBOARD_PIN_ROW_0_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_KEYBOARD_PIN_ROW_1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutputFeatures(GPIO_KEYBOARD_PIN_COL_0_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalOutputFeatures(GPIO_KEYBOARD_PIN_COL_1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_clearPins(GPIOA, GPIO_CTRL_PIN_CTRL_L_PIN |
		GPIO_CTRL_PIN_CTRL_R_PIN);
    DL_GPIO_enableOutput(GPIOA, GPIO_CTRL_PIN_CTRL_L_PIN |
		GPIO_CTRL_PIN_CTRL_R_PIN);
    DL_GPIO_clearPins(GPIOB, GPIO_LED_PIN_LED_PIN |
		GPIO_BUZZER_PIN_BUZZER_PIN |
		GPIO_SONIC_PIN_TX_PIN |
		GPIO_KEYBOARD_PIN_COL_0_PIN |
		GPIO_KEYBOARD_PIN_COL_1_PIN);
    DL_GPIO_enableOutput(GPIOB, GPIO_LED_PIN_LED_PIN |
		GPIO_BUZZER_PIN_BUZZER_PIN |
		GPIO_SONIC_PIN_TX_PIN |
		GPIO_KEYBOARD_PIN_COL_0_PIN |
		GPIO_KEYBOARD_PIN_COL_1_PIN);

}



SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_enableMFCLK();

}


/*
 * Timer clock configuration to be sourced by  / 2 (16000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 16000000 Hz / (2 * (15 + 1))
 */
static const DL_TimerA_ClockConfig gMOTOR_LClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_2,
    .prescale = 15U
};

static const DL_TimerA_PWMConfig gMOTOR_LConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 500,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_MOTOR_L_init(void) {

    DL_TimerA_setClockConfig(
        MOTOR_L_INST, (DL_TimerA_ClockConfig *) &gMOTOR_LClockConfig);

    DL_TimerA_initPWMMode(
        MOTOR_L_INST, (DL_TimerA_PWMConfig *) &gMOTOR_LConfig);

    DL_TimerA_setCaptureCompareValue(MOTOR_L_INST, 250, DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareOutCtl(MOTOR_L_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(MOTOR_L_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_enableClock(MOTOR_L_INST);


    
    DL_TimerA_setCCPDirection(MOTOR_L_INST , DL_TIMER_CC0_OUTPUT );

}
/*
 * Timer clock configuration to be sourced by  / 2 (16000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 16000000 Hz / (2 * (15 + 1))
 */
static const DL_TimerA_ClockConfig gMOTOR_RClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_2,
    .prescale = 15U
};

static const DL_TimerA_PWMConfig gMOTOR_RConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 500,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_MOTOR_R_init(void) {

    DL_TimerA_setClockConfig(
        MOTOR_R_INST, (DL_TimerA_ClockConfig *) &gMOTOR_RClockConfig);

    DL_TimerA_initPWMMode(
        MOTOR_R_INST, (DL_TimerA_PWMConfig *) &gMOTOR_RConfig);

    DL_TimerA_setCaptureCompareValue(MOTOR_R_INST, 250, DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareOutCtl(MOTOR_R_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(MOTOR_R_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_enableClock(MOTOR_R_INST);


    
    DL_TimerA_setCCPDirection(MOTOR_R_INST , DL_TIMER_CC0_OUTPUT );

}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 32000000 Hz / (1 * (31 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_SonicClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 31U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_Sonic_INST_LOAD_VALUE = (65 ms * 1000000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_SonicTimerConfig = {
    .period     = TIMER_Sonic_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_ONE_SHOT_UP,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_Sonic_init(void) {

    DL_TimerG_setClockConfig(TIMER_Sonic_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_SonicClockConfig);

    DL_TimerG_initTimerMode(TIMER_Sonic_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_SonicTimerConfig);
    DL_TimerG_enableInterrupt(TIMER_Sonic_INST , DL_TIMERG_INTERRUPT_LOAD_EVENT);
	NVIC_SetPriority(TIMER_Sonic_INST_INT_IRQN, 1);
    DL_TimerG_enableClock(TIMER_Sonic_INST);




}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   4000000 Hz = 4000000 Hz / (8 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_EncoderClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 0U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_Encoder_INST_LOAD_VALUE = (10 ms * 4000000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_EncoderTimerConfig = {
    .period     = TIMER_Encoder_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_Encoder_init(void) {

    DL_TimerG_setClockConfig(TIMER_Encoder_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_EncoderClockConfig);

    DL_TimerG_initTimerMode(TIMER_Encoder_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_EncoderTimerConfig);
    DL_TimerG_enableClock(TIMER_Encoder_INST);




}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   15625 Hz = 4000000 Hz / (8 * (255 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_0ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 255U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_0_INST_LOAD_VALUE = (1 * 15625 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_0TimerConfig = {
    .period     = TIMER_0_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_0_init(void) {

    DL_TimerG_setClockConfig(TIMER_0_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_0ClockConfig);

    DL_TimerG_initTimerMode(TIMER_0_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_0TimerConfig);
    DL_TimerG_enableInterrupt(TIMER_0_INST , DL_TIMERG_INTERRUPT_LOAD_EVENT);
	NVIC_SetPriority(TIMER_0_INST_INT_IRQN, 1);
    DL_TimerG_enableClock(TIMER_0_INST);




}



static const DL_UART_Main_ClockConfig gUART_BTClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_MFCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_BTConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_BT_init(void)
{
    DL_UART_Main_setClockConfig(UART_BT_INST, (DL_UART_Main_ClockConfig *) &gUART_BTClockConfig);

    DL_UART_Main_init(UART_BT_INST, (DL_UART_Main_Config *) &gUART_BTConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115107.91
     */
    DL_UART_Main_setOversampling(UART_BT_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_BT_INST, UART_BT_IBRD_4_MHZ_115200_BAUD, UART_BT_FBRD_4_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_BT_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(UART_BT_INST_INT_IRQN, 0);


    DL_UART_Main_enable(UART_BT_INST);
}

static const DL_UART_Main_ClockConfig gUART_ANGLEClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_MFCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_ANGLEConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_ANGLE_init(void)
{
    DL_UART_Main_setClockConfig(UART_ANGLE_INST, (DL_UART_Main_ClockConfig *) &gUART_ANGLEClockConfig);

    DL_UART_Main_init(UART_ANGLE_INST, (DL_UART_Main_Config *) &gUART_ANGLEConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 9600
     *  Actual baud rate: 9598.08
     */
    DL_UART_Main_setOversampling(UART_ANGLE_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_ANGLE_INST, UART_ANGLE_IBRD_4_MHZ_9600_BAUD, UART_ANGLE_FBRD_4_MHZ_9600_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_ANGLE_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(UART_ANGLE_INST_INT_IRQN, 0);


    DL_UART_Main_enable(UART_ANGLE_INST);
}

static const DL_UART_Main_ClockConfig gUART_SCREENClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_SCREENConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_SCREEN_init(void)
{
    DL_UART_Main_setClockConfig(UART_SCREEN_INST, (DL_UART_Main_ClockConfig *) &gUART_SCREENClockConfig);

    DL_UART_Main_init(UART_SCREEN_INST, (DL_UART_Main_Config *) &gUART_SCREENConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 9600
     *  Actual baud rate: 9600.24
     */
    DL_UART_Main_setOversampling(UART_SCREEN_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_SCREEN_INST, UART_SCREEN_IBRD_32_MHZ_9600_BAUD, UART_SCREEN_FBRD_32_MHZ_9600_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_SCREEN_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(UART_SCREEN_INST_INT_IRQN, 0);


    DL_UART_Main_enable(UART_SCREEN_INST);
}

