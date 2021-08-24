/*
 * UART_prog.c
 *
 *  Created on: Mar 26, 2021
 *      Author: AHMAD SABRY
 */

#define F_CPU 8000000UL
#include "lib/types.h"
#include "lib/BIT_math.h"
#include "UART_interface.h"
#include "UART_prv.h"

void UART_vidInit(void)
{
	UBRRH_REG = BAUDRATE >> 8;
	UBRRL_REG = BAUDRATE;
	UCSRB_REG = (1<<TXEN_BIN) | (1<<RXEN_BIN);
	UCSRC_REG = (1<<URSEL_BIN) | (1<<UCSZ0_BIN) | (1<<UCSZ1_BIN);
}


void UART_Transmit(u8 Byte)
{
	while(!(UCSRA_REG & (1<<UDRE_BIN)));
	UDR_REG = Byte;
}


u8 UART_Receive(void)
{
	while(!(UCSRA_REG & (1<<RXC_BIN)));
	return UDR_REG;
}
