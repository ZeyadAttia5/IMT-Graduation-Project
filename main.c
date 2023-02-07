#undef  F_CPU
#define F_CPU 8000000UL


#include "BIT_UTILIS.h"
#include "STD_TYPES.h"
#include "Dio.h"
#include "user.h"
#include "UART.h"



#include <avr/wdt.h>
#include <util/delay.h>



#define LEDON '1'
#define LEDOFF	'0'


u8 userFound = 0;
u8 userIndex = 0;
u8 passFound = 0;

const u8 usernames[3][MAX_LENGTH] = {
		{ 'u', 's', 'e', 'r', '1' },
		{ 'u', 's','e', 'r', '2' },
		{ 'u', 's', 'e', 'r', '3' } };
const u8 passwords[3][MAX_LENGTH] = {
		{ 'p', 'a', 's', 's', '1' },
		{ 'p', 'a','s', 's', '2' },
		{ 'p', 'a', 's', 's', '3' } };

void LogIn(void);
void void_getUser();
void void_getUser(void);

int main() {


	UART_voidInit();
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_OUTPUT);
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_OUTPUT);


	while (1) {
		LogIn();
		if (userFound && passFound) {
			u8 adminMode = 1;
			UART_sendString("\n\nLogin Successful!\n");
			UART_sendString("Send 1 to turn on the LED\n0 to turn it Off\nq to Log Out");
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
					wdt_enable(WDTO_1S);
					UART_sendString("\n reset in 3");
					_delay_ms(330);
					UART_sendString("\n reset in 2");
					_delay_ms(330);
					UART_sendString("\n reset in 1\n");

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



void LogIn() {
	//Linear search for the user
	for (u8 i = 0; i < 3; i++) { //prompts the user to type the username 3 times
		UART_sendString("\nType your username:\n");
		void_getUser();
		//checks the entered username against the 3, iff the user wasn't found
		if (userFound == 1)
			break;
	}

	//if user was found, search for the password
	if (userFound) {
		for (u8 i = 0; i < 3; i++) {
			void_getPass();
			if (passFound)
			{
				UART_sendString("passtrue\n");
				break;
			}
			else {
				UART_sendString("passfalse\n");
			}
		}
	}
}


void void_getUser(void) {
	user usr;
	if (userFound != 1) {
		UART_u8GetString(usr.dataUser, MAX_LENGTH+1); //gets the string (works fine)
		for (u8 i = 0; i < 3; i++) {
			for (u8 j = 0; j < MAX_LENGTH; j++) {
				if (usr.dataUser[j] == usernames[i][j]) {
					userFound = 1;
					UART_voidSendChar(usr.dataUser[j]);
					UART_sendString("\n");
					UART_voidSendChar(usernames[i][j]);
					UART_sendString("\n TRUE \n");
				}
				else {
					userFound = 0;
					UART_voidSendChar(usr.dataUser[j]);
					UART_sendString("\n");
					UART_voidSendChar(usernames[i][j]);
					UART_sendString("\n false \n");
					break;
				}
			}
			if (userFound == 1) {
				userIndex = i;
				break;
			}
		}
	}
}


void void_getPass(void) {
	UART_voidSendChar('\n');
	UART_sendString("Type your password:\n");
	user usr;
	UART_u8GetString(usr.dataPass, MAX_LENGTH+1);

	for (u8 l = 0; l < MAX_LENGTH; l++) {
		if (usr.dataPass[l] == passwords[userIndex][l]) {
			passFound = 1;
			UART_voidSendChar(usr.dataPass[l]);
			UART_sendString("\n");
			UART_voidSendChar(passwords[userIndex][l]);
			UART_sendString("\n TRUE \n");
		}
		else {
			passFound = 0;
			UART_voidSendChar(usr.dataPass[l]);
			UART_sendString("\n");
			UART_voidSendChar(passwords[userIndex][l]);
			UART_sendString("\n false \n");
			UART_sendString("I am False ");
			break;
		}
	}
}
