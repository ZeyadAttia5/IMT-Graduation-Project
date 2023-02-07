/*
 * Inter.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_GIE_GIE_H_
#define INCLUDE_MCAL_GIE_GIE_H_

#include "./GIE_prv.h"

#define GIE_GlobalInterruptEnable SET_BIT(SREG,7);
#define GIE_GlobalInterruptDisable CLR_BIT(SREG,7);

#endif /* INCLUDE_MCAL_GIE_GIE_H_ */
