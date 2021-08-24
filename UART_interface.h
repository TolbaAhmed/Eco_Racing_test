/*
 * UART_interface.h
 *
 *  Created on: Mar 26, 2021
 *      Author: AHMAD SABRY
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/**********************************************/
/**************public definitions*************/
/*********************************************/

#define BAUD 9600
#define BAUDRATE (((F_CPU)/(BAUD*16UL))-1)

/**********************************************/
/**************public functions*************/
/*********************************************/

void UART_vidInit(void);

void UART_Transmit(u8 Byte);

u8 UART_Receive(void);

#endif /* UART_INTERFACE_H_ */
