#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include <stdint.h>
#include <avr/interrupt.h>

#define SYSTEM_FREQ	16000000ULL


#define  Disable_Interrupts()		cli()
#define  Enable_Interrupts()		sei()
#define RxEN	(4U)
#define TxEN	(3U)
#define RxIE	(7U)


typedef void(*UART_PtrToFunc)(uint8_t);

void UART_Init(uint32_t speed,UART_PtrToFunc UART_Receive_Callback);
void UART_DeInit(void);
void UART_Write_Byte(char data);
char UART_Receive_Byte(void);
void UART_Write_String(char data[]);
void Wait_for_Transmission_Complete(void);

#endif	/*	UART_DRIVER_H_	*/