 /*
 * EXTI_Prog.c
 *
 *  Created on: Apr 23, 2023
 *      Author: Khaled Waled
 */
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_Interface.h"
#include "EXTI_Cfg.h"
#include "EXTI_Private.h"

void EXTI_voidInt0Init(void)
{

#if INT0_SENS_CONTROL == SC_LOW_LEVEL
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);

#elif INT0_SENS_CONTROL == SC_LOGIC_CHANGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);

#elif INT0_SENS_CONTROL == SC_FALLING_EDGE
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);

#elif INT0_SENS_CONTROL == SC_RISING_EDGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
#else 
	#erorr "wrong config"	
#endif


     SET_BIT(EXTI_GICR,EXTI_GICR_INT0);
}




void EXTI_voidInt1Init(void)
{

#if INT1_SENS_CONTROL == SC_LOW_LEVEL
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);

#elif INT1_SENS_CONTROL == SC_LOGIC_CHANGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);

#elif INT1_SENS_CONTROL == SC_FALLING_EDGE
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);

#elif INT1_SENS_CONTROL == SC_RISING_EDGE
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
#endif
	 SET_BIT(EXTI_GICR,EXTI_GICR_INT1);
}





void EXTI_voidInt2Init(void)
{
#if INT2_SENS_CONTROL == SC_FALLING_EDGE
	CLR_BIT(EXTI_MCUCSR	,EXTI_MCUCSR_ISC2_PIN);
#elif INT2_SENS_CONTROL == SC_RISING_EDGE
	SET_BIT(EXTI_MCUCSR	,EXTI_MCUCSR_ISC2_PIN);
#endif
	SET_BIT(EXTI_GICR,EXTI_GICR_INT2);
}




void EXTI_voidInt0Disable(void)
{
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT0);
}




void EXTI_voidInt1Disable(void)
{
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT1);
}




void EXTI_voidInt2Disable(void)
{
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT2);
}





/*******************************************************************************/
void EXTI_voidIntInit(u8 copy_Int_chanel,u8 copy_Int_trig_type)
{
	switch(copy_Int_chanel)
	{
		case  EXTI_INT0:
			switch(copy_Int_trig_type)
			{
				case SC_LOW_LEVEL :
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT0);
					break ;
				case SC_LOGIC_CHANGE :
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT0);
					break ;

				case SC_FALLING_EDGE :
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT0);
					break ;
				case SC_RISING_EDGE :
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT0);
					break ;
				}
				break;
		case  EXTI_INT1:

			switch(copy_Int_trig_type)
			{
				case SC_LOW_LEVEL :
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT1);
					break ;
				case SC_LOGIC_CHANGE :
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT1);
					break ;

				case SC_FALLING_EDGE :
					CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT1);
					break ;
				case SC_RISING_EDGE :
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00_PIN);
					SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT1);
					break ;
			}
			break;
		case  EXTI_INT2:

			switch(copy_Int_trig_type)
			{


				case SC_FALLING_EDGE :
					CLR_BIT(EXTI_MCUCSR	,EXTI_MCUCSR_ISC2_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT2);
					break ;
				case SC_RISING_EDGE :
					SET_BIT(EXTI_MCUCSR	,EXTI_MCUCSR_ISC2_PIN);
					SET_BIT(EXTI_GICR,EXTI_GICR_INT2);
					break ;
			}
			break;


	}
}

void EXTI_voidIntDisable(u8 copy_Int_chanel)
{
	switch (copy_Int_chanel)
	{
		case EXTI_INT0:
		{
			CLR_BIT(EXTI_GICR,EXTI_GICR_INT0);
			break ;
		}
		case EXTI_INT1:
		{
			CLR_BIT(EXTI_GICR,EXTI_GICR_INT1);
			break ;
		}
		case EXTI_INT2:
		{
			CLR_BIT(EXTI_GICR,EXTI_GICR_INT2);
			break ;
		}
	}
}
