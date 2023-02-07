#include "../../SERVICES/BIT_UTILIS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../INCLUDE/MCAL/DIO/Dio.h"

#include "../../INCLUDE/MCAL/UART/UART.h"
#include <stdio.h>
#include "avr/delay.h"
#include "string.h"

#define LEDON '1'
#define LEDOFF	'0'
#define MAX_LENGTH 5

	u8 userFound = 0;
	u8 userIndex = 0;
	u8 passFound = 0;

	u8 dataUser[MAX_LENGTH];
	u8 dataPass[MAX_LENGTH];
	u8 usernames[3][MAX_LENGTH] = {
			{ 'u', 's', 'e', 'r', '1' },
			{ 'u', 's','e', 'r', '2' },
			{ 'u', 's', 'e', 'r', '3' } };
	u8 passwords[3][MAX_LENGTH+1] = {
			{ 'p', 'a', 's', 's', '1' },
			{ 'p', 'a','s', 's', '2' },
			{ 'p', 'a', 's', 's', '3' } };

u8 compare_arrays(u8 *arr1, u8 *arr2, u8 size);
void LogIn(void);
int main() {



	UART_voidInit();
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_OUTPUT);
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_OUTPUT);


	LogIn();
	while (1) {
		if (userFound && passFound) {
			u8 adminMode = 1;
			UART_sendString("\n\nLogin Successful!\n");
			UART_sendString(
					"Send 1 to turn on the LED\n0 to turn it Off\nq to Log Out");
			while (adminMode) {
				u8 command = UART_u8GetChar();
				switch (command) {
				case '1':
					DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_HIGH);
					break;
				case '0':
					DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_LOW);
					break;
				case 'q':
					DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_LOW);
					UART_sendString("\n\n\n");
					userFound = 0;
					passFound = 0;
					adminMode = 0;
					userIndex = 0;
					clear_array(dataUser, MAX_LENGTH);
					clear_array(dataPass, MAX_LENGTH+1);
					LogIn();
					break;
				default:
					break;
				}
			}
		}
		else {
			UART_sendString("\nWrong Entry!\n");
			DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_HIGH);
			while (1);
		}
	}
}



void LogIn(){
//Linear search for the user
		for (u8 k = 0; k < 3; k++) { //prompts the user to type the username 3 times
			UART_sendString("Type your username:\n");

			//checks the entered username against the 3, iff the user wasn't found
			if (userFound != 1) {
				UART_u8GetString(dataUser, MAX_LENGTH); //gets the string (works fine)
				for (u8 i = 0; i < 3; i++) {
					for (u8 j = 0; j < MAX_LENGTH; j++) {
						if (dataUser[j] == usernames[i][j]) {
							userFound = 1;
							UART_sendString("I am true ");
							UART_voidSendChar(dataUser[j]);
							UART_voidSendChar(' ');
							UART_voidSendChar(usernames[i][j]);
							UART_voidSendChar('\n');
						} else {
							userFound = 0;
							UART_sendString("I am False ");
							UART_voidSendChar(dataUser[i]);
							UART_voidSendChar(' ');
							UART_voidSendChar(usernames[i][j]);
							UART_voidSendChar('\n');
						}
					}
					if (userFound == 1) {
						userIndex = i;
						break;
					}
					UART_voidSendChar('\n');
				}
			}
			if (userFound == 1)
				break;
		}

		//if user was found, search for the password
		if (userFound) {
			for (u8 var = 0; var < 3; ++var) {
				UART_voidSendChar('\n');
				UART_sendString("Type your password:\n");
				UART_u8GetString(dataPass, MAX_LENGTH+1);
			for (u8 l = 0; l < MAX_LENGTH; l++) {
				if (dataPass[l+1] == passwords[userIndex][l]) {
					passFound = 1;
					UART_sendString("I am true ");
					UART_voidSendChar(dataPass[l+1]);
					UART_voidSendChar(' ');
					UART_voidSendChar(passwords[userIndex][l]);
					UART_voidSendChar('\n');
				}
				else {
					passFound = 0;
					UART_sendString("I am False ");
					UART_voidSendChar(dataPass[l]);
					UART_voidSendChar(' ');
					UART_voidSendChar(passwords[userIndex][l]);
					UART_voidSendChar('\n');
				}
			}
			if (passFound)
				break;
		}
	}
}



u8 compare_arrays(u8 *arr1, u8 *arr2, u8 size) {
	for (u8 i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			return 0;
		}
	}
	return 1;
}
