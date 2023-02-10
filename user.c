/*
 * user.c
 *
 * Created: 2/8/2023 9:54:22 PM
 *  Author: DarkStar
 */
#include "user.h"

#include "BIT_UTILIS.h"
#include "STD_TYPES.h"
#include "Dio.h"
#include "user.h"
#include "UART.h"

#include <avr/eeprom.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <string.h>

u8 userFound = 0;
u8 userIndex = 0;
u8 passFound = 0;
u8 number_of_users = 0;
u8 eeprom_Index = 0;

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
			UART_sendString("\nType your password:\n");
			void_getPass();
			if (passFound) {
				UART_sendString("password is correct\n");
				break;
			} else {
				UART_sendString("password is wrong\n");
			}
		}
	}
}

void void_getUser(void) {
	user usr;
	u8 datausrlength = 0;
	if (userFound != 1) {
		UART_u8GetString(usr.dataUser); //gets the string (works fine)
		for (u8 i = 1; i <= number_of_users*2; i+=2) {
			u8 LOC_u8Username = get_username(i);
			u8 comparison_result = memcmp(LOC_u8Username, usr.dataUser,
					sizeof(usr.dataUser));
			if (comparison_result == 0) {
				userIndex = i;
				userFound = 1;
				UART_voidSendChar('\n');
				UART_sendString(LOC_u8Username);
				UART_sendString(" was found at index ");
				UART_voidSendChar(i + '0');
				UART_voidSendChar('\n');
				break;
			}
		}
	}
}

void void_getPass(void) {
	user usr;
	u8 datausrlength = 0;
	UART_u8GetString(usr.dataPass); //gets the string (works fine)
	u8 LOC_u8Password = get_password(userIndex);
	u8 comparison_result = memcmp(LOC_u8Password, usr.dataPass, sizeof(usr.dataPass));
	if (comparison_result == 0) {
		passFound = 1;
		UART_voidSendChar('\n');
		UART_sendString(LOC_u8Password);
		UART_sendString(" was found at index ");
		UART_voidSendChar(userIndex+1 + '0');
		UART_voidSendChar('\n');
	}
	else{
		UART_voidSendChar('\n');
		UART_sendString(LOC_u8Password);
		UART_sendString(" was found at index ");
		UART_voidSendChar(userIndex+1 + '0');
		UART_voidSendChar('\n');
		UART_sendString("Entered password is ");
		UART_sendString(usr.dataPass);
		UART_voidSendChar('\n');

	}
}


void user_init() {
if (!(0 < eeprom_read_byte(0) && 99 > eeprom_read_byte(0))) {
	eeprom_write_byte(0, 0);
} else {
	number_of_users = eeprom_read_byte(0);
}
}

void add_user(u8 username, u8 password) {
//add new username + password in eeprom[num_ofusers] // initinal position 1

//add username -> increase pointer in memory then add;
eeprom_write_byte(0, (eeprom_read_byte(0) + 1));
eeprom_Index = eeprom_read_byte(0);
eeprom_write_byte(eeprom_Index, username);

eeprom_write_byte(0, ((u8) eeprom_read_byte(0) + 1));
eeprom_Index = eeprom_read_byte(0);
eeprom_write_byte(eeprom_Index, password);

++number_of_users;
}


void del_user(u8 username, u8 password) {
eeprom_write_byte(0, eeprom_read_byte(0) - 1);
number_of_users = eeprom_read_byte(0);
}

u8 get_username(u8 index) {
return eeprom_read_byte(index);
}

u8 get_password(u8 index) {
return eeprom_read_byte(index + 1);
}

u8 u8_compareData(u8 EEPROM_DATA, u8 *USER_DATA, uint32_t SIZE_OF_USER_DATA) {
return memcmp(EEPROM_DATA, USER_DATA, sizeof(USER_DATA));
}
