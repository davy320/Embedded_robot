#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__

#include <stdint.h>

// Function prototypes for the wrapper functions
void moveForward(uint16_t speed);
void moveBackward(uint16_t speed);
void moveForwardLeft(uint16_t speed);
void moveForwardRight(uint16_t speed);
void moveBackwardLeft(uint16_t speed);
void moveBackwardRight(uint16_t speed);

#endif // MOTOR_CONTROLLER_H
