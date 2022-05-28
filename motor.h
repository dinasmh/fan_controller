/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: motor.c
 *
 * Description: header file for the DC motor driver
 *
 * Author: Dina Atef
 *
 *******************************************************************************/


#ifndef MOTOR_H_
#define MOTOR_H_

#include"std_types.h"
#include "PWM.h"


#define MOTOR_PORT_ID PORTB_ID
#define IN1_ID PIN0_ID
#define IN2_ID PIN1_ID
#define EN_ID PIN2_ID

typedef enum {Stop,CW, ACW}DcMotor_state;
/*
 * Description :
 * Function of motor initialisation.
 */
void motor_init(void);
/*
 * Description :
 * Function of motor rotation.
 */
void DcMotor_Rotate(DcMotor_state, uint8);

#endif /* MOTOR_H_ */
