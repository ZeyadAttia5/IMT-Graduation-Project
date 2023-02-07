/*
 * spi.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_SPI_SPI_H_
#define INCLUDE_MCAL_SPI_SPI_H_

#include "../../../SERVICES/STD_TYPES.h"

typedef enum {
	spi_enuOk, spi_invalidInput
} SPI_tenuErrorStatus;

/*SPI Control Register Bits � SPCR Bits*/
#define SPCR_SPIE	7	//SPI Interrupt Enable
#define SPCR_SPE 	6	//SPI Enable
#define SPCR_DORD	5	//Data Order
#define SPCR_MSTR	4	//Master-Slave Select
#define SPCR_CPOL	3	//Clock Polarity
#define SPCR_CPHA 	2	//Clock Phase
#define SPCR_SPR1 	1	//Clock Rate Select
#define SPCR_SPR0 	0	//Clock Rate Select
/**************************************/
/**************************************/

/*SPI Status Register � SPSR Bits*/
#define SPSR_SPIF	7	//SPI Interrupt Flag
#define SPSR_WCOL 	6	//SPI Write COLlision Flag
#define SPSR_SPI2X 	0	//Clock Rate Select
/**************************************/
/**************************************/

/*Clock Rate Select*/
#define SPI_Prescaler4			0
#define SPI_Prescaler16			1
#define SPI_Prescaler64			2
#define SPI_Prescaler128		3
#define SPI_2xPrescaler2		4
#define SPI_2xPrescaler8		5
#define SPI_2xPrescaler32		6
#define SPI_2xPrescaler64		7
/**************************************/
/**************************************/

/*Data Mode Select*/
#define SPI_ReadRising		0
#define SPI_SendRising		1
#define SPI_ReadFalling		2
#define SPI_SendFalling		3
/**************************************/
/**************************************/

/*Data Order Select*/
#define SPI_TransmitMSB		0
#define SPI_TransmitLSB		1
/**************************************/
/**************************************/

SPI_tenuErrorStatus SPI_enuMasterInit(u8 Copy_u8DataMode, u8 Copy_u8ClockSelect,
		u8 Copy_u8DataOrder);
SPI_tenuErrorStatus SPI_enuSlaveInit(u8 Copy_u8DataMode, u8 Copy_u8DataOrder);
u8 SPI_u8Trancieve(u8 Copy_u8Data);
void SPI_enuInterruptEnable(void);

#endif /* INCLUDE_MCAL_SPI_SPI_H_ */
