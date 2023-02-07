/*
 * LCD_cfg.h
 *
 *  Created on: Oct 11, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

typedef struct LCD_tLCD {
	u8 DataPort;
	u8 CfgPort;
	u8 RSPin;
	u8 RWPin;
	u8 ENPin;
} LCD_tLCD;

typedef enum {
	LCD_enuOk, LCD_invalidInput
} LCD_tenuErrorStatus;
#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
