/*
 * Motor.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Mahmoud Rezk Mahmoud , Mustafa Khalil
 */
#include "Motor.h"



uint8 MOTOR_init(void)
{
	uint8 retval=OK;
	uint8 LOOP_index=0;

	for(LOOP_index=0;LOOP_index<NUM_OF_Motors;LOOP_index++)
	{
		switch(MOTOR_cnfg_arr[LOOP_index].MOTOR_ID)
		{
		case MOTOR1:
			switch(MOTOR_cnfg_arr[LOOP_index].MOTOR_STATUS)
			{
			case STOP:
				DIO_Write(MOTOR1A,LOW);
				DIO_Write(MOTOR1B,LOW);
				break;
			case FORWARD:
				DIO_Write(MOTOR1A,HIGH);
				DIO_Write(MOTOR1B,LOW);
				break;
			case REVERSE:
				DIO_Write(MOTOR1A,LOW);
				DIO_Write(MOTOR1B,HIGH);
				break;
			default:
				retval=NOK;
				break;
			}
			break;
			case MOTOR2:
				switch(MOTOR_cnfg_arr[LOOP_index].MOTOR_STATUS)
				{
				case STOP:
					DIO_Write(MOTOR2A,LOW);
					DIO_Write(MOTOR2B,LOW);
					break;
				case FORWARD:
					DIO_Write(MOTOR2A,HIGH);
					DIO_Write(MOTOR2B,LOW);
					break;
				case REVERSE:
					DIO_Write(MOTOR2A,LOW);
					DIO_Write(MOTOR2B,HIGH);
					break;
				default:
					retval=NOK;
					break;
				}
				break;
				default:
				
				DIO_Write(MOTOR1A,LOW);
				DIO_Write(MOTOR1B,LOW);
				DIO_Write(MOTOR2A,LOW);
				DIO_Write(MOTOR2B,LOW);

					retval=NOK;
					break;
		}
	}


	return retval;
}

uint8 MOTOR_Forward(uint8 Motor_Num)
{
	uint8 retval=OK;
	if(Motor_Num<NUM_OF_Motors)
	{
		if(Motor_Num==MOTOR1)
		{
			DIO_Write(MOTOR1A,HIGH);
			DIO_Write(MOTOR1B,LOW);
		}
		else if(Motor_Num==MOTOR2)
		{
			DIO_Write(MOTOR2A,HIGH);
			DIO_Write(MOTOR2B,LOW);
		}
		else
		{
			retval=NOK;

		}

	}
	else
	{
		retval=NOK;
	}

	return retval;

}

uint8 MOTOR_Reverse(uint8 Motor_Num)
{
	uint8 retval=OK;
	if(Motor_Num<NUM_OF_Motors)
	{
		if(Motor_Num==MOTOR1)
		{
			DIO_Write(MOTOR1A,LOW);
			DIO_Write(MOTOR1B,HIGH);
		}
		else if(Motor_Num==MOTOR2)
		{
			DIO_Write(MOTOR2A,LOW);
			DIO_Write(MOTOR2B,HIGH);
		}
		else
		{
				retval=NOK;

		}

	}
	else
	{
		retval=NOK;
	}


	return retval;

}


uint8 MOTOR_Stop(uint8 Motor_Num)
{
	uint8 retval=OK;
	if(Motor_Num<NUM_OF_Motors)
	{
		if(Motor_Num==MOTOR1)
		{
			DIO_Write(MOTOR1A,LOW);
			DIO_Write(MOTOR1B,LOW);
		}
		else if(Motor_Num==MOTOR2)
		{
			DIO_Write(MOTOR2A,LOW);
			DIO_Write(MOTOR2B,LOW);
		}
		else
		{
			retval=NOK;


		}
	}
	else
	{
		retval= NOK;
	}


	return retval;

}


