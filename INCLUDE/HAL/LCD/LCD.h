/*
 * LCD.h
 *
 *  Created on: Sep 9, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_HAL_LCD_LCD_H_
#define INCLUDE_HAL_LCD_LCD_H_

#include "../../../SERVICES/STD_TYPES.h"
#include "./LCD_cfg.h"

#define LCD_RSPin 0
#define LCD_RWPin 1
#define LCD_ENPin 2

#define LCD_RS_SendData  0x01  //Register Set: 1 to send Data to LCD's processor -> memory
#define LCD_RS_Configure 0  //Register Set: 0 to configure LCD Settings

#define LCD_RW_Read      1  //To read the Busy-Flag
#define LCD_RW_Write     0  //To write data

#define LCD_Enable_On    1  //Enable Data pins
#define LCD_Enable_Off   0  //Disable Data pins

#define LCD_FunctionSetTwoLineMinPower  0b00111000    // 8-bit data, 2-line display, 5 x 7 font
#define LCD_FunctionSetTwoLineMaxPower  0b00111100    // 8-bit data, 2-line display, 5 x 10 font

#define LCD_DisplayOn  0b00001111
#define LCD_DisplayOff 0b00000000

#define LCD_ClrDisplay 0b00000001

#define LCD_DDRAM_DEFAULT_ADDRESS 128

LCD_tenuErrorStatus LCD_vidInit(LCD_tLCD copy_tLCD);
LCD_tenuErrorStatus LCD_vidSendChar(u8 LCD_u8Char, LCD_tLCD copy_tLCD);
LCD_tenuErrorStatus LCD_vidSendString(u8 *LCD_u8CharArr, LCD_tLCD copy_tLCD);
LCD_tenuErrorStatus LCD_vidSendCommand(u8 LCD_u8Command, LCD_tLCD copy_tLCD);
LCD_tenuErrorStatus LCD_vidSendDigit(u8 digit, LCD_tLCD copy_tLCD);
LCD_tenuErrorStatus LCD_vidMoveCursor(u8 LCD_u8Line, u8 LCD_u8Index,
		LCD_tLCD copy_tLCD);
LCD_tenuErrorStatus LCD_vidSendNumber(u16 Copy_u16Number, LCD_tLCD copy_tLCD);
LCD_tenuErrorStatus LCD_vidPulseEnable(u8 LCD_u8ENPin, u8 copy_u8CfgPort);

#endif /* INCLUDE_HAL_LCD_LCD_H_ */
