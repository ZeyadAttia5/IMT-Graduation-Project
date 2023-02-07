/*
 * LED_cfg.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_HAL_LED_LED_CFG_H_
#define INCLUDE_HAL_LED_LED_CFG_H_
#include "../../../SERVICES/STD_TYPES.h"

/*
 #define LED_PIN_0 DIO_u8_PORTA, DIO_u8_PIN0, LED_ACTIVE_HIGH
 #define LED_PIN_1 DIO_u8_PORTA, DIO_u8_PIN1, LED_ACTIVE_HIGH
 #define LED_PIN_2 DIO_u8_PORTA, DIO_u8_PIN2, LED_ACTIVE_HIGH
 #define LED_PIN_3 DIO_u8_PORTA, DIO_u8_PIN3, LED_ACTIVE_HIGH
 #define LED_PIN_4 DIO_u8_PORTA, DIO_u8_PIN4, LED_ACTIVE_HIGH
 #define LED_PIN_5 DIO_u8_PORTA, DIO_u8_PIN5, LED_ACTIVE_HIGH
 #define LED_PIN_6 DIO_u8_PORTA, DIO_u8_PIN6, LED_ACTIVE_HIGH
 #define LED_PIN_7 DIO_u8_PORTA, DIO_u8_PIN7, LED_ACTIVE_HIGH
 #define LED_ALL_8 DIO_u8_PORTA, PORT_HIGH, LED_ACTIVE_HIGH
 */

typedef struct LED_tLed {
	// a led has a state (Active High/Low), a pin, and PinValue
	u8 LED_state;		//Active HIGH/LOW
	u8 LED_pin;			//0 -> 7
	u8 LED_port;		//0 -> 3
} LED_tLed;

#endif /* INCLUDE_HAL_LED_LED_CFG_H_ */
