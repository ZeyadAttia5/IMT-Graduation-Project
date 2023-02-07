/*
 * Keypad.c
 *
 *  Created on: Sep 10, 2022
 *      Author: ANOOS
 */

#include "../../../INCLUDE/HAL/KEYPAD/Keypad.h"
#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include"../../../SERVICES/STD_TYPES.h"
#include "util/delay.h"

//  I took this driver from Anas  

u8 KeyPadValues[4][4] = { { 1, 2, 3, 1 }, { 3, 4, 5, 1 }, { 6, 7, 8, 1 }, { 4,
		0, 2, 1 } };

u8 Keypad_voidGetPressedKey(void) {

	u8 KeyPadResult = 0xff;

	for (u8 col = 0; col < 4; col++) {
		DIO_enuSetPinValue(DIO_u8_PORTD, col, DIO_u8_LOW); //to activate  column
		for (u8 row = 0; row < 4; row++) {

			if (DIO_u8GetPinValue(DIO_u8_PORTD, row + 4) == 0) {

				KeyPadResult = KeyPadValues[col][row];

				while (DIO_u8GetPinValue(DIO_u8_PORTD, row + 4) == 0)
					; // to save value after rafa3t soba3ak

				_delay_ms(10);

			}

		}
		DIO_enuSetPinValue(DIO_u8_PORTD, col, DIO_u8_LOW); //to close column

	}
	return KeyPadResult;
}
////////////////////////////////////////////////
void Keypad_voidSetKeyPadDir() {

	DIO_enuSetPortDirection(DIO_u8_PORTD, 0x0f);
	DIO_enuSetPortValue(DIO_u8_PORTD, 0xff); // F for 1111 of columns and F for pull up

}
