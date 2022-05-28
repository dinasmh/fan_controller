/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: motor.c
 *
 * Description: source file for the DC motor driver
 *
 * Author: Dina Atef
 *
 *******************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "motor.h"
#include "gpio.h"
#include"PWM.h"

/*
 * Description :
 * Initialize the Motor:
 * 1. Setup the motor pins directions by use the GPIO driver.
 */


void motor_init(void){

	/*Setup the motor pins from the GPIO*/

	GPIO_setupPinDirection(MOTOR_PORT_ID,IN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,IN2_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,EN_ID,PIN_OUTPUT);
	/*Stopping motor at the beginning*/
	GPIO_writePin(MOTOR_PORT_ID,EN_ID,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_state state, uint8 speed){

	if (state==CW){
		GPIO_writePin(MOTOR_PORT_ID,EN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID,IN1_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID, IN2_ID, LOGIC_LOW);
		Timer0_PWM_Init(speed);
	}
	else if(state==ACW){
		GPIO_writePin(MOTOR_PORT_ID,EN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID, IN1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, IN2_ID, LOGIC_HIGH);
		Timer0_PWM_Init(speed);
	}
	else if(state==Stop){
		GPIO_writePin(MOTOR_PORT_ID, EN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, IN1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, IN2_ID, LOGIC_LOW);
		Timer0_PWM_Init(speed);
	}
}

