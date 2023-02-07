/*
 * ADC_prv.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRV_H_
#define INCLUDE_MCAL_ADC_ADC_PRV_H_

#define ADCSRA *((volatile u8*) 0x26)
#define ADMUX  *((volatile u8*) 0x27)
#define SFIOR  *((volatile u8*) 0x50)
#define ADCL  *((volatile u8*) 0x24)
#define ADCH  *((volatile u8*) 0x25)

#endif /* INCLUDE_MCAL_ADC_ADC_PRV_H_ */
