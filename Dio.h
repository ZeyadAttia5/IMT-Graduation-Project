/*
 * Dio.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Administrator
 */
#ifndef INCLUDE_MCAL_DIO_DIO_H_
#define INCLUDE_MCAL_DIO_DIO_H_

#include "STD_TYPES.h"

typedef enum {
	DIO_enuOk, DIO_invalidInput
} DIO_tenuErrorStatus;

/*Port Define */
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/* PIN Define */
#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

/* PIN DIRECTIONS */
#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1

/* Pin Value Options */
#define DIO_u8_HIGH 0x01
#define DIO_u8_LOW 0x00

/* Port Direction */
#define DIO_u8_PORT_INPUT 0
#define DIO_u8_PORT_OUTPUT 255

/* IO Pins */

DIO_tenuErrorStatus DIO_eunSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinVal);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

DIO_tenuErrorStatus DIO_enuSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinDir);

/* IO Ports */
DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PinDir);

DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortVal); //Output Direction Only

DIO_tenuErrorStatus DIO_enuTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

#endif /* INCLUDE_MCAL_DIO_DIO_H_ */
