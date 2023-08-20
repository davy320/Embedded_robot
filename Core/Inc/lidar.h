#ifndef LIDAR_LIB_H
#define LIDAR_LIB_H

#include "stm32f0xx_hal.h"

// Define the I2C address of the VL53L1X sensors
#define VL53L1X_DEFAULT_ADDRESS 0x52
#define VL53L1X_SENSOR1_ADDRESS VL53L1X_DEFAULT_ADDRESS
#define VL53L1X_SENSOR2_ADDRESS 0x53

// Function prototypes
HAL_StatusTypeDef initVL53L1X(uint8_t sensorAddress, I2C_HandleTypeDef hi2c1);
HAL_StatusTypeDef readVL53L1XDistance(uint8_t sensorAddress, uint16_t *distance, I2C_HandleTypeDef hi2c1);

#endif // LIDAR_LIB_H
