/*
 * Led.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Administrator
 */

#include "../../../INCLUDE/HAL/LED/Led.h"
#include "../../../INCLUDE/HAL/LED/Led_cfg.h"
#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include "avr/delay.h"

LED_tenuErrorStatus LED_init(LED_tLed copy_tLed) {

	LED_tenuErrorStatus LOC_enuErrorStatus = LED_enuOk;

	if ((copy_tLed.LED_port >= DIO_u8_PORTA
			&& copy_tLed.LED_port <= DIO_u8_PORTD)
			&& (copy_tLed.LED_pin >= DIO_u8_PIN0
					&& copy_tLed.LED_pin <= DIO_u8_PIN7)
			&& (copy_tLed.LED_state == LED_ACTIVE_HIGH
					|| copy_tLed.LED_state == LED_ACTIVE_LOW)) {
		DIO_enuSetPinDirection(copy_tLed.LED_port, copy_tLed.LED_pin,
		DIO_u8_OUTPUT);
	} else {
		LOC_enuErrorStatus = LED_invalidInput;
	}
	return LOC_enuErrorStatus;
}

LED_tenuErrorStatus LED_enuLedOn(LED_tLed copy_tLed) {

	LED_tenuErrorStatus LOC_enuErrorStatus = LED_enuOk;

	if ((copy_tLed.LED_port >= DIO_u8_PORTA
			&& copy_tLed.LED_port <= DIO_u8_PORTD)
			&& (copy_tLed.LED_pin >= DIO_u8_PIN0
					&& copy_tLed.LED_pin <= DIO_u8_PIN7)) {
		if (copy_tLed.LED_state == LED_ACTIVE_HIGH) {
			LOC_enuErrorStatus = DIO_enuSetPinValue(copy_tLed.LED_port,
					copy_tLed.LED_pin, DIO_u8_HIGH);
			//copy_tLed.LED_pinValue = 1;
		} else if (copy_tLed.LED_state == LED_ACTIVE_LOW) {
			LOC_enuErrorStatus = DIO_enuSetPinValue(copy_tLed.LED_port,
					copy_tLed.LED_pin, DIO_u8_LOW);
			//copy_tLed.LED_pinValue = 0;
		} else
			LOC_enuErrorStatus = LED_invalidInput;
	}

	else
		LOC_enuErrorStatus = LED_invalidInput;

	return LOC_enuErrorStatus;
}

LED_tenuErrorStatus LED_enuLedOff(LED_tLed copy_tLed) {

	LED_tenuErrorStatus LOC_enuErrorStatus = LED_enuOk;

	if ((copy_tLed.LED_port >= DIO_u8_PORTA
			&& copy_tLed.LED_port <= DIO_u8_PORTD)
			&& (copy_tLed.LED_pin >= DIO_u8_PIN0
					&& copy_tLed.LED_pin <= DIO_u8_PIN7)) {
		if (copy_tLed.LED_state == LED_ACTIVE_HIGH) {
			LOC_enuErrorStatus = DIO_enuSetPinValue(copy_tLed.LED_port,
					copy_tLed.LED_pin, DIO_u8_LOW);
			//copy_tLed.LED_pinValue = 0;
		} else if (copy_tLed.LED_state == LED_ACTIVE_LOW) {
			LOC_enuErrorStatus = DIO_enuSetPinValue(copy_tLed.LED_port,
					copy_tLed.LED_pin, DIO_u8_HIGH);
			//copy_tLed.LED_pinValue = 1;
		} else
			LOC_enuErrorStatus = LED_invalidInput;
	} else {
		LOC_enuErrorStatus = LED_invalidInput;
	}
	return LOC_enuErrorStatus;
}
