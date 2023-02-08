/*
 * UART.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Administrator
 */
#ifndef INCLUDE_MCAL_UART_UART_H_
#define INCLUDE_MCAL_UART_UART_H_

#include "STD_TYPES.h"
//UCSRA
#define RXC		7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR 	3
#define PE 		2
#define U2X 	1
#define MPCM 	0

//UCSRB
#define TXB8	0
#define RXB8	1

void clear_array(u8 *arr,const u8 size);
void UART_voidInit(void);
void UART_voidSendChar(const u8 data);
u8 UART_u8GetChar(void);
void UART_sendString(const u8 *data);
void UART_u8GetString(u8 *data);
//unsigned int UART_u32GetNineBits(void);
//void UART_voidSendNineBits(unsigned int data);

#endif /* INCLUDE_MCAL_UART_UART_H_ */
