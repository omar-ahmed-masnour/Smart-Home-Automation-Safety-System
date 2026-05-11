/*
 * flame_sensor.h
 *
 *  Created on: Sep 30, 2025
 *      Author: agh
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_
#include "gpio.h"


/*****************************************************************************************************
 * 								FUNCTION PROTOTYPES													 *
 ****************************************************************************************************/

void FlameSensor_init(uint8 FLAME_SENSOR_portNum, uint8 FLAME_SENSOR_pinNum);

uint8 FlameSensor_getValue(uint8 FLAME_SENSOR_portNum, uint8 FLAME_SENSOR_pinNum);

#endif /* FLAME_SENSOR_H_ */
