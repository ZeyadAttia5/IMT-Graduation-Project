/*
 * ADC.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_ADC_ADC_H_
#define INCLUDE_MCAL_ADC_ADC_H_
#include "../../../SERVICES/BIT_UTILIS.h"
#include "../../../SERVICES/STD_TYPES.h"

#include "./ADC_cfg.h"

#define ADC_PIN0 0
#define ADC_PIN1 1
#define ADC_PIN2 2
#define ADC_PIN3 3
#define ADC_PIN4 4
#define ADC_PIN5 5
#define ADC_PIN6 6
#define ADC_PIN7 7

#define ADC_Enable				1 			//ADEN in ADCSRA
#define ADC_Disable				0 			//ADEN in ADCSRA
#define ADC_Start_Conversion	0			//Write a logical 1 to start conversion. stays high as long as a conversion is taking place
#define ADC_Interrupt_Enable	1			//ADIE in ADCSRA
#define ADC_Right_Adjustment	0
#define ADC_Left_Adjustment		1

//******ADCSRA BITS*******//
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

//******ADC Voltage Reference******// 	//Bits 6 and 7 in ADMUX  	//needs to be in INIT
#define REFS1 7
#define REFS0 6

#define ADC_Voltage_Reference_AREF				 0b00
#define ADC_Voltage_Reference_External_Capacitor 0b01
// #define ADC_Voltage_Reference_Reserved 0b10
#define ADC_Voltage_Reference_Internal			 0b11

//******ADC Adjust Result******//
#define ADC_Left_Adjust_Result 1 		//ADLAR Bit 5 in ADMUX

//******ADC Analog Channel and Gain Selection******//
//No input differential
#define ADC_Channel_0 0b00000
#define ADC_Channel_1 0b00001
#define ADC_Channel_2 0b00010
#define ADC_Channel_3 0b00011
#define ADC_Channel_4 0b00100
#define ADC_Channel_5 0b00101
#define ADC_Channel_6 0b00110
#define ADC_Channel_7 0b00111

#define ADC_Channel_0_10x_Gain 0b01000
#define ADC_Channel_1_Channel_0_10x_Gain 0b01001
#define ADC_Channel_0_200x_Gain 0b01010
#define ADC_Channel_1_Channel_0_200x_Gain 0b01011
#define ADC_Channel_1_10x_Gain 0b01100
#define ADC_Channel_3_Channel_2_10x_Gain 0b01101
#define ADC_Channel_2_200x_Gain 0b01110
#define ADC_Channel_3_Channel_2_200x_Gain 0b01111
//1x gain with channel 1
#define ADC_Channel_0_Channel_1_1x_Gain 0b10000
#define ADC_Channel_1_1x_Gain 0b10001
#define ADC_Channel_2_Channel_1_1x_Gain 0b10010
#define ADC_Channel_3_Channel_1_1x_Gain 0b10011
#define ADC_Channel_4_Channel_1_1x_Gain 0b10100
#define ADC_Channel_5_Channel_1_1x_Gain 0b10101
#define ADC_Channel_6_Channel_1_1x_Gain 0b10110
#define ADC_Channel_7_Channel_1_1x_Gain 0b10111
//1x gain with channel 2
#define ADC_Channel_0_Channel_2_1x_Gain 0b11000
#define ADC_Channel_1_Channel_2_1x_Gain 0b11001
#define ADC_Channel_2_1x_Gain 0b11010
#define ADC_Channel_3_Channel_2_1x_Gain 0b11011
#define ADC_Channel_4_Channel_2_1x_Gain 0b11100
#define ADC_Channel_5_Channel_2_1x_Gain 0b11101

//******ADC Prescaler Select Bits******//

#define ADC_Prescaler_Factor_2 0b000
#define ADC_Prescaler_Factor_4 0b010
#define ADC_Prescaler_Factor_8 0b011
#define ADC_Prescaler_Factor_16 0b100
#define ADC_Prescaler_Factor_32 0b101
#define ADC_Prescaler_Factor_64 0b110
#define ADC_Prescaler_Factor_128 0b111

//******ADC Auto Trigger Source Selections******//
#define ADATE 5 //Auto Trigger enable bit in ADCSAR

#define ADC_Auto_Trigger_Enable  1
#define ADC_Single_Conversion 0

#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#define ADC_FreeRunning 0b000
#define ADC_AnalogComparator 0b001
#define ADC_External_Interrupt_Request_0 0b010
#define ADC_Timer0_Compare_Match 0b011
#define ADC_Timer0_Overflow 0b100
#define ADC_Timer0_Compare_MatchB 0b101
#define ADC_Timer1_Overflow 0b110
#define ADC_Timer1_Capture_Event 0b111

//***************************************************//

void ADC_voidInit(void);
void ADC_voidDisable(void);
u16 ADC_Read(void);
#endif /* INCLUDE_MCAL_ADC_ADC_H_ */
