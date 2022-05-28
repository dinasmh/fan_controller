 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Dina Atef
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE 2.56

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(ADC_ConfigType);

typedef enum{no_prescaler=0 , F_2 ,F_4 ,F_8 ,F_16,F_32,F_64,F_128}ADC_PRESCALER;
typedef enum{AREF=0,AVCC=1,internal=3}ADC_REF_VALUE;

typedef struct{
	ADC_REF_VALUE ref_value;
	ADC_PRESCALER prescaler;
}ADC_ConfigType;


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
