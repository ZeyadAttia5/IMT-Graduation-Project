/*
 * LCD.c
 *
 *  Created on: Sep 9, 2022
 *      Author: Administrator
 */

#include "util/delay.h"

#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include "../../../INCLUDE/HAL/LCD/LCD.h"
#include "../../../INCLUDE/HAL/LCD/LCD_cfg.h"
#undef F_CPU
#define F_CPU 8000000

LCD_tenuErrorStatus LCD_vidInit(LCD_tLCD copy_tLCD) {
	u8 LOC_u8ErrorStatus = LCD_enuOk;

	if (copy_tLCD.DataPort >= DIO_u8_PORTA && copy_tLCD.DataPort <= DIO_u8_PORTD) {
		DIO_enuSetPortDirection(copy_tLCD.DataPort, DIO_u8_PORT_OUTPUT);
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;
	if (copy_tLCD.CfgPort >= DIO_u8_PORTA && copy_tLCD.CfgPort <= DIO_u8_PORTD) {

		if (copy_tLCD.RSPin >= DIO_u8_PIN0 && copy_tLCD.RSPin <= DIO_u8_PIN7)
			DIO_enuSetPinDirection(copy_tLCD.CfgPort, copy_tLCD.RSPin,
			DIO_u8_OUTPUT);
		else
			LOC_u8ErrorStatus = LCD_invalidInput;

		if (copy_tLCD.RWPin >= DIO_u8_PIN0 && copy_tLCD.RWPin <= DIO_u8_PIN7)
			DIO_enuSetPinDirection(copy_tLCD.CfgPort, copy_tLCD.RWPin,
			DIO_u8_OUTPUT);
		else
			LOC_u8ErrorStatus = LCD_invalidInput;

		if (copy_tLCD.ENPin >= DIO_u8_PIN0 && copy_tLCD.ENPin <= DIO_u8_PIN7)
			DIO_enuSetPinDirection(copy_tLCD.CfgPort, copy_tLCD.ENPin,
			DIO_u8_OUTPUT);
		else
			LOC_u8ErrorStatus = LCD_invalidInput;
		_delay_ms(40);
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;

	LCD_vidSendCommand(LCD_FunctionSetTwoLineMinPower, copy_tLCD); //function set
	_delay_ms(2);
	LCD_vidSendCommand(LCD_DisplayOn, copy_tLCD); //display on/off control
	_delay_ms(2);
	LCD_vidSendCommand(LCD_ClrDisplay, copy_tLCD); //clear display
	_delay_ms(2);
	LCD_vidSendCommand(0b00000110, copy_tLCD); //entry mode set
	_delay_ms(2);

	LCD_vidPulseEnable(copy_tLCD.ENPin, copy_tLCD.CfgPort);

	return LOC_u8ErrorStatus;

}

LCD_tenuErrorStatus LCD_vidSendChar(u8 LCD_u8Char, LCD_tLCD copy_tLCD) {

	u8 LOC_u8ErrorStatus = LCD_enuOk;

	if ((copy_tLCD.ENPin >= DIO_u8_PIN0 && copy_tLCD.ENPin <= DIO_u8_PIN7)
			&& (copy_tLCD.CfgPort >= DIO_u8_PORTA
					&& copy_tLCD.CfgPort <= DIO_u8_PORTD)) {
		DIO_enuSetPinValue(copy_tLCD.CfgPort, copy_tLCD.RSPin, LCD_RS_SendData); // RS = 1
		DIO_enuSetPinValue(copy_tLCD.CfgPort, copy_tLCD.RWPin, LCD_RW_Write); // RW = 0
		DIO_enuSetPortValue(copy_tLCD.DataPort, LCD_u8Char);
		LCD_vidPulseEnable(copy_tLCD.ENPin, copy_tLCD.CfgPort);
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;

	return LOC_u8ErrorStatus;
}

LCD_tenuErrorStatus LCD_vidSendString(u8 *LCD_u8CharArr, LCD_tLCD copy_tLCD) {
	u8 LOC_u8ErrorStatus = LCD_enuOk;

	if ((copy_tLCD.ENPin >= DIO_u8_PIN0 && copy_tLCD.ENPin <= DIO_u8_PIN7)
			&& (copy_tLCD.CfgPort >= DIO_u8_PORTA
					&& copy_tLCD.CfgPort <= DIO_u8_PORTD)) {
		while (*LCD_u8CharArr != '\0') {
			LCD_vidSendChar(*LCD_u8CharArr, copy_tLCD);
			LCD_u8CharArr++;
		}
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;
	return LOC_u8ErrorStatus;
}

LCD_tenuErrorStatus LCD_vidSendCommand(u8 LCD_u8Command, LCD_tLCD copy_tLCD) {

	u8 LOC_u8ErrorStatus = LCD_enuOk;
	if ((copy_tLCD.ENPin >= DIO_u8_PIN0 && copy_tLCD.ENPin <= DIO_u8_PIN7)
			&& (copy_tLCD.CfgPort >= DIO_u8_PORTA
					&& copy_tLCD.CfgPort <= DIO_u8_PORTD)) {
		DIO_enuSetPinValue(copy_tLCD.CfgPort, copy_tLCD.RSPin,
		LCD_RS_Configure); // RS = 0
		DIO_enuSetPinValue(copy_tLCD.CfgPort, copy_tLCD.RWPin, LCD_RW_Write); // RW = 0
		DIO_enuSetPortValue(copy_tLCD.DataPort, LCD_u8Command);     // send data
		LCD_vidPulseEnable(copy_tLCD.ENPin, copy_tLCD.CfgPort);
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;
	return LOC_u8ErrorStatus;

}

LCD_tenuErrorStatus LCD_vidSendDigit(u8 digit, LCD_tLCD copy_tLCD) {
	u8 LOC_u8ErrorStatus = LCD_enuOk;
	if ((copy_tLCD.ENPin >= DIO_u8_PIN0 && copy_tLCD.ENPin <= DIO_u8_PIN7)
			&& (copy_tLCD.CfgPort >= DIO_u8_PORTA
					&& copy_tLCD.CfgPort <= DIO_u8_PORTD)) {
		LCD_vidSendChar((char) digit + 48, copy_tLCD);
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;
	return LOC_u8ErrorStatus;

}

LCD_tenuErrorStatus LCD_vidMoveCursor(u8 LCD_u8Line, u8 LCD_u8Index,
		LCD_tLCD copy_tLCD) {
	u8 LOC_u8ErrorStatus = LCD_enuOk;

	if ((copy_tLCD.ENPin >= DIO_u8_PIN0 && copy_tLCD.ENPin <= DIO_u8_PIN7)
			&& (copy_tLCD.CfgPort >= DIO_u8_PORTA
					&& copy_tLCD.CfgPort <= DIO_u8_PORTD)) {
		switch (LCD_u8Line) {
		case 0:
			LCD_vidSendCommand(LCD_DDRAM_DEFAULT_ADDRESS + LCD_u8Index,
					copy_tLCD);
			break;
		case 1:
			LCD_vidSendCommand(LCD_DDRAM_DEFAULT_ADDRESS + 0x40 + LCD_u8Index,
					copy_tLCD);
			break;
		default:
			LOC_u8ErrorStatus = LCD_invalidInput;
			break; //do nothing
		}
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;

	return LOC_u8ErrorStatus;
}

LCD_tenuErrorStatus LCD_vidSendNumber(u16 Copy_u16Number, LCD_tLCD copy_tLCD) {
	u8 LOC_u8ErrorStatus = LCD_enuOk;

	//if pin is invalid OR port is invalid, just return;
	if (!(copy_tLCD.ENPin >= DIO_u8_PIN0 && copy_tLCD.ENPin <= DIO_u8_PIN7)
			|| !(copy_tLCD.CfgPort >= DIO_u8_PORTA
					&& copy_tLCD.CfgPort <= DIO_u8_PORTD)) {
		LOC_u8ErrorStatus = LCD_invalidInput;
		return LOC_u8ErrorStatus; //There is no need to continue with the function past this point: waste of time, memory and potential malicious use
	} else {
		u16 LOC_u16Digit = 0;
		u8 add_Zero = 0;
		while (Copy_u16Number > 0) {
			if (Copy_u16Number % 10 == 0 && LOC_u16Digit == 0) {
				add_Zero = 1;
			}
			LOC_u16Digit = LOC_u16Digit * 10 + (Copy_u16Number % 10);
			Copy_u16Number /= 10;
		}
		while (LOC_u16Digit > 0) {
			u8 LOC_u8Digit = LOC_u16Digit % 10;
			LCD_vidSendDigit(LOC_u8Digit, copy_tLCD);
			LOC_u16Digit /= 10;
		}
		if (add_Zero)
			LCD_vidSendDigit(0, copy_tLCD);
		return LOC_u8ErrorStatus;
	}

}

LCD_tenuErrorStatus LCD_vidPulseEnable(u8 LCD_u8ENPin, u8 copy_u8CfgPort) {
	u8 LOC_u8ErrorStatus = LCD_enuOk;
	if (LCD_u8ENPin >= DIO_u8_PIN0 && LCD_u8ENPin <= DIO_u8_PIN7) {
		if (copy_u8CfgPort >= DIO_u8_PORTA && copy_u8CfgPort <= DIO_u8_PORTD) {
			DIO_enuSetPinValue(copy_u8CfgPort, LCD_u8ENPin, LCD_Enable_On);
			_delay_ms(2);
			DIO_enuSetPinValue(copy_u8CfgPort, LCD_u8ENPin, LCD_Enable_Off);
		} else
			LOC_u8ErrorStatus = LCD_invalidInput;
	} else
		LOC_u8ErrorStatus = LCD_invalidInput;
	return LOC_u8ErrorStatus;
}
