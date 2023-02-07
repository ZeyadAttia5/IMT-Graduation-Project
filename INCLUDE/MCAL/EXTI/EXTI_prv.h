/*
 * EXTI_prv.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Administrator
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_PRV_H_
#define INCLUDE_MCAL_EXTI_EXTI_PRV_H_

#define MCUCR *((volatile u8*) 0x55) //INT0, INT1 MODES
#define MCUCSR *((volatile u8*) 0x54) //INT2 MODE
#define GICR *((volatile u8*) 0x5B) //General Interrupt Control Register    INT1->Bit7   INT0->Bit6   INT2->5
#define GIFR *((volatile u8*) 0x5A) // Global Interrupt Flags Register
#define SREG *((volatile u8*) 0x5F) // Status Register works as Global Interrupt Enable    BIT7 -> Interrupts

#endif /* INCLUDE_MCAL_EXTI_EXTI_PRV_H_ */
