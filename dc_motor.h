/*
 * dc_motor.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Omar Mansour
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"gpio.h"
#include"pwm.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_IN1_PORT   PORTB_ID
#define DC_MOTOR_IN1_PIN    PIN0_ID
#define DC_MOTOR_IN2_PORT   PORTB_ID
#define DC_MOTOR_IN2_PIN    PIN1_ID

typedef enum{
	CW, Anti_CW, stop
}DC_MOTOR_State;



void DcMotor_init(void);
void DcMotor_Rotate(DC_MOTOR_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
