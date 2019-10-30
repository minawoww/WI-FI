/*
 * ESP_Driver.h
 *
 * Created: 2/16/2019 4:04:18 PM
 *  Author: Ahmed.Magdy
 */ 


#ifndef ESP_DRIVER_H_
#define ESP_DRIVER_H_

#define F_CPU 8000000ul
#include "uart_driver.h"
#include <util/delay.h>


/* ======================================================================= */
/* User Options */
/* ============ */
#define Extra_Features_Enable (0)             /* Only Enabled in Case of Micro-controllers with Memory Higher than ATmega32 */
#define SEND_STRING_TO_UART UART_Write_String /* Add UART String Write Service */
#define TIMER_WAIT_FUNCTION() _delay_ms(900)  /* Add Timer milliseconds Wait Service */

/* ======================================================================= */
/* Developer Types */
/* =============== */
#define OK_Status 1
#define NOK_Status 0
#define NO_Response 2
#define Std_ReturnType char
#define ElementDataType unsigned char
#define Data_Ptr unsigned int*
#define Response_Status_Checkpoint(); if(NOK_Status == ESP_ReadResponseLine()){return NOK_Status;}else if(NO_Response == ESP_ReadResponseLine()){return NO_Response;}
typedef enum
{
	Station_mode=49,    /* Client Mode only using the letter "1" in Ascii */
	AP_mode,           /* Access Point Mode only using the letter "2" in Ascii */
	AP_Station_mode    /* Client and Access Point Mode only using the letter "3" in Ascii */
}ESPModeType;
typedef enum
{
	Server=0,
	Client
}ESPOperationType;

/* ======================================================================= */
/* Available Services */
/* =================== */
Std_ReturnType ESP_InitTest(void);
Std_ReturnType ESP_Configure_As_server(ElementDataType* PortNumber);
Std_ReturnType ESP_Enable_multiple_connections(ElementDataType* Mode);
Std_ReturnType ESP_SelectMode(ElementDataType Mode);
Std_ReturnType ESP_CreateAccesPoint(ElementDataType* SSID, ElementDataType* Password, ElementDataType* ChannelNumber, ElementDataType* SecurityLevel);
Std_ReturnType ESP_JoinAccesPoint(ElementDataType* SSID, ElementDataType* Password);
Std_ReturnType ESP_StartServer(ElementDataType* PortNumber);
Std_ReturnType ESP_StartTCPConnection(ElementDataType* IP, ElementDataType* PortNumber);
Std_ReturnType ESP_SendData(ElementDataType* Data, ElementDataType* DataSize);
Data_Ptr ESP_ReceiveData(void);
void ESP_FillResponseBuffer(ElementDataType data);
void ESP_ClearResponseBuffer(void);
                                       /*Server, PORT, SSID, PASSWORD, NULL, NULL, NULL, NULL*/
void WIFI_Service_Start(ESPOperationType Mode, ElementDataType* Server_Operation_Port,ElementDataType* Server_Operation_SSID, ElementDataType* Server_Operation_Password,
ElementDataType* Client_Operation_SSID, ElementDataType* Client_Operation_Password, ElementDataType* Client_Operation_IP, ElementDataType* Client_Operation_Port );


#if Extra_Features_Enable
Std_ReturnType ESP_WaitForPeerConnect(void);
Std_ReturnType ESP_SetStationIP(ElementDataType* IP);
Std_ReturnType ESP_SetAcessPointIP(ElementDataType* IP);
Std_ReturnType ESP_DHCPEnable(ElementDataType* Mode, ElementDataType* Enable);
Std_ReturnType ESP_QuitAcessPoint();
#endif
/* ======================================================================= */

#endif /* ESP_DRIVER_H_ */