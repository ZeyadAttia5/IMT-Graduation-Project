#include "../../../INCLUDE/HAL/Sev_Seg/Sev_Seg.h"

#include "../../../INCLUDE/MCAL/DIO/Dio.h"

static u8 Sev_Seg_Arr_DecToSeg[11] = { 0b00111111, /* 0 */
0b00000110, /* 1 */
0b01011011, /* 2 */
0b01001111, /* 3 */
0b01100110, /* 4 */
0b01101101, /* 5 */
0b01111101, /* 6 */
0b00000111, /* 7 */
0b01111111, /* 8 */
0b01101111, /* 9 */
0b01111001 /* E */
};

Sev_Seg_tenuErrorStatus Sev_SegINIT(Sev_Seg_tSevSeg sev) {
	Sev_Seg_tenuErrorStatus LOC_enuErrorStatus = Sev_Seg_enuOk;

	if ((sev.port >= DIO_u8_PORTA && sev.port <= DIO_u8_PORTD)) {
		DIO_enuSetPortDirection(sev.port, DIO_u8_PORT_OUTPUT);
	} else
		LOC_enuErrorStatus = Sev_Seg_invalidInput;

	return LOC_enuErrorStatus;
}

Sev_Seg_tenuErrorStatus Sev_Seg_enuShowNum(u8 Copy_u8numToShow,
		Sev_Seg_tSevSeg sev) {
	Sev_Seg_tenuErrorStatus LOC_enuErrorStatus = Sev_Seg_enuOk;

	if ((Copy_u8numToShow < 10 && Copy_u8numToShow >= 0)
			&& (sev.port >= DIO_u8_PORTA && sev.port <= DIO_u8_PORTD)) {
		switch (sev.com) {
		case Sev_commonGND:
			DIO_enuSetPortValue(sev.port,
					Sev_Seg_Arr_DecToSeg[Copy_u8numToShow]);
			break;

		case Sev_commonVCC:
			DIO_enuSetPortValue(sev.port,
					!Sev_Seg_Arr_DecToSeg[Copy_u8numToShow]);
			break;

		default:
			LOC_enuErrorStatus = Sev_Seg_invalidInput;
		}
	} else {
		DIO_enuSetPortValue(sev.port,
				Sev_Seg_Arr_DecToSeg[Sev_Seg_ErrorStatus]);
		LOC_enuErrorStatus = Sev_Seg_invalidInput;
	}

	return LOC_enuErrorStatus;
}

Sev_Seg_tenuErrorStatus Sev_Seg_enuCountUpToNum(u8 Copy_u8numToShow,
		u16 Copy_u16Delay, Sev_Seg_tSevSeg sev) {
	Sev_Seg_tenuErrorStatus LOC_enuErrorStatus = Sev_Seg_enuOk;
	if ((Copy_u8numToShow <= 9 && Copy_u8numToShow >= 0)
			&& (sev.port >= DIO_u8_PORTA && sev.port <= DIO_u8_PORTD)) {
		switch (sev.com) {
		u8 u8Counter = 0;
	case Sev_commonGND:
		u8Counter = 0;
		while (u8Counter <= Copy_u8numToShow) {
			DIO_enuSetPortValue(sev.port, Sev_Seg_Arr_DecToSeg[u8Counter]);
			_delay_ms(Copy_u16Delay);
			u8Counter++;
		}
		break;

	case Sev_commonVCC:
		u8Counter = 0;
		while (u8Counter <= Copy_u8numToShow) {
			DIO_enuSetPortValue(sev.port, !Sev_Seg_Arr_DecToSeg[u8Counter]);
			_delay_ms(Copy_u16Delay);
			u8Counter++;
		}
		break;

	default:
		LOC_enuErrorStatus = Sev_Seg_invalidInput;
		}
	} else {
		DIO_enuSetPortValue(sev.port,
				Sev_Seg_Arr_DecToSeg[Sev_Seg_ErrorStatus]); //Shows 'E' on the Sev-seg
		LOC_enuErrorStatus = Sev_Seg_invalidInput;
	}

	return LOC_enuErrorStatus;
}

Sev_Seg_tenuErrorStatus Sev_Seg_enuCountDownToZero(u8 Copy_u8numToShow,
		u16 Copy_u16Delay, Sev_Seg_tSevSeg sev) {
	Sev_Seg_tenuErrorStatus LOC_enuErrorStatus = Sev_Seg_enuOk;
	if ((Copy_u8numToShow <= 9 && Copy_u8numToShow >= 0)
			&& (sev.port >= DIO_u8_PORTA && sev.port <= DIO_u8_PORTD)) {
		switch (sev.com) {
		s8 s8Counter;
	case Sev_commonGND:
		s8Counter = Copy_u8numToShow;
		while (s8Counter >= 0) {
			DIO_enuSetPortValue(sev.port, Sev_Seg_Arr_DecToSeg[s8Counter]);
			_delay_ms(Copy_u16Delay);
			s8Counter--;
		}
		break;

	case Sev_commonVCC:
		s8Counter = Copy_u8numToShow;
		while (s8Counter >= 0) {
			DIO_enuSetPortValue(sev.port, !Sev_Seg_Arr_DecToSeg[s8Counter]);
			_delay_ms(Copy_u16Delay);
			s8Counter--;
		}
		break;

	default:
		LOC_enuErrorStatus = Sev_Seg_invalidInput;
		}
	}

	else {
		DIO_enuSetPortValue(sev.port,
				Sev_Seg_Arr_DecToSeg[Sev_Seg_ErrorStatus]); //Shows 'E' on the Sev-seg
		LOC_enuErrorStatus = Sev_Seg_invalidInput;
	}

	return LOC_enuErrorStatus;
}
