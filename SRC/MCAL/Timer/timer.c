/*
 * timer.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Administrator
 */

#include "../../../SERVICES/BIT_UTILIS.h"
#include "../../../SERVICES/STD_TYPES.h"
#include "../../../INCLUDE/MCAL/Timer/timer.h"
#include "../../../INCLUDE/MCAL/Timer/timer_prv.h"

void Timer_init(u8 Copy_u8TimerNo, u8 Copy_u8ClockSelect, u8 Copy_u8WGM,
		u8 Copy_u8OutputOnCompareMatch, u8 Copy_u8Timer1_OC2Mode) {

	switch (Copy_u8TimerNo) {
	case Timer0:
		switch (Copy_u8ClockSelect) {
		case Clock0_NoClock:
			CLR_BIT(TCCR0, CS00);
			CLR_BIT(TCCR0, CS01);
			CLR_BIT(TCCR0, CS02);
			break;
		case Clock0_Prescaler0:
			SET_BIT(TCCR0, CS00);
			CLR_BIT(TCCR0, CS00);
			CLR_BIT(TCCR0, CS00);
			break;
		case Clock0_Prescaler8:
			CLR_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLR_BIT(TCCR0, CS02);
			break;
		case Clock0_Prescaler64:
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLR_BIT(TCCR0, CS02);
			break;
		case Clock0_Prescaler256:
			CLR_BIT(TCCR0, CS00);
			CLR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		case Clock0_Prescaler1024:
			SET_BIT(TCCR0, CS00);
			CLR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		case Clock0_EXTFallingEdge:
			CLR_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		case Clock0_EXTRisingEdge:
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		}
		switch (Copy_u8WGM) {
		case WGM_Normal:
			CLR_BIT(TCCR0, WGM00);
			CLR_BIT(TCCR0, WGM01);
			break;
		case WGM_PhaseCorrect:
			SET_BIT(TCCR0, WGM00);
			CLR_BIT(TCCR0, WGM01);
			break;
		case WGM_CTC:
			CLR_BIT(TCCR0, WGM00);
			SET_BIT(TCCR0, WGM01);
			break;
		case WGM_FastPWM:
			SET_BIT(TCCR0, WGM00);
			SET_BIT(TCCR0, WGM01);
			break;
		}
		switch (Copy_u8OutputOnCompareMatch) {
		case OCM_DisconnectOC1:
			CLR_BIT(TCCR0, COM00);
			CLR_BIT(TCCR0, COM01);
			break;
		case OCM_ToggleOC1:
			if (Copy_u8WGM != WGM_FastPWM && Copy_u8WGM != WGM_PhaseCorrect) {
				SET_BIT(TCCR0, COM00);CLR_BIT(TCCR0, COM01);
			}
			break;
		case OCM_ClearOC1:
			CLR_BIT(TCCR0, COM00);
			SET_BIT(TCCR0, COM01);
			break;
		case OCM_SetOC1:
			SET_BIT(TCCR0, COM00);
			SET_BIT(TCCR0, COM01);
			break;
		}
		break;

		//TIMER 1
	case Timer1:
		switch (Copy_u8ClockSelect) {
		case Clock1_NoClock:
			CLR_BIT(TCCR1B, CS10);
			CLR_BIT(TCCR1B, CS11);
			CLR_BIT(TCCR1B, CS12);
			break;
		case Clock1_Prescaler0:
			SET_BIT(TCCR1B, CS10);
			CLR_BIT(TCCR1B, CS11);
			CLR_BIT(TCCR1B, CS12);
			break;
		case Clock1_Prescaler8:
			CLR_BIT(TCCR1B, CS10);
			SET_BIT(TCCR1B, CS11);
			CLR_BIT(TCCR1B, CS12);
			break;
		case Clock1_Prescaler64:
			SET_BIT(TCCR1B, CS10);
			SET_BIT(TCCR1B, CS11);
			CLR_BIT(TCCR1B, CS12);
			break;
		case Clock1_Prescaler256:
			CLR_BIT(TCCR1B, CS10);
			CLR_BIT(TCCR1B, CS11);
			SET_BIT(TCCR1B, CS12);
			break;
		case Clock1_Prescaler1024:
			SET_BIT(TCCR1B, CS10);
			CLR_BIT(TCCR1B, CS11);
			SET_BIT(TCCR1B, CS12);
			break;
		case Clock1_EXTFallingEdge:
			CLR_BIT(TCCR1B, CS10);
			SET_BIT(TCCR1B, CS11);
			SET_BIT(TCCR1B, CS12);
			break;
		case Clock1_EXTRisingEdge:
			SET_BIT(TCCR1B, CS10);
			SET_BIT(TCCR1B, CS11);
			SET_BIT(TCCR1B, CS12);
			break;
		}

		switch (Copy_u8WGM) {
		case Timer1_WGM_Normal16BitR:
			implement_Timer1_WGM_Normal16BitR
			;
			break;
		case Timer1_WGM_PhaseCorrect8BitR:
			implement_Timer1_WGM_PhaseCorrect8BitR
			;
			break;
		case Timer1_WGM_PhaseCorrect9BitR:
			implement_Timer1_WGM_FastPWM9BitR
			;
			break;
		case Timer1_WGM_PhaseCorrect10BitR:
			implement_Timer1_WGM_PhaseCorrect10BitR
			;
			break;
		case Timer1_WGM_ctcOCR1ATop:
			implement_Timer1_WGM_CTC
			;
			break;
		case Timer1_WGM_FastPWM8BitR:
			implement_Timer1_WGM_FastPWM8BitR
			;
			break;
		case Timer1_WGM_FastPWM9BitR:
			implement_Timer1_WGM_FastPWM9BitR
			;
			break;
		case Timer1_WGM_FastPWM10BitR:
			implement_Timer1_WGM_FastPWM10BitR
			;
			break;
		case Timer1_WGM_PhFreqCorrectICR1Top:
			implement_Timer1_WGM_PhFreqCorrectICR1Top
			;
			break;
		case Timer1_WGM_PhFreqCorrectOCR1ATop:
			implement_Timer1_WGM_PhFreqCorrectOCR1ATop
			;
			break;
		case Timer1_WGM_PhaseCorrectICR1Top:
			implement_Timer1_WGM_PhaseCorrectICR1Top
			;
			break;
		case Timer1_WGM_PhaseCorrectOCR1ATop:
			implement_Timer1_WGM_PhaseCorrectOCR1ATop
			;
			break;
		case Timer1_WGM_ctcICR1Top:
			implement_Timer1_WGM_ctcICR1Top
			;
			break;
		case Timer1_WGM_FastPWMICR1Top:
			implement_Timer1_WGM_FastPWMICR1Top
			;
			break;
		case Timer1_WGM_FastPWMOCR1ATop:
			implement_Timer1_WGM_FastPWMOCR1ATop
			;
			break;
		}

		switch (Copy_u8OutputOnCompareMatch) {
		case OCM_DisconnectOC1:
			CLR_BIT(TCCR1A, COM1A0);
			CLR_BIT(TCCR1A, COM1A1);
			break;
		case OCM_ToggleOC1:
			if (Copy_u8WGM != WGM_FastPWM && Copy_u8WGM != WGM_PhaseCorrect) {
				SET_BIT(TCCR1A, COM1A0);CLR_BIT(TCCR1A, COM1A1);
			}
			break;
		case OCM_ClearOC1ComSetTop:
			CLR_BIT(TCCR1A, COM1A0);
			SET_BIT(TCCR1A, COM1A1);
			break;
		case OCM_SetOC1ComClrTop:
			SET_BIT(TCCR1A, COM1A0);
			SET_BIT(TCCR1A, COM1A1);
			break;
		}

		switch (Copy_u8Timer1_OC2Mode) {
		case OCM_DisconnectOC1:
			CLR_BIT(TCCR1A, COM1B0);
			CLR_BIT(TCCR1A, COM1B1);
			break;
		case OCM_ToggleOC1:
			if (Copy_u8WGM != WGM_FastPWM && Copy_u8WGM != WGM_PhaseCorrect) {
				SET_BIT(TCCR1A, COM1B0);CLR_BIT(TCCR1A, COM1B1);
			}
			break;
		case OCM_ClearOC1ComSetTop:
			CLR_BIT(TCCR1A, COM1B0);
			SET_BIT(TCCR1A, COM1B1);
			break;
		case OCM_SetOC1ComClrTop:
			SET_BIT(TCCR1A, COM1B0);
			SET_BIT(TCCR1A, COM1B1);
			break;
		}
		break;

	case Timer2:
		switch (Copy_u8ClockSelect) {
		case Clock2_NoClock:
			CLR_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS21);
			CLR_BIT(TCCR2, CS22);
			break;
		case Clock2_Prescaler0:
			SET_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS20);
			break;
		case Clock2_Prescaler8:
			CLR_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			CLR_BIT(TCCR2, CS22);
			break;
		case Clock2_Prescaler32:
			SET_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			CLR_BIT(TCCR2, CS22);
			break;
		case Clock2_Prescaler64:
			CLR_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
		case Clock2_Prescaler128:
			SET_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
		case Clock2_Prescaler256:
			CLR_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
		case Clock2_Prescaler1024:
			SET_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
		}
		switch (Copy_u8WGM) {
		case WGM_Normal:
			CLR_BIT(TCCR2, WGM20);
			CLR_BIT(TCCR2, WGM21);
			break;
		case WGM_PhaseCorrect:
			SET_BIT(TCCR2, WGM20);
			CLR_BIT(TCCR2, WGM21);
			break;
		case WGM_CTC:
			CLR_BIT(TCCR2, WGM20);
			SET_BIT(TCCR2, WGM21);
			break;
		case WGM_FastPWM:
			SET_BIT(TCCR2, WGM20);
			SET_BIT(TCCR2, WGM21);
			break;
		}
		switch (Copy_u8OutputOnCompareMatch) {
		case OCM_DisconnectOC2:
			CLR_BIT(TCCR2, COM20);
			CLR_BIT(TCCR2, COM21);
			break;
		case OCM_ToggleOC2:
			if (Copy_u8WGM != WGM_FastPWM && Copy_u8WGM != WGM_PhaseCorrect) {
				SET_BIT(TCCR2, COM20);CLR_BIT(TCCR2, COM21);
			}
			break;
		case OCM_ClearOC1ComSetTop:
			CLR_BIT(TCCR2, COM20);
			SET_BIT(TCCR2, COM21);
			break;
		case OCM_SetOC1ComClrTop:
			SET_BIT(TCCR2, COM20);
			SET_BIT(TCCR2, COM21);
			break;
		}
		break;
	default:
		break;
	}

}

void Timer_voidOCMInterrupt(u8 Copy_u8TimerNo, u8 state, u8 Copy_u8Timer1OCIEn) {

	switch (Copy_u8TimerNo) {
	case Timer0:
		switch (state) {
		case Enable:
			SET_BIT(TIMSK, OCIE0);
			break;
		case Disable:
			CLR_BIT(TIMSK, OCIE0);
			break;
		}
		break;

	case Timer1:
		switch (Copy_u8Timer1OCIEn) {
		case OCIE1A:
			switch (state) {
			case Enable:
				SET_BIT(TIMSK, OCIE1A);
				break;
			default:
				CLR_BIT(TIMSK, OCIE1A);
				break;
			}
			break;

		case OCIE1B:
			switch (state) {
			case Enable:
				SET_BIT(TIMSK, OCIE1B);
				break;
			default:
				CLR_BIT(TIMSK, OCIE1B);
				break;
				break;
			}

			break;
		}
		break;

	case Timer2:
		switch (state) {
		case Enable:
			SET_BIT(TIMSK, OCIE2);
			break;
		case Disable:
			CLR_BIT(TIMSK, OCIE2);
			break;
		}
		break;
	}
}

void Timer_voidOverflowInterrupt(u8 Copy_u8TimerNo, u8 state) {

	switch (Copy_u8TimerNo) {
	case Timer0:
		switch (state) {
		case Enable:
			SET_BIT(TIMSK, TOIE0);
			break;
		case Disable:
			CLR_BIT(TIMSK, TOIE0);
			break;
		}
		break;

	case Timer1:
		switch (state) {
		case Enable:
			SET_BIT(TIMSK, TOIE1);
			break;
		default:
			CLR_BIT(TIMSK, TOIE1);
			break;
		}
		break;

	case Timer2:
		switch (state) {
		case Enable:
			SET_BIT(TIMSK, TOIE2);
			break;
		case Disable:
			CLR_BIT(TIMSK, TOIE2);
			break;
		}
		break;
	}

}

void Timer_voidPreloadValue(u8 Copy_u8TimerNo, u16 Copy_u16Value,
		u8 Copy_u8Timer1OCR1x) {
	switch (Copy_u8TimerNo) {
	case Timer0:
		ASSIGN_REG(OCR0, (u8 )Copy_u16Value);
		break;
	case Timer1:
		switch (Copy_u8Timer1OCR1x) {
		case OCR11:
			OCR1A = Copy_u16Value;
			break;
		case OCR12:
			OCR1B = Copy_u16Value;
			break;
		case ICR:
			ICR1 = Copy_u16Value;
			break;
		}
		break;

	case Timer2:
		ASSIGN_REG(OCR2, (u8 )Copy_u16Value);
		break;
	}
}

/*
 void Timer2_voidAsynchronous(u8 Copy_u8State){
 switch(Copy_u8State){
 case Disable:
 CLR_BIT(ASSR,AS2);
 break;
 }
 case Enable:
 CLR_BIT(TIMSK,OCIE2);
 CLR_BIT(TIMSK,TOIE2);
 SET_BIT(ASSR, AS2);
 //code need to be added here
 }*/
