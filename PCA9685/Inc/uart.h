#ifndef __UART_H
#define __UART_H

void UART_print(char msg[]);
void UART_println(char msg[]);
void UART_start_receiving(void);

void UART_TxEndCallback(void);
void UART_RxEndCallback(void);

#endif // __UART_H
