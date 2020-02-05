#include "uart.h"
#include <string.h>
#include "stm32f3xx_hal.h"



extern UART_HandleTypeDef huart2;

static char    println_buff[50] = {0};
static uint8_t byte_buff        = 0;
static volatile uint8_t uart_busy_flag = 0;



void UART_print(char msg[]) {
  while(HAL_UART_Transmit_IT(&huart2, (uint8_t*) msg, strlen(msg)) != HAL_OK);
  uart_busy_flag = 1;
}

void UART_println(char msg[]) {
  while(uart_busy_flag);
  uart_busy_flag = 1;
  strcpy(println_buff, msg);
  strcat(println_buff, "\n");
  while(HAL_UART_Transmit_IT(&huart2, (uint8_t*) println_buff, strlen(println_buff)) != HAL_OK);
}

void UART_start_receiving() {
  while(HAL_UART_Receive_IT(&huart2, &byte_buff, 1) != HAL_OK);
}


void UART_TxEndCallback() {
  uart_busy_flag = 0;
}

void UART_RxEndCallback() {
  HAL_UART_Receive_IT(&huart2, &byte_buff, 1);
}

void HAL_UART_TxCpltCallback (UART_HandleTypeDef *huart) 
{
  if      (huart->Instance == USART2) UART_TxEndCallback();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{
  if      (huart->Instance == USART2) UART_RxEndCallback();
}

