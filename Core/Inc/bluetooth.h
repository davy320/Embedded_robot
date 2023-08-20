#ifndef __BLUETOOTH_LIBRARY_H__
#define __BLUETOOTH_LIBRARY_H__

#include "stm32f0xx_hal.h"
#include "string.h"

// Define states
typedef enum {
    BLUETOOTH_MODE,
    FREE_ROAM_MODE
} ControllerMode;

// Function prototypes
void Bluetooth_Init(UART_HandleTypeDef huart1);

void Bluetooth_MakeDiscoverable(UART_HandleTypeDef huart1);

void Bluetooth_Send(char* data, UART_HandleTypeDef huart1);

void Bluetooth_Receive(char* buffer, uint16_t size, UART_HandleTypeDef huart1);

void Bluetooth_SendATCommand(char* command, UART_HandleTypeDef huart1);

void Bluetooth_SetAsMaster(UART_HandleTypeDef huart1);

void Bluetooth_ConnectToDevice(char* address, UART_HandleTypeDef huart1);

ControllerMode handleBluetoothCommands(UART_HandleTypeDef huart1);

#endif // __BLUETOOTH_LIBRARY_H__
