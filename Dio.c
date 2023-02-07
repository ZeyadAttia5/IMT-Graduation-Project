/*
 * Dio.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Administrator
 */
#include "Dio.h"
#include "Dio_prv.h"
#include "BIT_UTILIS.h"
#include "STD_TYPES.h"

DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinVal) {

	DIO_tenuErrorStatus LOC_enuErrorStatus = DIO_enuOk;

	if ((Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PortId >= DIO_u8_PORTA)
			&& (Copy_u8PinId <= DIO_u8_PIN7 && Copy_u8PinId >= DIO_u8_PIN0)) {
		if (Copy_u8PinVal == DIO_u8_HIGH) {
			switch (Copy_u8PortId) {
			case DIO_u8_PORTA:
				SET_BIT(PORTA_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTB:
				SET_BIT(PORTB_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTC:
				SET_BIT(PORTC_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTD:
				SET_BIT(PORTD_REGISTER, Copy_u8PinId);
				break;
			default: /* Wrong Port ID */
				break;
			}
		} else if (Copy_u8PinVal == DIO_u8_LOW) {
			switch (Copy_u8PortId) {
			case DIO_u8_PORTA:
				CLR_BIT(PORTA_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTB:
				CLR_BIT(PORTB_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTC:
				CLR_BIT(PORTC_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTD:
				CLR_BIT(PORTD_REGISTER, Copy_u8PinId);
				break;
			default: /* Wrong Port ID */
				break;
			}
		}
	}

	else {
		LOC_enuErrorStatus = DIO_invalidInput;
	}
	return LOC_enuErrorStatus;
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId) {
	u8 Copy_u8Result;
	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA)) {
		if (Copy_u8PinId <= DIO_u8_PIN7 && Copy_u8PinId >= DIO_u8_PIN0) {

			switch (Copy_u8PortId) {
			case DIO_u8_PORTA:
				Copy_u8Result = GET_BIT(PINA_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTB:
				Copy_u8Result = GET_BIT(PINB_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTC:
				Copy_u8Result = GET_BIT(PINC_REGISTER, Copy_u8PinId);
				break;
			case DIO_u8_PORTD:
				Copy_u8Result = GET_BIT(PIND_REGISTER, Copy_u8PinId);
				break;
			default: /* Wrong Port ID */
				break;
			}
		}

	}

	return Copy_u8Result;
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

DIO_tenuErrorStatus DIO_enuSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinDir) {

	DIO_tenuErrorStatus LOC_enuErrorStatus = DIO_enuOk;

	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA)) {
		if ((Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinId >= DIO_u8_PIN0)) {
			if (Copy_u8PinDir == DIO_u8_OUTPUT) {
				switch (Copy_u8PortId) {
				case DIO_u8_PORTA:
					SET_BIT(DDRA_REGISTER, Copy_u8PinId);
					break;
				case DIO_u8_PORTB:
					SET_BIT(DDRB_REGISTER, Copy_u8PinId);
					break;
				case DIO_u8_PORTC:
					SET_BIT(DDRC_REGISTER, Copy_u8PinId);
					break;
				case DIO_u8_PORTD:
					SET_BIT(DDRD_REGISTER, Copy_u8PinId);
					break;
				default: /* Wrong Port ID */
					break;
				}
			} else if (Copy_u8PinDir == DIO_u8_INPUT) {
				switch (Copy_u8PortId) {
				case DIO_u8_PORTA:
					CLR_BIT(DDRA_REGISTER, Copy_u8PinId);
					break;
				case DIO_u8_PORTB:
					CLR_BIT(DDRB_REGISTER, Copy_u8PinId);
					break;
				case DIO_u8_PORTC:
					CLR_BIT(DDRC_REGISTER, Copy_u8PinId);
					break;
				case DIO_u8_PORTD:
					CLR_BIT(DDRD_REGISTER, Copy_u8PinId);
					break;
				default: /* Wrong Port ID */
					break;
				}
			}
		} else {
			LOC_enuErrorStatus = DIO_invalidInput;
		}
	} else {
		LOC_enuErrorStatus = DIO_invalidInput;
	}

	return LOC_enuErrorStatus;
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PinDir) {

	DIO_tenuErrorStatus LOC_enuErrorStatus = DIO_enuOk;

	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA)) {
		switch (Copy_u8PortId) {
		case DIO_u8_PORTA:
			ASSIGN_REG(DDRA_REGISTER, Copy_u8PinDir);
			break;
		case DIO_u8_PORTB:
			ASSIGN_REG(DDRB_REGISTER, Copy_u8PinDir);
			break;
		case DIO_u8_PORTC:
			ASSIGN_REG(DDRC_REGISTER, Copy_u8PinDir);
			break;
		case DIO_u8_PORTD:
			ASSIGN_REG(DDRD_REGISTER, Copy_u8PinDir);
			break;
		default: /* Wrong Port ID */
			break;
		}
	}

	else {
		return LOC_enuErrorStatus = DIO_invalidInput;
	}

	return LOC_enuErrorStatus;
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortVal) //Output Direction Only
{
	DIO_tenuErrorStatus LOC_enuErrorStatus = DIO_enuOk;

	if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA)) {
		switch (Copy_u8PortId) {
		case DIO_u8_PORTA:
			ASSIGN_REG(PORTA_REGISTER, Copy_u8PortVal);
			break;
		case DIO_u8_PORTB:
			ASSIGN_REG(PORTB_REGISTER, Copy_u8PortVal);
			break;
		case DIO_u8_PORTC:
			ASSIGN_REG(PORTC_REGISTER, Copy_u8PortVal);
			break;
		case DIO_u8_PORTD:
			ASSIGN_REG(PORTD_REGISTER, Copy_u8PortVal);
			break;
		default: /* Wrong Port ID */
			break;
		}
	} else {
		LOC_enuErrorStatus = DIO_invalidInput;
	}
	return LOC_enuErrorStatus;
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

DIO_tenuErrorStatus DIO_enuTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId) {

	DIO_tenuErrorStatus LOC_enuErrorStatus = DIO_enuOk;

	if ((Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PortId >= DIO_u8_PORTA)
			&& (Copy_u8PinId <= DIO_u8_PIN7 && Copy_u8PinId >= DIO_u8_PIN0)) {
		switch (Copy_u8PortId) {
		case DIO_u8_PORTA:
			TGL_BIT(PORTA_REGISTER, Copy_u8PinId);
			break;
		case DIO_u8_PORTB:
			TGL_BIT(PORTB_REGISTER, Copy_u8PinId);
			break;
		case DIO_u8_PORTC:
			TGL_BIT(PORTC_REGISTER, Copy_u8PinId);
			break;
		case DIO_u8_PORTD:
			TGL_BIT(PORTD_REGISTER, Copy_u8PinId);
			break;
		default: /* Wrong Port ID */
			break;
		}
	}

	else {
		LOC_enuErrorStatus = DIO_invalidInput;
	}
	return LOC_enuErrorStatus;
}

