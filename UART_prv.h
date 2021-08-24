/*
 * UART_prv.h
 *
 *  Created on: Mar 26, 2021
 *      Author: AHMAD SABRY
 */

#ifndef UART_PRV_H_
#define UART_PRV_H_


#define UDR_REG			*((volatile u8*) 0x2C)
#define UCSRA_REG		*((volatile u8*) 0x2B)
#define UCSRB_REG		*((volatile u8*) 0x2A)
#define UCSRC_REG		*((volatile u8*) 0x40)
#define UBRRH_REG		*((volatile u8*) 0x40)
#define UBRRL_REG		*((volatile u8*) 0x29)


#define TXEN_BIN		3
#define RXEN_BIN		4
#define URSEL_BIN		7
#define UCSZ0_BIN		1
#define UCSZ1_BIN		2
#define UDRE_BIN		5
#define RXC_BIN			7


#endif /* UART_PRV_H_ */
