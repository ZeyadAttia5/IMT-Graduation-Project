/*
 * timer_prv.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_PRV_H_
#define INCLUDE_MCAL_TIMER_TIMER_PRV_H_

#define TIMSK	*((volatile u8 *) 0x59)	//Timer/Counter Interrupt Mask Register
#define TIFR	*((volatile u8 *) 0x58)
#define SFIOR	*((volatile u8 *) 0x50)

#define TCCR0	*((volatile u8 *) 0x53)
#define TCNT0	*((volatile u8 *) 0x52)
#define OCR0	*((volatile u8 *) 0x5C)

#define TCCR1A 	*((volatile u8 *) 0x4F)
#define TCCR1B 	*((volatile u8 *) 0x4E)
#define TCNT1H 	*((volatile u8 *) 0x4D)	//Counter Register TCNT1
#define TCNT1L 	*((volatile u8 *) 0x4C)
#define OCR1AH 	*((volatile u8 *) 0x4B)	//Output Compare Register OCR1
#define OCR1AL 	*((volatile u8 *) 0x4A)
#define OCR1BH 	*((volatile u8 *) 0x49)
#define OCR1BL 	*((volatile u8 *) 0x48)
#define ICR1L 	*((volatile u8 *) 0x46)	//Input-capture Register ICR1
#define ICR1H 	*((volatile u8 *) 0x47)
#define ICR1 	*((volatile u16 *) 0x46)
#define OCR1A	*((volatile u16 *) 0x4A)
#define OCR1B 	*((volatile u16 *) 0x48)

#define TCCR2 	*((volatile u8 *) 0x45)
#define TCNT2 	*((volatile u8 *) 0x44)
#define OCR2 	*((volatile u8 *) 0x43)
#define ASSR 	*((volatile u8 *) 0x42)

//Timer 1 WGM Macro
#define implement_Timer1_WGM_Normal16BitR			CLR_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //0
#define implement_Timer1_WGM_PhaseCorrect8BitR		CLR_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //1
#define implement_Timer1_WGM_PhaseCorrect9BitR		CLR_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //2
#define implement_Timer1_WGM_PhaseCorrect10BitR		CLR_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //3
#define implement_Timer1_WGM_CTC					CLR_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //4
#define implement_Timer1_WGM_FastPWM8BitR			CLR_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //5
#define implement_Timer1_WGM_FastPWM9BitR			CLR_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //6
#define implement_Timer1_WGM_FastPWM10BitR			CLR_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //7
#define implement_Timer1_WGM_PhFreqCorrectICR1Top	SET_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //8
#define implement_Timer1_WGM_PhFreqCorrectOCR1ATop	SET_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //9
#define implement_Timer1_WGM_PhaseCorrectICR1Top	SET_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //10
#define implement_Timer1_WGM_PhaseCorrectOCR1ATop	SET_BIT(TCCR1B,4); CLR_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //11
#define implement_Timer1_WGM_ctcICR1Top				SET_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //12
//#define implement_Timer1_WGM_Reserved				SET_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); CLR_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //13
#define implement_Timer1_WGM_FastPWMICR1Top			SET_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); CLR_BIT(TCCR1A,0) //14
#define implement_Timer1_WGM_FastPWMOCR1ATop		SET_BIT(TCCR1B,4); SET_BIT(TCCR1B,3); SET_BIT(TCCR1A,1); SET_BIT(TCCR1A,0) //15

#endif /* INCLUDE_MCAL_TIMER_TIMER_PRV_H_ */
