/*
 * main.c
 *
 *  Created on: Jan 22, 2021
 *      Author: AHMAD SABRY
 */

#include "lib/types.h"
#include "lib/BIT_math.h"
#include "DIO_interface.h"
#include "DIO_prv.h"


void DIO_vidSetPinVal(u8 Portid, u8 Pinid, u8 PinVal)
{
	if((Portid <= DIO_PORTD) && (Pinid <= DIO_PIN7))
	{
		if(PinVal == DIO_HIGH)
		{
			switch (Portid)
			{
			case DIO_PORTA: SET_BIT(PORTA_REG,Pinid);break;
			case DIO_PORTB: SET_BIT(PORTB_REG,Pinid);break;
			case DIO_PORTC: SET_BIT(PORTC_REG,Pinid);break;
			case DIO_PORTD: SET_BIT(PORTD_REG,Pinid);break;
			}
		}
		else if(PinVal == DIO_LOW)
		{
			switch (Portid)
			{
			case DIO_PORTA: CLR_BIT(PORTA_REG,Pinid);break;
			case DIO_PORTB: CLR_BIT(PORTB_REG,Pinid);break;
			case DIO_PORTC: CLR_BIT(PORTC_REG,Pinid);break;
			case DIO_PORTD: CLR_BIT(PORTD_REG,Pinid);break;
			}
		}
		else
		{
			//report error
		}
	}
	else
	{
		//report error
	}
}
void DIO_vidSetPinDir(u8 Portid, u8 Pinid, u8 PinDir)
{
	if((Portid <= DIO_PORTD) && (Pinid <= DIO_PIN7))
	{
		if(PinDir == DIO_HIGH)
		{
			switch (Portid)
			{
			case DIO_PORTA: SET_BIT(DDRA_REG,Pinid);break;
			case DIO_PORTB: SET_BIT(DDRB_REG,Pinid);break;
			case DIO_PORTC: SET_BIT(DDRC_REG,Pinid);break;
			case DIO_PORTD: SET_BIT(DDRD_REG,Pinid);break;
			}
		}
		else if(PinDir == DIO_LOW)
		{
			switch (Portid)
			{
			case DIO_PORTA: CLR_BIT(DDRA_REG,Pinid);break;
			case DIO_PORTB: CLR_BIT(DDRB_REG,Pinid);break;
			case DIO_PORTC: CLR_BIT(DDRC_REG,Pinid);break;
			case DIO_PORTD: CLR_BIT(DDRD_REG,Pinid);break;
			}
		}
		else
		{
			//report error
		}
	}
	else
	{
		//report error
	}
}
void DIO_vidSetPortVal(u8 Portid, u8 PortVal)
{
	if(Portid <= DIO_PORTD)
	{
		switch (Portid)
		{
		case DIO_PORTA: PORTA_REG = PortVal;break;
		case DIO_PORTB: PORTB_REG = PortVal;break;
		case DIO_PORTC: PORTC_REG = PortVal;break;
		case DIO_PORTD: PORTD_REG = PortVal;break;
		}

	}
	else
	{
		//report error
	}
}
void DIO_vidSetPortDir(u8 Portid, u8 PortDir)
{
	if(Portid <= DIO_PORTD)
	{
		switch (Portid)
		{
		case DIO_PORTA: DDRA_REG = PortDir;break;
		case DIO_PORTB: DDRB_REG = PortDir;break;
		case DIO_PORTC: DDRC_REG = PortDir;break;
		case DIO_PORTD: DDRD_REG = PortDir;break;
		}
	}
	else
	{
		//report error
	}
}
u8 DIO_u8GetPinVal(u8 Portid, u8 Pinid)
{
	u8 Result = 0xff; //means wrong inputs (port ID or Pin ID)

	if((Portid <= DIO_PORTD) && (Pinid <= DIO_PIN7))
	{
		switch (Portid)
		{
		case DIO_PORTA: Result = GET_BIT(PINA_REG,Pinid);break;
		case DIO_PORTB: Result = GET_BIT(PINB_REG,Pinid);break;
		case DIO_PORTC: Result = GET_BIT(PINC_REG,Pinid);break;
		case DIO_PORTD: Result = GET_BIT(PIND_REG,Pinid);break;
		}
	}
	return Result;
}

