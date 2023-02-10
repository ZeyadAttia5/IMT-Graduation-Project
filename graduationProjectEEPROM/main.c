#undef  F_CPU
#define F_CPU 8000000UL


#include "BIT_UTILIS.h"
#include "STD_TYPES.h"
#include "Dio.h"
#include "user.h"
#include "UART.h"
#include <avr/eeprom.h> 


#include <avr/wdt.h>
#include <util/delay.h>



#define LEDON '1'
#define LEDOFF	'0'

extern u8 userFound;
extern u8 passFound;







int main() {

	user_init();
	UART_voidInit();
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_OUTPUT);
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_OUTPUT);
	add_user("user1", "pass1");
	add_user("user2", "pass2");
	add_user("user3", "pass3");
//	UART_sendString("\nnumber of users is ");
//	UART_voidSendChar(number_of_users + '0');
//	UART_voidSendChar('\n');
//	for(u8 i = 1; i <= number_of_users*2; i++){
//	    UART_voidSendChar('\n');
//	    UART_sendString("username: ");
//	    UART_sendString(get_username(i));
//	    UART_voidSendChar('\n');
//	    UART_sendString("password: ");
//	    UART_sendString(get_password(i++));
//	    UART_voidSendChar('\n');
//	    UART_voidSendChar('\n');
//	}

	while (1) {
		LogIn();

		if (userFound && passFound) {
			u8 adminMode = 1;
			UART_sendString("\n\nLogin Successful!\n");
			UART_sendString("Send 1 to turn on the LED\n0 to turn it Off\nq to Log Out\n");
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

