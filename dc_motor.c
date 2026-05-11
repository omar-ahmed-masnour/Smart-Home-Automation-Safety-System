/*
 * dc_motor.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Omar Mansour
 */
#include "dc_motor.h"

void DcMotor_init(void)
{
	GPIO_setupPinDirection( DC_MOTOR_IN1_PORT,  DC_MOTOR_IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection( DC_MOTOR_IN2_PORT,  DC_MOTOR_IN2_PIN, PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_HIGH);
	GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_HIGH);

}
void DcMotor_Rotate(DC_MOTOR_State state, uint8 speed)
{
	PWM_ConfigType config;
	config.PWM_Port = PORTB_ID;
	config.PWM_Pin = PIN3_ID;
	config.PWM_Speed = speed;
	config.mode = non_inverting;
	config.pre_scaler = F_CPU_1024;

	Timer0_PWM_Init(&config);

	switch (state)
	{
	case stop:
		GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_HIGH);
		break;

	case Anti_CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_HIGH);
		break;

	case CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_LOW);

		break;
	}



}




