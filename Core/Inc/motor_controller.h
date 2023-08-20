#ifndef __MOTOR_CONTROLLER_H__
#define __MOTOR_CONTROLLER_H__

#include "stm32f0xx_hal.h"

#define MOTOR_PORT      GPIOA

#define EN_A_PIN        GPIO_PIN_0
#define INPUT_A_1_PIN   GPIO_PIN_1
#define INPUT_A_2_PIN   GPIO_PIN_3
#define EN_B_PIN        GPIO_PIN_6
#define INPUT_B_1_PIN   GPIO_PIN_4
#define INPUT_B_2_PIN   GPIO_PIN_5

typedef enum {
    MOTOR_STOPPED,
    MOTOR_FORWARD,
    MOTOR_BACKWARD
} MotorDirection;

typedef struct {
    MotorDirection dirA;
    MotorDirection dirB;
    uint16_t speedA;
    uint16_t speedB;
} MotorStatus;

void initMotor(void);
void setMotorDirectionA(MotorDirection dir);
void setMotorDirectionB(MotorDirection dir);
void setMotorSpeedA(uint16_t speed);
void setMotorSpeedB(uint16_t speed);
void stopMotors(void);
MotorStatus getMotorStatus(void);

#endif // MOTOR_DRIVER_H
