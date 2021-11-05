#ifndef __MOTOR_H
#define __MOTOR_H

#include "main.h"
#include "stm32f4xx_hal.h"

uint8_t motor_drive(uint8_t, int, float);
uint8_t motor_start_stop(uint8_t);
#endif
