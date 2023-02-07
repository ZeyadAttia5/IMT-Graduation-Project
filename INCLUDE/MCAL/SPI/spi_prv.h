/*
 * spi_prv.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_SPI_SPI_PRV_H_
#define INCLUDE_MCAL_SPI_SPI_PRV_H_
#include "../../../SERVICES/STD_TYPES.h"

#define SPCR *((volatile u8*) 0x2D)
#define SPSR *((volatile u8*) 0x2E)
#define SPDR *((volatile u8*) 0x2F)

#endif /* INCLUDE_MCAL_SPI_SPI_PRV_H_ */
