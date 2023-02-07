/*
 * spi.c
 *
 *  Created on: Oct 15, 2022
 *      Author: Administrator
 */

#include "../../../INCLUDE/MCAL/SPI/spi.h"
#include "../../../INCLUDE/MCAL/SPI/spi_prv.h"
#include "../../../SERVICES/BIT_UTILIS.h"
#include "../../../SERVICES/STD_TYPES.h"
#include "../../../INCLUDE/MCAL/DIO/Dio.h"
#include "avr/delay.h"

SPI_tenuErrorStatus SPI_enuMasterInit(u8 Copy_u8DataMode, u8 Copy_u8ClockSelect,
		u8 Copy_u8DataOrder) {
	SPI_tenuErrorStatus LOC_enuErrorStatus = spi_enuOk;
	switch (Copy_u8DataMode) {
	case 0:
		CLR_BIT(SPCR, SPCR_CPOL);
		CLR_BIT(SPCR, SPCR_CPHA);
		break;
	case 1:
		CLR_BIT(SPCR, SPCR_CPOL);
		SET_BIT(SPCR, SPCR_CPHA);
		break;
	case 2:
		SET_BIT(SPCR, SPCR_CPOL);
		CLR_BIT(SPCR, SPCR_CPHA);
		break;
	case 3:
		SET_BIT(SPCR, SPCR_CPOL);
		SET_BIT(SPCR, SPCR_CPHA);
		break;
	default:
		LOC_enuErrorStatus = spi_invalidInput;
		return LOC_enuErrorStatus;
	}

	switch (Copy_u8ClockSelect) {
	case SPI_Prescaler4:
		CLR_BIT(SPSR, SPSR_SPI2X);
		CLR_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPCR, SPCR_SPR1);
		break;
	case SPI_Prescaler16:
		CLR_BIT(SPSR, SPSR_SPI2X);
		CLR_BIT(SPCR, SPCR_SPR1);
		SET_BIT(SPCR, SPCR_SPR1);
		break;
	case SPI_Prescaler64:
		CLR_BIT(SPSR, SPSR_SPI2X);
		SET_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPCR, SPCR_SPR1);
		break;
	case SPI_Prescaler128:
		CLR_BIT(SPSR, SPSR_SPI2X);
		SET_BIT(SPCR, SPCR_SPR1);
		SET_BIT(SPCR, SPCR_SPR1);
		break;
	case SPI_2xPrescaler2:
		SET_BIT(SPSR, SPSR_SPI2X);
		CLR_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPCR, SPCR_SPR1);
		break;
	case SPI_2xPrescaler8:
		SET_BIT(SPSR, SPSR_SPI2X);
		CLR_BIT(SPCR, SPCR_SPR1);
		SET_BIT(SPCR, SPCR_SPR1);
		break;
	case SPI_2xPrescaler32:
		SET_BIT(SPSR, SPSR_SPI2X);
		SET_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPCR, SPCR_SPR1);
		break;
	case SPI_2xPrescaler64:
		SET_BIT(SPSR, SPSR_SPI2X);
		SET_BIT(SPCR, SPCR_SPR1);
		SET_BIT(SPCR, SPCR_SPR1);
		break;
	default:
		LOC_enuErrorStatus = spi_invalidInput;
		return LOC_enuErrorStatus;
	}

	switch (Copy_u8DataOrder) {
	case SPI_TransmitMSB:
		CLR_BIT(SPCR, SPCR_DORD);
		break;
	case SPI_TransmitLSB:
		SET_BIT(SPCR, SPCR_DORD);
		break;
	default:
		LOC_enuErrorStatus = spi_invalidInput;
		return LOC_enuErrorStatus;
	}

	SET_BIT(SPCR, SPCR_MSTR);
	DIO_enuSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN5, DIO_u8_OUTPUT);
	DIO_enuSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN7, DIO_u8_OUTPUT);
	DIO_enuSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_OUTPUT);
	DIO_enuSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_HIGH);
	SET_BIT(SPCR, SPCR_SPE);

	return LOC_enuErrorStatus;
}

SPI_tenuErrorStatus SPI_enuSlaveInit(u8 Copy_u8DataMode, u8 Copy_u8DataOrder) {

	SPI_tenuErrorStatus LOC_enuErrorStatus = spi_enuOk;
	switch (Copy_u8DataMode) {
	case 0:
		CLR_BIT(SPCR, SPCR_CPOL);
		CLR_BIT(SPCR, SPCR_CPHA);
		break;
	case 1:
		CLR_BIT(SPCR, SPCR_CPOL);
		SET_BIT(SPCR, SPCR_CPHA);
		break;
	case 2:
		SET_BIT(SPCR, SPCR_CPOL);
		CLR_BIT(SPCR, SPCR_CPHA);
		break;
	case 3:
		SET_BIT(SPCR, SPCR_CPOL);
		SET_BIT(SPCR, SPCR_CPHA);
		break;
	default:
		LOC_enuErrorStatus = spi_invalidInput;
		return LOC_enuErrorStatus;
	}

	switch (Copy_u8DataOrder) {
	case SPI_TransmitMSB:
		CLR_BIT(SPCR, SPCR_DORD);
		break;
	case SPI_TransmitLSB:
		SET_BIT(SPCR, SPCR_DORD);
		break;
	default:
		LOC_enuErrorStatus = spi_invalidInput;
		return LOC_enuErrorStatus;
	}

	CLR_BIT(SPCR, SPCR_MSTR);
	SET_BIT(SPCR, SPCR_SPE);
	DIO_enuSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN6, DIO_u8_OUTPUT);

	return LOC_enuErrorStatus;
}

u8 SPI_u8Trancieve(u8 Copy_u8Data) {
	SPDR = Copy_u8Data;
	while (GET_BIT(SPSR, SPSR_SPIF) == 0)
		;
	_delay_us(2000);
	return SPDR;
}

void SPI_enuInterruptEnable(void) {
	SET_BIT(SPCR, SPCR_SPIE);
}
