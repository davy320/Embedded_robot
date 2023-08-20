#include "accel.h"
#include <stdio.h>

#include "stm32f0xx_hal_spi.h"
#include "stm32f0xx_hal.h"


void LSM303CTR_Init(SPI_HandleTypeDef hspi1) {
    uint8_t data;

    data = LSM303CTR_ReadReg(LSM303CTR_WHO_AM_I_REG, hspi1);
    if (data != 0x41) {
    	printf("Unable to detect LSM303CTR");
    }

    data = 0x60;
    LSM303CTR_WriteReg(LSM303CTR_CTRL_REG1_XL, data, hspi1);
}

void LSM303CTR_ReadAccel(int16_t *x, int16_t *y, int16_t *z, SPI_HandleTypeDef hspi1) {
    uint8_t data[6];

    LSM303CTR_ReadRegs(LSM303CTR_OUT_X_L_XL, data, 6, hspi1);

    *x = (int16_t)(data[1] << 8 | data[0]);
    *y = (int16_t)(data[3] << 8 | data[2]);
    *z = (int16_t)(data[5] << 8 | data[4]);
}

void LSM303CTR_WriteReg(uint8_t reg, uint8_t data, SPI_HandleTypeDef hspi1) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);  // CS_XL low
    HAL_SPI_Transmit(&hspi1, &reg, 1, HAL_MAX_DELAY);
    HAL_SPI_Transmit(&hspi1, &data, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);    // CS_XL high
}

uint8_t LSM303CTR_ReadReg(uint8_t reg, SPI_HandleTypeDef hspi1) {
    uint8_t data;
    reg |= 0x80;

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);  // CS_XL low
    HAL_SPI_Transmit(&hspi1, &reg, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, &data, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);    // CS_XL high

    return data;
}

void LSM303CTR_ReadRegs(uint8_t reg, uint8_t *data, uint8_t len, SPI_HandleTypeDef hspi1) {
    reg |= 0x80;

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);  // CS_XL low
    HAL_SPI_Transmit(&hspi1, &reg, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, data, len, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);    // CS_XL high
}
