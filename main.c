
#include "ESP_Driver.h"
#include "uart_driver.h"
#include "Motor.h"
#include "avr/delay.h"

uint8_t LOC_Data = 0;

void ReceiveData (uint8_t Data){
	LOC_Data = Data;
}


int main(void)
{
	
	MOTOR_init();
	
	

	Disable_Interrupts();
	UART_Init(9600, ReceiveData);
	Enable_Interrupts();

	WIFI_Service_Start ( Server , 2222 , "dabQADER" , "123456789", NULL, NULL, NULL, NULL );

	while(OK_Status != ESP_SendData(" wifi demo started ", " 17") );
	
    while (1) 
    {
		LOC_Data = ESP_ReceiveData();
		_delay_ms(1000);

			if (LOC_Data == 'R')
			{
				MOTOR_Reverse(MOTOR1);
				MOTOR_Reverse(MOTOR2);
			}
			else if (LOC_Data == 'F')
			{
				MOTOR_Forward(MOTOR1);
				MOTOR_Forward(MOTOR2);	
			}
			else
			{
				MOTOR_Stop(MOTOR1);
				MOTOR_Stop(MOTOR2);
			}
		
    }
}

