#ifndef __I3_I2C_EXT_H
#define __I3_I2C_EXT_H

#include <stdint.h>
#include <stdlib.h>

uint8_t I3_I2C_Ext_Check(uint8_t addr);
uint8_t I3_I2C_Ext_Busy (void);
void    I3_I2C_Ext_Read (uint8_t addr, uint8_t* buff, size_t size);
void    I3_I2C_Ext_Write(uint8_t addr, uint8_t* buff, size_t size);
void    I2C_Ext_Mem_Write(uint8_t addr, uint16_t reg, uint8_t reg_size, uint8_t* buff, size_t size);
void    I2C_Ext_Mem_Read (uint8_t addr, uint16_t reg, uint8_t reg_size, uint8_t* buff, size_t size);


#endif // __I3_I2C_EXT_H
