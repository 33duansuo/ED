#include "keyboard.h"
#include "stdint.h"
#include "delay.h"
uint32_t row,col;

void KeyInit()
{
    DL_GPIO_setPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_0_PIN);
    DL_GPIO_setPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_1_PIN);
}
uint32_t getKey()
{
    uint32_t  NewKeyValue = 0;
    Delay_ms(10);
    col = 0;
    row = 0;
    for(;col<2;col++)
    {
        if(col == 0)
        {
            DL_GPIO_clearPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_0_PIN);
            DL_GPIO_setPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_1_PIN);
        }
        if(col == 1)
        {
            DL_GPIO_clearPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_1_PIN);
            DL_GPIO_setPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_0_PIN);
        }

        if(!DL_GPIO_readPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_ROW_0_PIN)||
        !DL_GPIO_readPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_ROW_1_PIN))
        {
            Delay_ms(1);
        }

        if(!DL_GPIO_readPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_ROW_0_PIN)||
        !DL_GPIO_readPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_ROW_1_PIN))
        {
            if(!DL_GPIO_readPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_ROW_0_PIN))
            {
                row = 0;
                NewKeyValue = row*2 + col + 1;
                break;
            }
            if (!DL_GPIO_readPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_ROW_1_PIN)) 
            {
                row = 1;
                NewKeyValue = row*2 + col + 1;
                break;
            }
        }
    }
    DL_GPIO_setPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_0_PIN);
    DL_GPIO_setPins(GPIO_KEYBOARD_PORT, GPIO_KEYBOARD_PIN_COL_1_PIN);
    return NewKeyValue;
}