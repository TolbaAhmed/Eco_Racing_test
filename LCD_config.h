/*
 * LCD_config.h
 *
 *  Created on: Jan 23, 2021
 *      Author: AHMAD SABRY
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/******************************************/
/*****PORT/PINs configurationsfor LCD******/
/******************************************/
/* Description: LCD DATA port configuration */
/* Range      : DIO_u8PORTA ~ DIO_u8PORTD */
#define LCD_DATA_PORT	DIO_PORTB

/* Description: LCD control port configurations */
/* Range      : DIO_u8PORTA ~ DIO_u8PORTD */
#define LCD_CONTROL_PORT	DIO_PORTA

/* Description: LCD RS pin */
/* Range      : DIO_u8PIN0 ~ DIO_u8PIN7 */
#define LCD_RS_PIN	DIO_PIN7

/* Description: LCD RW pin */
/* Range      : DIO_u8PIN0 ~ DIO_u8PIN7 */
#define LCD_RW_PIN	DIO_PIN6

/* Description: LCD E pin */
/* Range      : DIO_u8PIN0 ~ DIO_u8PIN7 */
#define LCD_E_PIN	DIO_PIN5


#endif /* LCD_CONFIG_H_ */
