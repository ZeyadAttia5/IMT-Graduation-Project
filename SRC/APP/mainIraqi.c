#include "../../SERVICES/BIT_UTILIS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../INCLUDE/MCAL/DIO/Dio.h"

#include "../../INCLUDE/MCAL/UART/UART.h"
#include <stdio.h>
#include "avr/delay.h"

/*
 int main(void) {


 DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_OUTPUT);
 DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_OUTPUT);
 UART_voidInit();

 u8 password[] = {'1'};
 u8 passwordsize = 1;
 u8 i = 0;
 u8 trials = 0;
 u8 passtruth = 1;
 u8 data = '6';
 while (1) {
 UART_voidSendChar(data);
 data = UART_voidGetChar();
 _delay_ms(4);

 if (trials == 6)
 {
 DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN4, DIO_u8_HIGH); //password is wrong
 //while (1) {};
 }

 if (i < passwordsize)
 {
 if (data != password[i])
 {
 passtruth = 0;
 }
 i++;
 }
 if (i >= passwordsize)
 {
 i = 0;
 if (passtruth == 1)
 {
 while (1)
 {
 data = UART_voidGetChar();
 _delay_ms(4);
 switch (data)
 {
 case 1:
 DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_HIGH); //password is right
 break;
 case 2:
 DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN7, DIO_u8_LOW); //password is right
 break;
 default:
 break;
 }
 }
 }
 if (passtruth == 0)
 {
 trials++;
 passtruth = 1;
 }
 }
 }
 }
 */
