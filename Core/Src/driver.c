#include "motor_controller.h"
#include "driver.h"

void moveForward(uint16_t speed) {
    setMotorDirectionA(MOTOR_FORWARD);
    setMotorDirectionB(MOTOR_FORWARD);
    setMotorSpeedA(speed);
    setMotorSpeedB(speed);
}

void moveBackward(uint16_t speed) {
    setMotorDirectionA(MOTOR_BACKWARD);
    setMotorDirectionB(MOTOR_BACKWARD);
    setMotorSpeedA(speed);
    setMotorSpeedB(speed);
}

void moveForwardLeft(uint16_t speed) {
    setMotorDirectionA(MOTOR_STOPPED);
    setMotorDirectionB(MOTOR_FORWARD);
    setMotorSpeedA(0);
    setMotorSpeedB(speed);
}

void moveForwardRight(uint16_t speed) {
    setMotorDirectionA(MOTOR_FORWARD);
    setMotorDirectionB(MOTOR_STOPPED);
    setMotorSpeedA(speed);
    setMotorSpeedB(0);
}

void moveBackwardLeft(uint16_t speed) {
    setMotorDirectionA(MOTOR_STOPPED);
    setMotorDirectionB(MOTOR_BACKWARD);
    setMotorSpeedA(0);
    setMotorSpeedB(speed);
}

void moveBackwardRight(uint16_t speed) {
    setMotorDirectionA(MOTOR_BACKWARD);
    setMotorDirectionB(MOTOR_STOPPED);
    setMotorSpeedA(speed);
    setMotorSpeedB(0);
}

