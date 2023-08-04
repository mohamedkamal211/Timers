#include"STD_Types.h"
#include "BIT_MATHS.h"

#include "Timer 0_interface.h"
#include "Timer 0_private.h"
#include "Timer 0_confige.h"
#include "Timer 0_register.h"


void(*TIMER0_pvCallBackFunc)(void) = NULL;
void TIMER0_voidInit(void){

	//Choose CLR Timer on Compare match
	CLR_BIT(TIMER0_TCCR0,TCCR0_WGM00);
	SET_BIT(TIMER0_TCCR0,TCCR0_WGM01);

	//Set compare match value to 125
	TIMER0_OCR0 = 125;

	//Set Compare Match Interrupt
	SET_BIT(TIMER0_TIMSK,TIMSK_OCIE0);

	//prescaler: division by 64
	SET_BIT(TIMER0_TCCR0,TCCR0_CS00);
	SET_BIT(TIMER0_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMER0_TCCR0,TCCR0_CS02);

}
u8 TIMER0_SetCallBack(void(*Copy_pvCallBackFunc)(void)){
	u8 Local_u8ErrorState=OK;

	if(Copy_pvCallBackFunc != NULL){

		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;

	}
	else{

		Local_u8ErrorState = NULL_POINTER;

	}

	return Local_u8ErrorState;
}
void __vector_10 (void)    __attribute__((signal));
void __vector_10 (void){

	if(TIMER0_pvCallBackFunc != NULL){

		TIMER0_pvCallBackFunc();

	}

}
