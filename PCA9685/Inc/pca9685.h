#ifndef __PCA9685_H
#define __PCA9685_H

#include "stdint.h"

#define PCA9685_MODE1               0x00
#define PCA9685_MODE2               0x01
#define PCA9685_SUBADR1             0x02
#define PCA9685_SUBADR2             0x03
#define PCA9685_SUBADR3             0x04
#define PCA9685_PRESCALE            0xFE
#define PCA9685_LED0_ON_L           0x06
#define PCA9685_LED0_ON_H           0x07
#define PCA9685_LED0_OFF_L          0x08
#define PCA9685_LED0_OFF_H          0x09
#define PCA9685_ALL_LED_ON_L        0xFA
#define PCA9685_ALL_LED_ON_H        0xFB
#define PCA9685_ALL_LED_OFF_L       0xFC
#define PCA9685_ALL_LED_OFF_H       0xFD

#define PCA9685_RESTART             0x80
#define PCA9685_SLEEP               0x10
#define PCA9685_ALLCALL             0x01
#define PCA9685_INVRT               0x10
#define PCA9685_OUTDRV              0x04

uint8_t pca_init(uint8_t addr, uint16_t freq);
uint8_t set_PWM (uint8_t addr, uint8_t channel,uint16_t on, uint16_t off);
void PWM_off(uint8_t addr);
void pcaByteWrite(uint8_t addr, uint8_t reg, uint8_t data);

#endif /* __PCA9685_H */ 
