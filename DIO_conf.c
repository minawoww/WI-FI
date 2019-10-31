/*
 * DIO_conf.c
 *
 *  Created on: Sep 20, 2019
 *      Author: abdelqader
 */

#include"DIO_conf.h"

/*Configure your pins with the same order in the enum
 { port , pin Number , Pin direction , output_value , Pullup/external resistor , initialized/not initialized }*/
	 
DIO_Conf_t DIO_Array[NUM_PINS] = {
		{PORT_D, PIN4, OUTPUT, HIGH, NA, INITIALIZED },
		{PORT_D, PIN2, OUTPUT, LOW, NA, INITIALIZED },
		{PORT_D, PIN3, OUTPUT, LOW, NA, INITIALIZED },
		{PORT_D, PIN6, OUTPUT, LOW, NA, INITIALIZED },
		{PORT_D, PIN7, OUTPUT, LOW, NA, INITIALIZED },
		{PORT_D, PIN5, OUTPUT, HIGH, NA, INITIALIZED },
};
