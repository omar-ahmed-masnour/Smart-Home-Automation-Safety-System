/*
 * main.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Omar Mansour
 */
#include "gpio.h"
#include "adc.h"
#include "buzzer.h"
#include "dc_motor.h"
#include"flame_sensor.h"
#include "gpio.h"
#include "lcd.h"
#include"ldr.h"
#include"led.h"
#include"lm35_sensor.h"
#include"pwm.h"
#include <util/delay.h>




#define BUZZER_PORT PORTD_ID
#define BUZZER_PIN PIN3_ID

#define RED_LED_PORT PORTB_ID
#define RED_LED_PIN PIN5_ID

#define GREEN_LED_PORT PORTB_ID
#define GREEN_LED_PIN PIN6_ID

#define BLUE_LED_PORT PORTB_ID
#define BLUE_LED_PIN PIN7_ID

#define FLAME_SENSOR_PORT PORTD_ID
#define FLAME_SENSOR_PIN  PIN2_ID

int main()
{
	LED_init(RED_LED_PORT, RED_LED_PIN);
	LED_init(GREEN_LED_PORT, GREEN_LED_PIN);
	LED_init(BLUE_LED_PORT, BLUE_LED_PIN);
	DcMotor_init();
	ADC_init();
	BUZZER_init(PORTD_ID,PIN3_ID);
	LCD_init();
	// LCD_displayString("Hello Omar");


	uint8 ldr_reading;
	uint8 flame_value;
	uint8 room_temp;
	uint8 reset_screen =0;
	while(1)
	{
		/* Poll sensor */
		flame_value = FlameSensor_getValue(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN);
		ldr_reading = LDR_getLightIntensity();
		room_temp= LM35_getTemperature();
		//room_temp = 20;

		/***********************************************************************************
		 * 								Room Lighting									   *
		 ***********************************************************************************/

		if(ldr_reading <=15)
		{
			LED_onPosLogic(RED_LED_PORT, RED_LED_PIN);
			LED_onPosLogic(GREEN_LED_PORT, GREEN_LED_PIN);
			LED_onPosLogic(BLUE_LED_PORT, BLUE_LED_PIN);
		}
		else if(ldr_reading <=50)
		{

			LED_offPosLogic(BLUE_LED_PORT, BLUE_LED_PIN);

			LED_onPosLogic(RED_LED_PORT, RED_LED_PIN);
			LED_onPosLogic(GREEN_LED_PORT, GREEN_LED_PIN);

		}
		else if(ldr_reading <=70)
		{

			LED_offPosLogic(GREEN_LED_PORT, GREEN_LED_PIN);
			LED_offPosLogic(BLUE_LED_PORT, BLUE_LED_PIN);

			LED_onPosLogic(RED_LED_PORT, RED_LED_PIN);

		}
		else if(ldr_reading >70)
		{
			LED_offPosLogic(RED_LED_PORT, RED_LED_PIN);
			LED_offPosLogic(GREEN_LED_PORT, GREEN_LED_PIN);
			LED_offPosLogic(BLUE_LED_PORT, BLUE_LED_PIN);
		}

		/***********************************************************************************
		 * 								Flame Sensor									   *
		 ***********************************************************************************/

		if(flame_value==LOGIC_HIGH)
		{
			BUZZER_on(PORTD_ID,PIN3_ID);
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"Critical alert!");
			 _delay_ms(100);
			 reset_screen=1;
			 continue;

		}
		else
		{
			BUZZER_off(PORTD_ID,PIN3_ID);

			if(reset_screen==1)
			{
				LCD_clearScreen();
			}
			reset_screen=0;
		}


		/***********************************************************************************
		 * 								Room Temperature								   *
		 ***********************************************************************************/

		if(room_temp >= 40 )
		{
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0,0,"FAN is ON ");
		}
		else if(room_temp>=35)
		{
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0,0,"FAN is ON ");
		}
		else if(room_temp>=30)
		{
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0,0,"FAN is ON ");
		}
		else if(room_temp>=25)
		{
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0,0,"FAN is ON ");
		}
		else if(room_temp <25)
		{
			DcMotor_Rotate(stop,0);
			LCD_displayStringRowColumn(0,0,"FAN is OFF");
		}



		/***********************************************************************************
		 * 								LCD Display								   *
		 ***********************************************************************************/

		LCD_moveCursor(1,0);
		LCD_displayString("Temp=");
		LCD_intgerToString(room_temp);
		LCD_displayString("C ");

		LCD_displayString("LDR=");
		LCD_intgerToString(ldr_reading);
		LCD_displayString("%  ");


	}
}











