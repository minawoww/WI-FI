
#include "ESP8266_Driver.h"
#include "avr/delay.h"


// variable to received the character.
static uint8_t G_ReceivedData = 0;
// status variable to check the status of the receiving
static EnumRx_Status_t Rx_Status = Rx_NotComplete;


static void UART_RxString(uint8_t Data)
{
	static uint8_t Read_Flag = 0;
		
	if (Read_Flag == 1)
	{
		Read_Flag = 0;
		G_ReceivedData = Data;
		Rx_Status = Rx_Complete;
	}
	
	if (Data == ':'){
		Read_Flag = 1;
	}

}


void ESP_Init(void){
	
	// UART init WITH BAUD RATE AS WIFI CONFIGURED AS 9600 BSP
	UART_Init(9600,UART_RxString);
	// SET UP THE MODE ON 2 AS AN ACCESS POINT
	UART_Write_String("AT+CWMODE=2\r\n");
	_delay_ms(1000);
	// CONFIGURE THE ACCESS POINT NAME AND PASSWORD
	UART_Write_String("AT+CWSAP_DEF=\"dabQADER\",\"123456789\",5,3\r\n");
	_delay_ms(2000);
	// ENABLE MULTIPLE CONNECTIONS
	UART_Write_String("AT+CIPMUX=1\r\n");
	_delay_ms(1000);
	// CREATE SERVER AT PORT NUMBER
	UART_Write_String("AT+CIPSERVER=1,2222\r\n");
	_delay_ms(1000);
	
	Enable_Interrupts(); 
	
}


int8_t ESP_ReceiveChar (uint8_t * Ptr_Data)
{
	int8_t StateVar = 1;
	if (Rx_Status == Rx_Complete){
		*Ptr_Data = G_ReceivedData;
		Rx_Status = Rx_NotComplete;
	}
	else {
		StateVar = -1;
	}
	return StateVar;
}