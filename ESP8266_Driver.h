
#ifndef ESP8266_DRIVER_H_
#define ESP8266_DRIVER_H_

#include "uart_driver.h"

typedef enum {Rx_Complete, Rx_NotComplete } EnumRx_Status_t;


int8_t ESP_ReceiveChar (uint8_t * Ptr_Data);
void ESP_Init(void);



#endif