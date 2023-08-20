#ifndef __ACCELEROMETER_LIBRARY_H__
#define __ACCELEROMETER_LIBRARY_H__

#include "stm32f0xx_hal.h"

// LSM303CTR register addresses
#define LSM303CTR_WHO_AM_I_REG       0x0F
#define LSM303CTR_CTRL_REG1_XL       0x10
#define LSM303CTR_OUT_X_L_XL         0x28
#define LSM303CTR_OUT_X_H_XL         0x29
#define LSM303CTR_OUT_Y_L_XL         0x2A
#define LSM303CTR_OUT_Y_H_XL         0x2B
#define LSM303CTR_OUT_Z_L_XL         0x2C
#define LSM303CTR_OUT_Z_H_XL         0x2D

// Function prototypes
void LSM303CTR_Init(SPI_HandleTypeDef hspi1);
void LSM303CTR_ReadAccel(int16_t *x, int16_t *y, int16_t *z, SPI_HandleTypeDef hspi1);
void LSM303CTR_WriteReg(uint8_t reg, uint8_t data, SPI_HandleTypeDef hspi1);
uint8_t LSM303CTR_ReadReg(uint8_t reg, SPI_HandleTypeDef hspi1);
void LSM303CTR_ReadRegs(uint8_t reg, uint8_t *data, uint8_t len, SPI_HandleTypeDef hspi1);

#endif // LSM303CTR_H
