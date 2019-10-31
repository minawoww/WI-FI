
#include "uart_driver.h"
#include <stdlib.h>
#include "avr/io.h"

static UART_PtrToFunc UART_Rx_Callback = NULL;
void UART_Init(uint32_t speed,UART_PtrToFunc UART_Receive_Callback)
{
	//uscr register
	UCSRC=0b10000110; 
	uint16_t baud_Rate = 0;
	// baud rate registers value 
	baud_Rate = ((SYSTEM_FREQ) / ((speed)*16UL))-1;
	// UART transmitting and receiving enable
	UCSRB |= (1U<<RxEN) |(1U<<TxEN);
	if (UART_Receive_Callback != NULL)
	{
		UART_Rx_Callback = UART_Receive_Callback;
		// UART receive enable and interrupt on receive enable
		UCSRB |= (1U<<RxIE);
	}
	// set registers with baud rate value
	UBRRH	 =		(baud_Rate>>8);
	UBRRL	 =		 baud_Rate;
}
void UART_DeInit(void)
{
	UCSRB = 0;
}


void UART_Write_String(char data[])
{
	while(*data != 0)
	{
		UART_Write_Byte(*data);
		data++;
	}
}
void UART_Write_Byte(char data)
{
	while ( !(UCSRA & (1<<UDRE)) );
	UDR = data;
}

char UART_Receive_Byte(void)
{
	while ( !(UCSRA & (1<<RXC)) );
	return UDR;
}



ISR(USART_RXC_vect)
{
	UART_Rx_Callback(UDR);
}

void Wait_for_Transmission_Complete(void)
{
	while((UCSRA &(1U<<TXC)) == 0);
}



