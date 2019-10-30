
#include "ESP8266_Driver.h"
#include "Motor.h"


int main(void)
{
	
	MOTOR_init();
	
	uint8_t LOC_Data = 0;
	// wait to initialize the wifi
	ESP_Init();
	
    while (1) 
    {
		if(ESP_ReceiveChar(&LOC_Data) != -1)
		{
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
			else if (LOC_Data == 'S')
			{
				MOTOR_Stop(MOTOR1);
				MOTOR_Stop(MOTOR2);
			}
		}
    }
}

