/*
 * DIO_conf.h
 *
 *  Created on: Sep 20, 2019
 *      Author: abdelqader
 */

#ifndef DIO_CONF_H_
#define DIO_CONF_H_

#include "REG_Lib.h"
#include "STD_Types.h"

typedef enum { En1,MOTOR1A,MOTOR1B,MOTOR2A,MOTOR2B,En2 ,NUM_PINS } PINS_t ;


#define PORT_A		0
#define PORT_B		1
#define PORT_C		2
#define PORT_D		3

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

#define OUTPUT		1
#define INPUT		0

#define HIGH		1
#define LOW			0

#define PULLUP		1
#define EXTRES		0

#define INITIALIZED			1
#define NOT_INITIALIZED		0

#define NA			0xff


typedef struct {

	uint8 PORT;
	uint8 PIN;
	uint8 Dir;
	uint8 Val;
	uint8 Res;
	uint8 IS_Init;

}DIO_Conf_t;


extern DIO_Conf_t DIO_Array[NUM_PINS];


#endif /* DIO_CONF_H_ */
