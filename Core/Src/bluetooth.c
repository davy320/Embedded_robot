#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_uart.h"
#include "string.h"
#include <stdio.h>
#include "bluetooth.h"
#include "driver.h"


void Bluetooth_Init(UART_HandleTypeDef huart1)
{
	Bluetooth_MakeDiscoverable(huart1);
}

void Bluetooth_MakeDiscoverable(UART_HandleTypeDef huart1)
{
    char command[] = "AT+DISC?\r\n";
    HAL_UART_Transmit(&huart1, (uint8_t *)command, strlen(command), HAL_MAX_DELAY);
}


void Bluetooth_Send(char* data, UART_HandleTypeDef huart1)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
}

void Bluetooth_Receive(char* buffer, uint16_t size, UART_HandleTypeDef huart1)
{
    HAL_UART_Receive(&huart1, (uint8_t*)buffer, size, HAL_MAX_DELAY);
}

void Bluetooth_Connect(UART_HandleTypeDef huart1)
{
    char connectCmd[] = "AT+CON";
    Bluetooth_Send(connectCmd, huart1);
}

void Bluetooth_SendATCommand(char* command, UART_HandleTypeDef huart1)
{
    char cmd[50];
    sprintf(cmd, "AT+%s\r\n", command);
    HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
}

void Bluetooth_SetAsMaster(UART_HandleTypeDef huart1)
{
    Bluetooth_SendATCommand("ROLE1", huart1);
}

void Bluetooth_ConnectToDevice(char* address, UART_HandleTypeDef huart1)
{
    char connectCmd[50];
    sprintf(connectCmd, "CON%s", address);
    Bluetooth_SendATCommand(connectCmd, huart1);
}

ControllerMode handleBluetoothCommands(UART_HandleTypeDef huart1) {
    char buffer[100];
    Bluetooth_Receive(buffer, sizeof(buffer), huart1);

    switch(buffer[0]) {
        case 'F':
            moveForward(100);
            break;
        case 'B':
            moveBackward(100);
            break;
        case 'L':
            moveForwardLeft(100);
            break;
        case 'R':
            moveForwardRight(100);
            break;
        case 'M':
        	break;
        case 'N':
        	return FREE_ROAM_MODE;
        default:
        	break;
    }
    return BLUETOOTH_MODE;
}
