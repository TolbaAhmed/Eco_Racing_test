/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: AHMAD SABRY
 */

#define F_CPU 8000000UL
#include "lib/types.h"
#include "lib/BIT_math.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"

void main(void)		// Slave
{
	//initialization
	/* DIO initialization */
	DIO_vidSetPortDir(DIO_PORTA,DIO_PORT_OUT);		//LCD Control port
	DIO_vidSetPortDir(DIO_PORTB,DIO_PORT_OUT);		//LCD Data port

	DIO_vidSetPinDir(DIO_PORTC,DIO_PIN0,DIO_INPUT);	//Push Butten #1
	DIO_vidSetPinDir(DIO_PORTC,DIO_PIN1,DIO_INPUT);	//Push Butten #2

	/* LCD initialization */
	LCD_vidInit();

	/* UART initialization */
	UART_vidInit();

	/* default strings */
	u8 scr1_line1[]="Waiting for ";
	u8 scr1_line2[]="Question";
	u8 scr2_line1[]="Are you ";
	u8 scr2_line1_case1[]="Busy?";
	u8 scr2_line1_case2[]="Hungry?";
	u8 scr2_line2[]="1.Yes   2.No";


	/* Variables initialization */
	u8 Btn = 0;
	u8 answer = 0;

	while(1)
	{

		//screen 1
		LCD_vidSendCommand(LCD_CLR);
		LCD_vidSendCommand(LCD_LINE1);
		LCD_vidwriteStr(scr1_line1);
		LCD_vidSendCommand(LCD_LINE2);
		LCD_vidwriteStr(scr1_line2);

		//UART 1
		answer = UART_Receive();

		//screen 2
		LCD_vidSendCommand(LCD_CLR);
		LCD_vidSendCommand(LCD_LINE1);
		LCD_vidwriteStr(scr2_line1);

		if(answer == 1)
		{
			LCD_vidwriteStr(scr2_line1_case1);
		}
		else if(answer == 2)
		{
			LCD_vidwriteStr(scr2_line1_case2);
		}

		LCD_vidSendCommand(LCD_LINE2);
		LCD_vidwriteStr(scr2_line2);

		Btn = 0;
		while(!(Btn))
		{
			if((DIO_u8GetPinVal(DIO_PORTC,DIO_PIN0)))
			{
				Btn = 1;
			}
			else if((DIO_u8GetPinVal(DIO_PORTC,DIO_PIN1)))
			{
				Btn = 2;
			}
		}

		//UART 2
		UART_Transmit(Btn);

	}

}


