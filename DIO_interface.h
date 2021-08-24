/*
 * DIO_interface.h
 *
 *  Created on: Jan 22, 2021
 *      Author: AHMAD SABRY
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/************************************************/
/********************public functions************/
/************************************************/

void DIO_vidSetPinVal(u8 Portid, u8 Pinid, u8 PinVal);
void DIO_vidSetPinDir(u8 Portid, u8 Pinid, u8 PinDir);
void DIO_vidSetPortVal(u8 Portid, u8 PortVal);
void DIO_vidSetPortDir(u8 Portid, u8 PortDir);
u8 DIO_u8GetPinVal(u8 Portid, u8 Pinid);



/************************************************/
/*******************public macros****************/
/************************************************/

/*Output status*/
#define DIO_HIGH	1
#define DIO_LOW		0

#define DIO_PORT_HIGH	0xff
#define DIO_PORT_LOW	0x00
/*Direction status*/
#define DIO_INPUT	0
#define DIO_OUTPUT	1

#define DIO_PORT_IN		0x00
#define DIO_PORT_OUT	0xff
/*Port IDs*/
#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3
/*Pins IDs*/
#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7


#endif /* DIO_INTERFACE_H_ */
