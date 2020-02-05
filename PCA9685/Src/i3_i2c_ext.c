#include "i3_i2c_ext.h"

#include "stm32f3xx_hal.h"


extern I2C_HandleTypeDef hi2c2;
extern void Error_Handler(void);


static volatile uint8_t i2c_busy = 0;
static volatile uint8_t i2c_received = 0;

uint8_t I3_I2C_Ext_Check(uint8_t addr) {
  return HAL_I2C_IsDeviceReady(&hi2c2, addr<<1, 10, 10) == HAL_OK;
}

uint8_t I3_I2C_Ext_Busy() {
  return i2c_busy;
}

void I3_I2C_Ext_Read(uint8_t addr, uint8_t* buff, size_t size) {
  i2c_busy = 1;
  HAL_I2C_Master_Receive_IT(&hi2c2, (uint16_t)addr<<1, buff, size);
  while (! i2c_received);
  i2c_received = 0;
}

void I3_I2C_Ext_Write(uint8_t addr, uint8_t* buff, size_t size) {
//   i2c_busy = 1;
//   HAL_I2C_Master_Transmit_IT(&hi2c1, (uint16_t)addr<<1, buff, size);
  HAL_I2C_Master_Transmit(&hi2c2, (uint16_t)addr<<1, buff, size, 10);   // WTF???
}

void I2C_Ext_Mem_Read(uint8_t addr, uint16_t reg, uint8_t reg_size, uint8_t* buff, size_t size) {
  i2c_busy = 1;
  HAL_I2C_Mem_Read_IT(&hi2c2, (uint16_t) addr<<1, reg, reg_size, buff, size);
  while (! i2c_received);
  i2c_received = 0;
}

void I2C_Ext_Mem_Write(uint8_t addr, uint16_t reg, uint8_t reg_size, uint8_t* buff, size_t size) {                      // Bicycle, but there is HAL driver bug
    HAL_I2C_Mem_Write(&hi2c2, (uint16_t) addr<<1, reg, reg_size, buff, size, 10);
}


void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef* hi2c) {
  i2c_busy = 0;
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef* hi2c) {
  i2c_busy = 0;
  i2c_received = 1;
}

void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef* hi2c) {
  i2c_busy = 0;
}

void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef* hi2c) {
  i2c_busy = 0;
  i2c_received = 1;
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef* hi2c) {
  Error_Handler();
}
