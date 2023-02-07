/*
 * Sev_seg.h
 *
 *  Created on: Sep 5, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_HAL_SEV_SEG_SEV_SEG_H_
#define INCLUDE_HAL_SEV_SEG_SEV_SEG_H_

#define Sev_Seg_ErrorStatus 10

#include "../../../SERVICES/STD_TYPES.h"
#include "../../../SERVICES/BIT_UTILIS.h"
#include "../../MCAL/DIO/Dio.h"
#include "util/delay.h"

typedef enum {
	Sev_Seg_enuOk, Sev_Seg_invalidInput
} Sev_Seg_tenuErrorStatus;

#define Sev_commonGND  0
#define Sev_commonVCC  1
typedef struct Sev_Seg_tSevSeg {

	u8 port;
	u8 com;

} Sev_Seg_tSevSeg;

Sev_Seg_tenuErrorStatus Sev_SegINIT(Sev_Seg_tSevSeg);
Sev_Seg_tenuErrorStatus Sev_Seg_enuShowNum(u8 Copy_u8numToShow,
		Sev_Seg_tSevSeg sev);
Sev_Seg_tenuErrorStatus Sev_Seg_enuCountUpToNum(u8 Copy_u8numToShow,
		u16 Copy_u16Delay, Sev_Seg_tSevSeg sev);
Sev_Seg_tenuErrorStatus Sev_Seg_enuCountDownToZero(u8 Copy_u8numToShow,
		u16 Copy_u16Delay, Sev_Seg_tSevSeg sev);

#endif /* INCLUDE_HAL_SEV_SEG_SEV_SEG_H_ */
