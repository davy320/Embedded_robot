#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_uart.h"
#include "string.h"
#include <stdio.h>
#include "bluetooth.h"
#include "driver.h"

// Define the UART handle
extern UART_HandleTypeDef huart2;

// Initialization function
void Bluetooth_Init(void) {
    // UART initialization parameters

    if (HAL_UART_Init(&huart2) != HAL_OK) {
        // Initialization Error
        Bluetooth_Error_Handler();
    } else {
    	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
    	HAL_Delay(2000);
    	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
    }
}

HAL_StatusTypeDef Bluetooth_SendATCommand(char* command, char* response, uint16_t responseSize) {
    HAL_StatusTypeDef status;

    // Send the command
    status = HAL_UART_Transmit(&huart2, (uint8_t*)command, strlen(command), HAL_MAX_DELAY1);  // 1000ms timeout
    if(status != HAL_OK) {
	    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
        return status;
    }

    HAL_Delay(100);

    status = HAL_UART_Receive(&huart2, (uint8_t*)response, responseSize, HAL_MAX_DELAY1);  // 1000ms timeout
    // Receive the response with a timeout
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
    return status;
}

// Test the connection
HAL_StatusTypeDef Bluetooth_TestConnection(void) {
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);

    char response[5];
    return Bluetooth_SendATCommand("AT\r\n", response, 4);
}

// Set the name of the HM-10 module
HAL_StatusTypeDef Bluetooth_SetName(char* name) {
	char command[20];
	char response[30];

	snprintf(command, sizeof(command), "AT+NAME%s\r\n", name);
	return Bluetooth_SendATCommand(command, response, sizeof(response));
}

// Get the name of the HM-10 module
HAL_StatusTypeDef Bluetooth_GetName(char* name, uint16_t size) {
    return Bluetooth_SendATCommand("AT+NAME?\r\n", name, size);
}

// Set the passcode of the HM-10 module
HAL_StatusTypeDef Bluetooth_SetPasscode(char* passcode) {
    char command[20];
    char response[30];

    snprintf(command, sizeof(command), "AT+PASS%s\r\n", passcode);
    return Bluetooth_SendATCommand(command, response, sizeof(response));
}

// Get the passcode of the HM-10 module
HAL_StatusTypeDef Bluetooth_GetPasscode(char* passcode, uint16_t size) {
    return Bluetooth_SendATCommand("AT+PASS?\r\n", passcode, size);
}

// Get the role of the HM-10 module (should be 0 for slave)
HAL_StatusTypeDef Bluetooth_GetRole(char* role, uint16_t size) {
    return Bluetooth_SendATCommand("AT+ROLE?\r\n", role, size);
}

// Get the MAC address of the HM-10 module
HAL_StatusTypeDef Bluetooth_GetAddress(char* address, uint16_t size) {
    return Bluetooth_SendATCommand("AT+ADDR?\r\n", address, size);
}

// Check work mode
HAL_StatusTypeDef Bluetooth_CheckWorkMode(char* mode, uint16_t size) {
    return Bluetooth_SendATCommand("AT+IMME?\r\n", mode, size);
}

// Set work mode
HAL_StatusTypeDef Bluetooth_SetWorkMode(char mode) {
    char command[15];
    char response[25];

    snprintf(command, sizeof(command), "AT+IMME%c\r\n", mode);
    return Bluetooth_SendATCommand(command, response, sizeof(response));
}

void Bluetooth_Error_Handler(void) {
	  // Toggle the RED LED # error
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	while (1) {
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
	  HAL_Delay(200);
	}
}

