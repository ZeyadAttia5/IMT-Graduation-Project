/*
 * EXTI.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_H_
#define INCLUDE_MCAL_EXTI_EXTI_H_

#include "../../../SERVICES/BIT_UTILIS.h"
#include "EXTI_prv.h"

#define EXTI_SetINT1LowLevel CLR_BIT(MCUCR, 3); CLR_BIT(MCUCR, 2)
#define EXTI_SetINT1AnyLogicalChange CLR_BIT(MCUCR, 3); SET_BIT(MCUCR, 2)
#define EXTI_SetINT1FallingEdge SET_BIT(MCUCR, 3); CLR_BIT(MCUCR, 2)
#define EXTI_SetINT1RisingEdge SET_BIT(MCUCR, 3); SET_BIT(MCUCR, 2)

#define EXTI_SetINT0LowLevel CLR_BIT(MCUCR, 3); CLR_BIT(MCUCR, 2)
#define EXTI_SetINT0AnyLogicalChange CLR_BIT(MCUCR, 3); SET_BIT(MCUCR, 2)
#define EXTI_SetINT0FallingEdge SET_BIT(MCUCR, 3); CLR_BIT(MCUCR, 2)
#define EXTI_SetINT0RisingEdge SET_BIT(MCUCR, 3); SET_BIT(MCUCR, 2)

#define EXTI_SetINT2FallingEdge CLR_BIT(MCUCSR, 6); SET_BIT(GIFR, 5)
#define EXTI_SetINT2RisingEdge SET_BIT(MCUCSR, 6); SET_BIT(GIFR, 5)
//**************************************************************************************//

#define EXTI_EnableINT1 SET_BIT(GICR, 7)
#define EXTI_EnableINT0 SET_BIT(GICR, 6)
#define EXTI_EnableINT2 SET_BIT(GICR,5)

#define EXTI_DisableINT1 CLR_BIT(GICR, 7)
#define EXTI_DisableINT0 CLR_BIT(GICR, 6)
#define EXTI_DisableINT2 CLR_BIT(GICR,5)
//**************************************************************************************//

#define EXTI_EnableINT1Flag SET_BIT(GIFR,7)
#define EXTI_EnableINT0Flag SET_BIT(GIFR,6)
#define EXTI_EnableINT2Flag SET_BIT(GIFR,5)
//**************************************************************************************//

#define EXTI_FinishSetINT1LowLevel EXTI_DisableINT1; EXTI_SetINT1LowLevel; EXTI_EnableINT1
#define EXTI_FinishSetINT1AnyLogicalChange EXTI_DisableINT1; EXTI_SetINT1AnyLogicalChange; EXTI_EnableINT1
#define EXTI_FinishSetINT1FallingEdge EXTI_DisableINT1; EXTI_SetINT1FallingEdge; EXTI_EnableINT1
#define EXTI_FinishSetINT1RisingEdge EXTI_DisableINT1; EXTI_SetINT1RisingEdge; EXTI_EnableINT1

#define EXTI_FinishSetINT0LowLevel EXTI_DisableINT0; EXTI_SetINT0LowLevel; EXTI_EnableINT0
#define EXTI_FinishSetINT0AnyLogicalChange EXTI_DisableINT0; EXTI_SetINT0AnyLogicalChange; EXTI_EnableINT0
#define EXTI_FinishSetINT0FallingEdge EXTI_DisableINT0; EXTI_SetINT0FallingEdge; EXTI_EnableINT0
#define EXTI_FinishSetINT0RisingEdge EXTI_DisableINT0; EXTI_SetINT0RisingEdge; EXTI_EnableINT0

#define EXTI_FinishSetINT2FallingEdge EXTI_DisableINT2; EXTI_SetINT2FallingEdge; EXTI_EnableINT2Flag; EXTI_EnableINT2
#define EXTI_FinishSetINT2RisingEdge EXTI_DisableINT2; EXTI_SetINT2RisingEdge; EXTI_EnableINT2Flag; EXTI_EnableINT2
#endif /* INCLUDE_MCAL_EXTI_EXTI_H_ */
