#include "openmv.h"
#include "ti_msp_dl_config.h"

uint8_t RxBuffer[11] = {0};
double angle[3] = {0};
double acc[3] = {0};
double angleSpeed[3] = {0};
uint32_t count1 = 0;
void UART_ANGLE_INST_IRQHandler()
{
                //濡傛灉浜х敓浜嗕覆鍙ｄ腑鏂�
    switch( DL_UART_getPendingInterrupt(UART_ANGLE_INST))
    {
        case DL_UART_IIDX_RX://濡傛灉鏄帴鏀朵腑鏂�
        {
            RxBuffer[count1++] = DL_UART_Main_receiveData(UART_ANGLE_INST);
            if(RxBuffer[0] != 0x55)
            {
                count1 = 0;
            }
            else if(RxBuffer[0] == 0x55)
            {
                switch(RxBuffer[1])
                {
                    case 0x51:
                    {
                        acc[0] = ((short)(RxBuffer[3]<<8|RxBuffer[2]))/32768.0*16*9.8;
                        acc[1] = ((short)(RxBuffer[5]<<8|RxBuffer[4]))/32768.0*16*9.8;
                        acc[2] = ((short)(RxBuffer[7]<<8|RxBuffer[6]))/32768.0*16*9.8;
                        break;
                    }
                    case 0x52:
                    {
                        angleSpeed[0] = ((short)(RxBuffer[3]<<8|RxBuffer[2]))/32768.0*2000;
                        angleSpeed[1] = ((short)(RxBuffer[5]<<8|RxBuffer[4]))/32768.0*2000;
                        angleSpeed[2] = ((short)(RxBuffer[7]<<8|RxBuffer[6]))/32768.0*2000;
                        break;
                    }
                    case 0x53:
                    {
                        angle[0] = ((short)(RxBuffer[3]<<8|RxBuffer[2]))/32768.0*180;
                        angle[1] = ((short)(RxBuffer[5]<<8|RxBuffer[4]))/32768.0*180;
                        angle[2] = ((short)(RxBuffer[7]<<8|RxBuffer[6]))/32768.0*180;
                        break;
                    }
                    default:
                        break;
                }
            }

            if(count1>=11)
            {
                count1 = 0;
            }

            break;
        }
        default:
            break;
    }
    DL_UART_clearInterruptStatus(UART_ANGLE_INST,DL_UART_INTERRUPT_RX);
}
