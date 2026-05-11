/*
 * flame_sensor.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Omar Mansour
 */

#include "flame_sensor.h"

void FlameSensor_init(uint8 FLAME_SENSOR_portNum, uint8 FLAME_SENSOR_pinNum)
{
	GPIO_setupPinDirection( FLAME_SENSOR_portNum,  FLAME_SENSOR_pinNum, PIN_INPUT);
}

uint8 FlameSensor_getValue(uint8 FLAME_SENSOR_portNum, uint8 FLAME_SENSOR_pinNum)
{
	return  GPIO_readPin(FLAME_SENSOR_portNum, FLAME_SENSOR_pinNum);
}
