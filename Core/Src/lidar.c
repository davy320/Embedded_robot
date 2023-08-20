#include "lidar.h"

HAL_StatusTypeDef initVL53L1X(uint8_t sensorAddress, I2C_HandleTypeDef hi2c1) {
    return HAL_OK;
}

HAL_StatusTypeDef readVL53L1XDistance(uint8_t sensorAddress, uint16_t *distance, I2C_HandleTypeDef hi2c1) {
    uint8_t data[2];
    HAL_StatusTypeDef status;

    status = HAL_I2C_Mem_Read(&hi2c1, sensorAddress, VL53L1X_DEFAULT_ADDRESS, I2C_MEMADD_SIZE_8BIT, data, 2, 1000);

    if (status == HAL_OK) {
        *distance = (data[0] << 8) | data[1];
    }

    return status;
}
