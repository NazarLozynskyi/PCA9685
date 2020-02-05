#include "pca9685.h"
#include "i3_i2c_ext.h"
#include "stdint.h"

uint8_t pca_init(uint8_t addr, uint16_t freq)
{
    uint8_t prescale = 25000000/4096/freq;
    
    pcaByteWrite(addr, PCA9685_MODE2, PCA9685_OUTDRV);
    pcaByteWrite(addr, PCA9685_MODE1, PCA9685_SLEEP);
    pcaByteWrite(addr, PCA9685_PRESCALE, prescale);
    pcaByteWrite(addr, PCA9685_MODE1, PCA9685_ALLCALL|PCA9685_RESTART);
    return 0;
}

uint8_t set_PWM (uint8_t addr, uint8_t channel,uint16_t on, uint16_t off)
{
    pcaByteWrite(addr, PCA9685_LED0_ON_L+4*channel,  on  & 0xFF);
    pcaByteWrite(addr, PCA9685_LED0_ON_H+4*channel,  on  >> 8);
    pcaByteWrite(addr, PCA9685_LED0_OFF_L+4*channel, off & 0xFF);
    pcaByteWrite(addr, PCA9685_LED0_OFF_H+4*channel, off >> 8);
    

    return 0;
}

void PWM_off(uint8_t addr)
{
    pcaByteWrite(addr, PCA9685_ALL_LED_ON_L, 0x00);
    pcaByteWrite(addr, PCA9685_ALL_LED_ON_H, 0x00);
    pcaByteWrite(addr, PCA9685_ALL_LED_OFF_L, 0x00);
    pcaByteWrite(addr, PCA9685_ALL_LED_OFF_H, 0x00);
}
void pcaByteWrite(uint8_t addr, uint8_t reg, uint8_t data)
{
    I2C_Ext_Mem_Write(addr, reg, 1,&data, 1);
}
