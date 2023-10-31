/*
 * main.c
 *
 *  Created on: Oct 4, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Sevev_Seg_interface.h"
#include "LCD_interfac.h"
#include "keypad_interface.h"
#include "EXTI_Interface.h"
#include "Interrupt_interface.h"
#include "ADC_interface.h"
#include "Timer0_interface.h"
#include <util/delay.h>
volatile u8 flag_ldr=0;
volatile u8 flag_lm35=0;
volatile u16 READ_ldr=0;
volatile u16 READ_lm35=0;


void __vector_1(void) __attribute__ ((signal,used, externally_visible));
void __vector_1(void)
{
//	DIO_voidSetPinValue(PORTA_ID,PIN6,PIN_HIGH);
	if(READ_lm35 > 35)
	{
	DIO_voidSetPinValue(PORTC_ID,PIN6, PIN_HIGH);


	}
	if(READ_ldr < 20 && READ_ldr > 10)
	{
		DIO_voidSetPinValue(PORTC_ID,PIN6, PIN_LOW);

	}
}


void ADC_Chain_();

int main()
{
	//u8 ADC_Result = 0;
	HLCD_voidLcdIntiate();
	GIE_voidEnable();
	EXTI_voidInt0Init();
	ADC_voidInit();
	ADC_EnableInt0();

	//ADC_Result = ADC_voidGetResoult();


	DIO_voidSetPinDirection(PORTA_ID,PIN0,PIN_INPUT);	// LDR
	DIO_voidSetPinDirection(PORTA_ID,PIN1,PIN_INPUT);	// LM35

	DIO_voidSetPinDirection(PORTB_ID,PIN7,PIN_OUTPUT);	//led red
	DIO_voidSetPinDirection(PORTA_ID,PIN4,PIN_OUTPUT);	//led green
	DIO_voidSetPinDirection(PORTA_ID,PIN5,PIN_OUTPUT);	//led blue
	DIO_voidSetPinDirection(PORTA_ID,PIN6,PIN_OUTPUT);	//led yellow


	DIO_voidSetPinDirection(PORTC_ID,PIN6,PIN_OUTPUT);	// buzzer
	DIO_voidSetPinDirection(PORTD_ID, PIN2, PIN_OUTPUT);

			while (1)
			{
				ADC_Chain_();
				if (flag_ldr)
						{

							flag_ldr=0;

							if(READ_ldr < 20 && READ_ldr > 10)
							{
								DIO_voidSetPinValue(PORTB_ID,PIN7,PIN_HIGH);  //led blue
								DIO_voidSetPinValue(PORTA_ID,PIN4,PIN_LOW);   //led yellow
								DIO_voidSetPinValue(PORTA_ID,PIN5,PIN_LOW);   //led red
								DIO_voidSetPinValue(PORTA_ID,PIN6,PIN_LOW);   //led green
								HLCD_voidLcdWriteString("Alarm Heat low", 1,0);
								DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_HIGH);
								_delay_ms(10);
								DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_LOW);

//								HLCD_voidLcdWriteString("READ_ldr ", 1,1);
//								HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);


							}
							else if(READ_ldr < 10 && READ_ldr > 0)
							{
								HLCD_voidLcdWriteString("READ_ldr ", 1,0);
								HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
								DIO_voidSetPinValue(PORTB_ID,PIN7,PIN_LOW);
								DIO_voidSetPinValue(PORTA_ID,PIN4,PIN_HIGH);
								DIO_voidSetPinValue(PORTA_ID,PIN5,PIN_LOW);
								DIO_voidSetPinValue(PORTA_ID,PIN6,PIN_LOW);
//								HLCD_voidLcdWriteString("READ_ldr ", 1,1);
//								HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
							}
							else if(READ_ldr < 30 && READ_ldr > 20)
							{
								HLCD_voidLcdWriteString("READ_ldr ", 1,0);
															HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
								DIO_voidSetPinValue(PORTB_ID,PIN7,PIN_LOW);
								DIO_voidSetPinValue(PORTA_ID,PIN4,PIN_LOW);
								DIO_voidSetPinValue(PORTA_ID,PIN5,PIN_HIGH);
								DIO_voidSetPinValue(PORTA_ID,PIN6,PIN_LOW);
//								HLCD_voidLcdWriteString("READ_ldr ", 1,1);
//								HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
							}
							else if(READ_ldr < 40 && READ_ldr > 30)
							{
								HLCD_voidLcdWriteString("READ_ldr ", 1,0);
															HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
								DIO_voidSetPinValue(PORTB_ID,PIN7,PIN_LOW);
								DIO_voidSetPinValue(PORTA_ID,PIN4,PIN_LOW);
								DIO_voidSetPinValue(PORTA_ID,PIN5,PIN_LOW);
								DIO_voidSetPinValue(PORTA_ID,PIN6,PIN_HIGH);
//								HLCD_voidLcdWriteString("READ_ldr ", 1,1);
//								HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
							}
							else
							{
								HLCD_voidLcdWriteString("READ_ldr ", 1,0);
															HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
								DIO_voidSetPinValue(PORTB_ID,PIN7,PIN_HIGH);
								DIO_voidSetPinValue(PORTA_ID,PIN4,PIN_HIGH);
								DIO_voidSetPinValue(PORTA_ID,PIN5,PIN_HIGH);
								DIO_voidSetPinValue(PORTA_ID,PIN6,PIN_HIGH);
//								HLCD_voidLcdWriteString("READ_ldr ", 1,1);
//								HLCD_voidLcdWriteIntiger(READ_ldr,1, 10);
							}

							if (flag_lm35)
									{
										flag_lm35=0;
										HLCD_voidLcdWriteString("READ_lm35 ", 0,0);
										HLCD_voidLcdWriteIntiger((READ_lm35),0, 10);

										if(READ_lm35 > 35)
										{
											HLCD_voidLcdWriteString("Alarm Heat Above 35", 0,1);
											DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_HIGH);
											_delay_ms(10);
											DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_LOW);
										}

									}
						}
			}

			return 0;
}

void ADC_Chain_()
{
	static ADC_Channel_t channel= ADC_Channel_0;
	if(flag_ldr==0)
	{
		flag_ldr = 1;

		READ_ldr = ADC_voidGetResoult();
		READ_ldr = (u16)(READ_ldr*4.88);
		READ_ldr = (READ_ldr / 10);

		channel = ADC_Channel_1;

		ADC_voidStartConversion(channel);
	}
	if (flag_lm35==0)
	{
		flag_lm35 = 1;


		READ_lm35 = ADC_voidGetResoult();
		READ_lm35 =(u16)(READ_lm35*4.88);
		READ_lm35 = (READ_lm35 / 10);
		channel= ADC_Channel_0;

		ADC_voidStartConversion(channel);
	}
}


