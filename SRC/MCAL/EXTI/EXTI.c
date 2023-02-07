/*
 * EXTI.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Administrator
 */

//Example usage for the driver
// INPUT
/*

 DIO_enuSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_OUTPUT);
 // PULLUP
 DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_HIGH);


 DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_OUTPUT);
 DIO_enuSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_OUTPUT);

 */
//Set Mode -> Falling Edge
//		EXTI_FinishSetINT2FallingEdge;
/*
 while (1){
 for(u8 i = 0; i <15; i++){
 if(i == 10){
 GIE_GlobalInterruptDisable;
 EXTI_FinishSetINT0FallingEdge;
 GIE_GlobalInterruptEnable;
 DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_LOW);
 _delay_ms(50);
 }
 DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_HIGH);
 _delay_ms(200);
 DIO_enuSetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_LOW);
 _delay_ms(200);
 }
 EXTI_EnableINT0Flag;
 DIO_enuSetPinValue(DIO_u8_PORTD, DIO_u8_PIN2, DIO_u8_HIGH);
 _delay_ms(2000);
 }
 */
