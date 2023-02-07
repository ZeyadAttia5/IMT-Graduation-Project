#include "../../../INCLUDE/MCAL/ADC/ADC.h"
#include "../../../INCLUDE/MCAL/ADC/ADC_prv.h"
#include "../../../INCLUDE/MCAL/ADC/ADC_cfg.h"
#include "../../../SERVICES/BIT_UTILIS.h"
#include "../../../SERVICES/STD_TYPES.h"

u16 ADC_Read(void) {

	u16 LOC_Result = 0;

	SET_BIT(ADCSRA, ADSC);
	while (GET_BIT(ADCSRA, ADIF) == 0)
		;
#if ADC_Adjustment == ADC_Left_Adjustment
	LOC_Result = ADCH;
	#elif ADC_Adjustment == ADC_Right_Adjustment
	LOC_Result = ADCL | (ADCH << 8);
#endif
	return LOC_Result;
}

void ADC_voidInit(void) {
	SET_BIT(ADCSRA, ADEN);
	SET_BIT(ADCSRA, ADIE);

#if ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_0
	ASSIGN_REG(ADMUX, ADC_Channel_0);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_0_10x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_0_10x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_0_200x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_0_200x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_0_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_0_Channel_1_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_0_Channel_2_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_0_Channel_2_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_1
	ASSIGN_REG(ADMUX, ADC_Channel_1);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_1_10x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_1_10x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_1_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_1_Channel_0_10x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_1_Channel_0_10x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_1_Channel_0_200x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_1_Channel_0_200x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_1_Channel_2_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_1_Channel_2_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_2
	ASSIGN_REG(ADMUX, ADC_Channel_2);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_2_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_2_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_2_200x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_2_200x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_2_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_2_Channel_1_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_3_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_3_Channel_1_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_3_Channel_2_10x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_3_Channel_2_10x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_3_Channel_2_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_3_Channel_2_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_3_Channel_2_200x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_3_Channel_2_200x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_4
	ASSIGN_REG(ADMUX, ADC_Channel_4);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_4_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_4_Channel_1_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_4_Channel_2_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_4_Channel_2_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_5_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_5_Channel_1_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_5_Channel_2_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_5_Channel_2_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_6
	ASSIGN_REG(ADMUX, ADC_Channel_6);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_6_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_6_Channel_1_1x_Gain);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_7
	ASSIGN_REG(ADMUX, ADC_Channel_7);
#elif ADC_Analog_Channel_and_Gain_Selection == ADC_Channel_7_Channel_1_1x_Gain
	ASSIGN_REG(ADMUX, ADC_Channel_7_Channel_1_1x_Gain);
#endif

#if ADC_Voltage_Reference == ADC_Voltage_Reference_External_Capacitor
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);

#elif ADC_Voltage_Reference == ADC_Voltage_Reference_AREF
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, REFS0);

#elif ADC_Voltage_Reference == ADC_Voltage_Reference_Internal
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);

#endif

#if ADC_AUTO_TRIGGER == ADC_Single_Conversion
	CLR_BIT(ADCSRA, ADATE);
#elif ADC_AUTO_TRIGGER == ADC_Auto_Trigger_Enable
	SET_BIT(ADCSRA,ADATE);
#if ADC_Auto_Trigger_Source_Selection == ADC_FreeRunning
	CLR_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif ADC_Auto_Trigger_Source_Selection == ADC_AnalogComparator
	CLR_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS0);
#elif ADC_Auto_Trigger_Source_Selection == ADC_External_Interrupt_Request_0
	CLR_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif ADC_Auto_Trigger_Source_Selection == ADC_Timer0_Compare_Match
	CLR_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS0);
#elif ADC_Auto_Trigger_Source_Selection == ADC_Timer0_Overflow
	SET_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif ADC_Auto_Trigger_Source_Selection == ADC_Timer0_Compare_MatchB
	SET_BIT(SFIOR,ADTS2);
	CLR_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS0);
#elif ADC_Auto_Trigger_Source_Selection == ADC_Timer1_Overflow
	SET_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	CLR_BIT(SFIOR,ADTS0);
#elif ADC_Auto_Trigger_Source_Selection == ADC_Timer1_Capture_Event
	SET_BIT(SFIOR,ADTS2);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS0);
#endif
#endif

#if ADC_Prescaler_Factor >= ADC_Prescaler_Factor_2 && ADC_Prescaler_Factor <= ADC_Prescaler_Factor_128
	ADCSRA |= ADC_Prescaler_Factor;
#else
	#warning"wrong Prescaler"
#endif

}

void ADC_voidDisable(void) {
	CLR_BIT(ADCSRA, ADEN);
}
