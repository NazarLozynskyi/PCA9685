#include "my_main.h"
#include "uart.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "i3_i2c_ext.h"
#include "stm32f3xx_hal.h"
#include "pca9685.h"

extern I2C_HandleTypeDef hi2c2;
 size_t i = 0;

void my_main_loop(void)
{
    //char buff[50]={0};
    
    pca_init(0x40, 1000);
    set_PWM (0x40, 1,0, 0);
   
    while(1)
    {
        
        for(; i < 4096; i+=20)
        {
            set_PWM (0x40, 1,0, i);
            HAL_Delay(5);
        }
                
        for(; i > 0; i-=20)
        {
        
            set_PWM (0x40, 1,0, i);
            HAL_Delay(5);
        }
//         PWM_off(0x40);
//          HAL_Delay(200);

      
    }
}
