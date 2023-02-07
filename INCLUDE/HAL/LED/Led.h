/*
 * Led.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_HAL_LED_LED_H_
#define INCLUDE_HAL_LED_LED_H_

#include "Led_cfg.h"

#define LED_ACTIVE_HIGH 1
#define LED_ACTIVE_LOW 0
#define PORT_HIGH	255

typedef enum {
	LED_enuOk, LED_invalidInput
} LED_tenuErrorStatus;

LED_tenuErrorStatus LED_init(LED_tLed copy_tLed);
LED_tenuErrorStatus LED_enuLedOn(LED_tLed led);
LED_tenuErrorStatus LED_enuLedOff(LED_tLed led);

#endif /* INCLUDE_HAL_LED_LED_H_ */
