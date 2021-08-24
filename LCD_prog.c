/*
 * LCD_prog.c
 *
 *  Created on: Jan 23, 2021
 *      Author: AHMAD SABRY
 */
#include "lib/types.h"
#define F_CPU 8000000
#include <avr/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_prv.h"


void LCD_vidInit(void)
{
	//delay for 30 ms to ensure LCD uc initialization
	_delay_ms(30);

	//function SET command
	LCD_vidSendCommand(LCD_FUNCSET_8BIT);
	_delay_ms(1);

	//display ON/OFF
	LCD_vidSendCommand(LCD_DISPON_CURSOFF);
	_delay_ms(15);

	//return home
	LCD_vidSendCommand(LCD_HOME);
	_delay_ms(15);

	//entry set command
	LCD_vidSendCommand(LCD_ENTRYMODE);
	_delay_ms(2);

}

void LCD_vidSendCommand(u8 u8Cmd)
{
	//clear RS pin
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	//clear RW pin
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
	//set pin E to high
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	//load command to the data pins
	DIO_vidSetPortVal(LCD_DATA_PORT, u8Cmd);
	//clear E pin
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(5);
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(10);

}

void LCD_vidSendChar(u8 u8Char)
{
	//clear RS pin
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	//clear RW pin
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
	//set pin E to high
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	//load command to the data pins
	DIO_vidSetPortVal(LCD_DATA_PORT, u8Char);
	//clear E pin
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(5);
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(10);
}

void LCD_vidwriteStr(u8* pu8Str)
{
	u8 i = 0;
	while(pu8Str[i] != 0)
	{
		LCD_vidSendChar(pu8Str[i++]);
	}
}


void LCD_vidWriteInt(u16 Num)
{
	u16 NumCopy = Num;
	u8 Digits = 0;
	u8 k = 0;
	u16 Shift = 1;
	u8 Array[16] ={0};

	for(Digits =0 ; NumCopy > 0 ; Digits++)
	{
		NumCopy = NumCopy/10;
		Shift*=10;
	}

	Shift/=10;
	Digits--;

	for(k=0 ; k <= Digits ; k++)
	{
		Array[k]=(Num / Shift) + '0';
		Num = Num % Shift;
		Shift/=10;
	}

	k = 0;

	while(Array[k] != 0)
	{
		LCD_vidSendChar(Array[k++]);
	}
}


void LCD_vidLoadNewChar(void)
{
	LCD_vidSendCommand(0x40);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);


	LCD_vidSendCommand(0x48);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x10);
	LCD_vidSendChar(0x08);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x1E);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x00);


	LCD_vidSendCommand(0x50);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x0E);
	LCD_vidSendChar(0x1B);
	LCD_vidSendChar(0x0E);
	LCD_vidSendChar(0x00);


	LCD_vidSendCommand(0x58);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x04);
	LCD_vidSendChar(0x1F);
	LCD_vidSendChar(0x00);
	LCD_vidSendChar(0x00);
}
