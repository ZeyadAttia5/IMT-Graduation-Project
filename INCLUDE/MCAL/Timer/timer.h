/*
 * timer.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_H_
#define INCLUDE_MCAL_TIMER_TIMER_H_

//TIMSK
#define TOIE0	0		//Overflow Interrupt enable
#define OCIE0	1		//Output compare interrupt-enable
#define TOIE1	2
#define OCIE1A 	3
#define OCIE1B 	4
#define TICIE1 	5
#define TOIE2	6		//Overflow interrupt flag
#define OCIE2	7		//Output compare interrupt flag

//Special Function IO Register �SFIOR
#define PSR10	0		//when set -> reset prescalar for timers 1 & 0
#define PSR2	1		//when set -> reset prescalar for timer 2

//Timer/Counter Interrupt Flag Register -TIFR
#define TOV0	0
#define OCF0	1
#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5
#define TOV2	6
#define OCF2	7

//TCCR0 Register
#define CS00	0		//Clock Select
#define CS01	1		//Clock Select
#define CS02	2		//Clock Select
#define WGM01	3		//Waveform Generation Mode
#define COM00	4		//Compare Match Output Mode
#define COM01	5		//Compare Match Output Mode
#define WGM00	6		//Waveform Generation Mode
#define FOC0	7		//Force Output Compare

//Timer/Counter1 Control Register A � TCCR1A
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B 	2
#define WGM11	1
#define WGM10	0

//Some other Registers
#define OCR11	0
#define OCR12	1
#define ICR		2
//Timer/Counter1 Control Register B � TCCR1B
#define ICNC1	7
#define ICES1	6
//#define Res	5
#define WGM13 	4
#define WGM12 	3
#define CS12 	2
#define CS11 	1
#define CS10	0

//Timer/Counter 2 Control Register - TCCR2
#define CS20	0		//Clock Select
#define CS21	1		//Clock Select
#define CS22	2		//Clock Select
#define WGM21	3		//Waveform Generation Mode
#define COM20	4		//Compare Match Output Mode
#define COM21	5		//Compare Match Output Mode
#define WGM20	6		//Waveform Generation Mode
#define FOC2	7		//Force Output Compare

//Asynchronous Status Register - ASSR
#define AS2		0
#define TCN2UB	1
#define OCR2UB	2
#define TCR2UB	3

//BIT States & Channels
#define Disable		0
#define Enable		1
#define ChannelA	0
#define ChannelB	1

//Timer Select
#define Timer0	0
#define Timer1	1
#define Timer2	2

//Clock Select Modes Timer 0
#define Clock0_NoClock			0
#define Clock0_Prescaler0		1
#define Clock0_Prescaler8		2
#define Clock0_Prescaler64		3
#define Clock0_Prescaler256		4
#define Clock0_Prescaler1024	5
#define Clock0_EXTFallingEdge	6
#define Clock0_EXTRisingEdge	7

//Clock Select Modes Timer 1
#define Clock1_NoClock			0
#define Clock1_Prescaler0		1
#define Clock1_Prescaler8		2
#define Clock1_Prescaler64		3
#define Clock1_Prescaler256		4
#define Clock1_Prescaler1024	5
#define Clock1_EXTFallingEdge	6
#define Clock1_EXTRisingEdge	7

//Clock Select Modes Timer 2
#define Clock2_NoClock			0
#define Clock2_Prescaler0		1
#define Clock2_Prescaler8		2
#define Clock2_Prescaler32		3
#define Clock2_Prescaler64		4
#define Clock2_Prescaler128		5
#define Clock2_Prescaler256		6
#define Clock2_Prescaler1024	7

//Wave Form Generation Mode for timers 0 & 2
#define WGM_Normal			0
#define WGM_PhaseCorrect	1
#define WGM_CTC				2
#define WGM_FastPWM			3

//Timer 1 WGMs
#define Timer1_WGM_Normal16BitR				0  //Normal TCNT -> 16-bit Resolution (Count up to 2^16)
#define Timer1_WGM_PhaseCorrect8BitR		1  //PWM, Phase Correct, 8-bit Resolution
#define Timer1_WGM_PhaseCorrect9BitR		2  //PWM, Phase Correct, 9-bit
#define Timer1_WGM_PhaseCorrect10BitR		3  //PWM, Phase Correct, 10-bit
#define Timer1_WGM_ctcOCR1ATop				4  //CTC OCR1A has Max Value
#define Timer1_WGM_FastPWM8BitR				5  //Fast PWM, 8-bit
#define Timer1_WGM_FastPWM9BitR				6  //Fast PWM, 9-bit
#define Timer1_WGM_FastPWM10BitR			7  //Fast PWM, 10-bit
#define Timer1_WGM_PhFreqCorrectICR1Top	8  //PWM, Phase and Frequency Correct
#define Timer1_WGM_PhFreqCorrectOCR1ATop	9  //PWM, Phase and Frequency Correct
#define Timer1_WGM_PhaseCorrectICR1Top		10 //PWM, Phase Correct ICR1 has Max Value
#define Timer1_WGM_PhaseCorrectOCR1ATop		11 //PWM, Phase Correct OCR1A has Max Value
#define Timer1_WGM_ctcICR1Top				12 //CTC ICR1 has Max Value
//#define Timer1_WGM_Reserved				13 //Reserved
#define Timer1_WGM_FastPWMICR1Top			14 //Fast PWM ICR1 has Max Value
#define Timer1_WGM_FastPWMOCR1ATop			15 //Fast PWM OCR1A has Max Value

//Timer 1 Output on Compare Match (OCM)
#define OCM_NormalOC1			0
#define OCM_ToggleOC1			1
#define OCM_ClearOC1			2
#define OCM_SetOC1				3

#define PWM_OCM_NormalOC1				0
#define PWM_OCM_ToggleOC1A_NormalOC1B	1
#define PWM_OCM_ClrComSetTop			2
#define PWM_OCM_SetComClrTop			3

#define Phase_Freq_Correct_NormalOC1				0
#define Phase_Freq_Correct_ToggleOC1A_NormalOC1B	1
#define Phase_Freq_Correct_ClrComSetTop				2
#define Phase_Freq_Correct_SetComClrTop				3

//Output on Compare Match (OCM) NO PWM
#define OCM_DisconnectOC1			0		//Disconnect OC0 on compare Match
#define OCM_ToggleOC1				1		//Toggle OC0 on compare match
#define OCM_ClearOC1ComSetTop		2		//Clear OC0 on compare match
#define OCM_SetOC1ComClrTop			3		//Set OC0 on Compare match

//Output on Compare Match (OCM) NO PWM
#define OCM_DisconnectOC2		0		//Disconnect OC2 on compare Match
#define OCM_ToggleOC2			1		//Toggle OC2 on compare match
#define OCM_ClearOC1ComSetTop	2		//Clear OC2 on compare match
#define OCM_SetOC1ComClrTop		3		//Set OC2 on Compare match

//Output on Compare Match (OCM) Fast PWM
#define PWM_OCM_DisconnectOC0		0		//Disconnect OC0 on compare Match
//#define 							1		//Reserved
#define PWM_OCM_ClrComSetTop		2		//non Inverted
#define PWM_OCM_SetComClrTop		3		//Inverted

void Timer_voidPreloadValue(u8 Copy_u8TimerNo, u16 Copy_u16Value,
		u8 Copy_u8Timer1OCR1x);
void Timer_init(u8 Copy_u8TimerNo, u8 Copy_u8ClockSelect, u8 Copy_u8WGM,
		u8 Copy_u8OutputOnCompareMatch, u8 Timer1_OC2Mode);
void Timer_voidOCMInterrupt(u8 Copy_u8TimerNo, u8 state, u8 Copy_u8Timer1OCIEn);
void Timer_voidOverflowInterrupt(u8 Copy_u8TimerNo, u8 state);

#endif /* INCLUDE_MCAL_TIMER_TIMER_H_ */
