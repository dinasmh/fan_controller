/******************************************************************************
 *
 * Module: Main Function
 *
 * File Name: main.c
 *
 * Description: source file for the main function
 *
 * Author: Dina Atef
 *
 *******************************************************************************/
#include"lm35_sensor.h"
#include"motor.h"
#include"lcd.h"
#include "adc.h"

int main(void){
	uint8 temp;
	ADC_ConfigType adc={internal,F_8};
	ADC_init(adc);
	LCD_init();
	motor_init();
	LCD_displayString("Temp =       C");

	while(1){
		temp = LM35_getTemperature();
		LCD_moveCursor(0,9);
		LCD_intgerToString(temp);

		if(temp>=120){
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(1,2);
			LCD_displayString("Fan is ON");
		}
		else if(temp>=90){
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(1,2);
			LCD_displayString("Fan is ON");
		}
		else if(temp>=60){
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(1,2);
			LCD_displayString("Fan is ON");
		}
		else if(temp>=30){
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(1,2);
			LCD_displayString("Fan is ON");
		}
		else if(temp < 30 && temp>0){
			DcMotor_Rotate(Stop,0);
			LCD_moveCursor(1,2);
			LCD_displayString("Fan is OFF");
		}
	}
}
