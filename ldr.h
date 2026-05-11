/*
 * ldr.h
 *
 *  Created on: Sep 29, 2025
 *      Author: Omar Mansour
 */

#ifndef LDR_H_
#define LDR_H_
#include"adc.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100

/*******************************************************************************
 *                                Function prototypes                                  *
 *******************************************************************************/

uint16 LDR_getLightIntensity(void);


#endif /* LDR_H_ */
