/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: source file for the PWM in Timer0
 *
 * Author: Dina Atef
 *
 *******************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include"PWM.h"
#include"gpio.h"

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8 
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */
void Timer0_PWM_Init(uint8 set_duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0
	
	OCR0  = ((float)set_duty_cycle/100)*255; // Set Compare Value
	
	GPIO_setupPinDirection(PWM_PORT_ID,PWM_PIN_ID,PIN_OUTPUT);// Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC
	
	/* Configure timer control register 
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */ 
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01);
	TCCR0 |= (1<<CS01);
}

