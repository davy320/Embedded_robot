#include "motor_controller.h"
#include "main.h"
#include "stm32f0xx_hal.h"
#include "main.h"

#define MOTOR_PORT      GPIOA

#define EN_A_PIN        GPIO_PIN_0
#define INPUT_A_1_PIN   GPIO_PIN_1
#define INPUT_A_2_PIN   GPIO_PIN_3
#define EN_B_PIN        GPIO_PIN_6
#define INPUT_B_1_PIN   GPIO_PIN_4
#define INPUT_B_2_PIN   GPIO_PIN_5

extern TIM_HandleTypeDef htim3; /* PWM pin EN_B - generated automatically by STM32CubeIDE */

MotorStatus motorStatus = {
    .dirA = MOTOR_STOPPED,
    .dirB = MOTOR_STOPPED,
    .speedA = 0,
    .speedB = 0
};

void initMotor() {
    HAL_GPIO_WritePin(MOTOR_PORT, EN_A_PIN | INPUT_A_1_PIN | INPUT_A_2_PIN | INPUT_B_1_PIN | INPUT_B_2_PIN, GPIO_PIN_RESET);
    motorStatus.dirA = MOTOR_STOPPED;
    motorStatus.dirB = MOTOR_STOPPED;
    motorStatus.speedA = 0;
    motorStatus.speedB = 0;

    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void setMotorDirectionA(MotorDirection dir) {
    switch(dir) {
        case MOTOR_FORWARD:
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_A_1_PIN, GPIO_PIN_SET);
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_A_2_PIN, GPIO_PIN_RESET);
            motorStatus.dirA = MOTOR_FORWARD;
            break;
        case MOTOR_BACKWARD:
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_A_1_PIN, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_A_2_PIN, GPIO_PIN_SET);
            motorStatus.dirA = MOTOR_BACKWARD;
            break;
        case MOTOR_STOPPED:
        default:
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_A_1_PIN | INPUT_A_2_PIN, GPIO_PIN_RESET);
            motorStatus.dirA = MOTOR_STOPPED;
            break;
    }
}

void setMotorDirectionB(MotorDirection dir) {
    switch(dir) {
        case MOTOR_FORWARD:
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_B_1_PIN, GPIO_PIN_SET);
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_B_2_PIN, GPIO_PIN_RESET);
            motorStatus.dirB = MOTOR_FORWARD;
            break;
        case MOTOR_BACKWARD:
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_B_1_PIN, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_B_2_PIN, GPIO_PIN_SET);
            motorStatus.dirB = MOTOR_BACKWARD;
            break;
        case MOTOR_STOPPED:
        default:
            HAL_GPIO_WritePin(MOTOR_PORT, INPUT_B_1_PIN | INPUT_B_2_PIN, GPIO_PIN_RESET);
            motorStatus.dirB = MOTOR_STOPPED;
            break;
    }
}

void setMotorSpeedA(uint16_t speed) {
    if (speed == 0) {
        HAL_GPIO_WritePin(MOTOR_PORT, EN_A_PIN, GPIO_PIN_RESET);
    } else {
        HAL_GPIO_WritePin(MOTOR_PORT, EN_A_PIN, GPIO_PIN_SET);
    }

    motorStatus.speedA = speed;
}

void setMotorSpeedB(uint16_t speed) {
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speed);

    motorStatus.speedB = speed;
}


void stopMotors() {
    setMotorSpeedA(0);
    setMotorSpeedB(0);
    setMotorDirectionA(MOTOR_STOPPED);
    setMotorDirectionB(MOTOR_STOPPED);
}

MotorStatus getMotorStatus() {
    return motorStatus;
}

