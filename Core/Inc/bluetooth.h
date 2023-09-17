#ifndef __BLUETOOTH_LIBRARY_H__
#define __BLUETOOTH_LIBRARY_H__

#include "stm32f0xx_hal.h"
#include "string.h"

#define HAL_MAX_DELAY1      1000

// Initialization function
void Bluetooth_Init(void);

// Send AT command to HM-10
HAL_StatusTypeDef Bluetooth_SendATCommand(char* command, char* response, uint16_t responseSize);

// Test the connection
HAL_StatusTypeDef Bluetooth_TestConnection(void);

// Set the name of the HM-10 module
HAL_StatusTypeDef Bluetooth_SetName(char* name);

// Get the name of the HM-10 module
HAL_StatusTypeDef Bluetooth_GetName(char* name, uint16_t size);

// Set the passcode of the HM-10 module
HAL_StatusTypeDef Bluetooth_SetPasscode(char* passcode);

// Get the passcode of the HM-10 module
HAL_StatusTypeDef Bluetooth_GetPasscode(char* passcode, uint16_t size);

// Get the role of the HM-10 module (should be 0 for slave)
HAL_StatusTypeDef Bluetooth_GetRole(char* role, uint16_t size);

// Get the MAC address of the HM-10 module
HAL_StatusTypeDef Bluetooth_GetAddress(char* address, uint16_t size);

// Check work mode
HAL_StatusTypeDef Bluetooth_CheckWorkMode(char* mode, uint16_t size);

// Set work mode
HAL_StatusTypeDef Bluetooth_SetWorkMode(char mode);

void Bluetooth_Error_Handler(void);

#endif // __BLUETOOTH_LIBRARY_H__
