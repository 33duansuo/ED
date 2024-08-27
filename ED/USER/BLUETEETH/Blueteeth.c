#include "Blueteeth.h"

void BT_Trnasmit(uint8_t data)
{
    for(int i =0;i<5;i++)
    {
        DL_UART_Main_transmitData(UART_BT_INST,0x0a);
        delay_cycles(3200);

        DL_UART_Main_transmitData(UART_BT_INST,data);
        delay_cycles(3200);

        DL_UART_Main_transmitData(UART_BT_INST,0x0d);
        delay_cycles(3200);
    }
}