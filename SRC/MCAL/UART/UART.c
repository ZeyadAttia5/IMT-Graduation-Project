/*
 * UART.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Administrator
 */

// Task 1 support 9-bit data transmission
#include "../../../INCLUDE/MCAL/UART/UART_prv.h"
#include "../../../INCLUDE/MCAL/UART/UART.h"
#include "../../../SERVICES/BIT_UTILIS.h"
#include "../../../SERVICES/STD_TYPES.h"
#include "avr/delay.h"

void UART_voidInit(void) {
	//Set Baud Rate
	UBRRL = 51;
	UBRRH = 0;
	//Set Frame format -> 9 data 1 stop 0 parity
//	UCSRB = 0x04;
	UCSRC = 0x86;
	//Enable Rx and Tx
	UCSRB = 0x18; //||UCSRB;
}

void UART_voidSendChar(u8 data) {

	//while condition equivalent to GET_BIT(UCSRA, someBIT) check bit with calc programmer mode
	//while((UCSRA&0x20) == 0x00);
	while (!( UCSRA & (1 << UDRE)))
		;
	UDR_T = data;
}

u8 UART_u8GetChar(void) {
	u8 LOC_u8Result = 0;
	while ((UCSRA & 0x80) == 0x00)
		;
	LOC_u8Result = UDR_R;
	return LOC_u8Result;
}

void UART_sendString(u8 *data) {
	for (int i = 0; data[i] != '\0'; i++) {
		UART_voidSendChar(data[i]);
	}
}

void UART_u8GetString(u8 *string, u8 strLength) {
	u8 LOC_u8Data = 0;
	u8 idx = 0;
	LOC_u8Data = UART_u8GetChar();
	while (idx < strLength) {
		string[idx] = LOC_u8Data;
		LOC_u8Data = UART_u8GetChar();
		idx++;
	}
//	string[idx] = '\0';
}

void clear_array(u8 *arr, u8 size) {
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = '\0';
	}
}

/*void UART_voidSendNineBits(unsigned int data){

 while ( !( UCSRA & (1<<UDRE)));
 UCSRB &= ~(1<<TXB8);
 if ( data & 0x0100 )
 UCSRB |= (1<<TXB8);
 UDR_T = data;
 }
 unsigned int UART_u32GetNineBits(void){

 u8 LOC_u8Result = 0;
 while (!(UCSRA & (1<<RXC)));
 u8 status = UCSRA;
 u8 resh = UCSRB;
 LOC_u8Result = UDR_R;
 if ( (status & (1<<FE))|(1<<DOR)|(1<<PE) )
 return -1;
 resh = (resh >> 1) & 0x01;

 return ((resh << 8) | LOC_u8Result);
 }*/
