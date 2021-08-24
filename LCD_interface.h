/*
 * LCD_interface.h
 *
 *  Created on: Jan 23, 2021
 *      Author: AHMAD SABRY
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/**********************************************/
/**************public definitions*************/
/*********************************************/

#define LCD_CLR					0x01
#define LCD_HOME				0x02
#define LCD_ENTRYMODE			0x06
#define LCD_DISPOFF				0x08
#define LCD_DISPON_CURSON		0x0E
#define LCD_FUNCRESET			0x30
#define LCD_FUNCSET_8BIT		0x38
#define LCD_SETCURSOR			0xB0
#define LCD_DISPON_CURSBLINK	0x0F
#define LCD_DISPON_CURSOFF		0x0C

#define LCD_LINE1				0x80
#define LCD_LINE2				0xC0

/**********************************************/
/**************public functions*************/
/*********************************************/

void LCD_vidInit(void);

void LCD_vidSendCommand(u8 u8Cmd);

void LCD_vidSendChar(u8 u8Char);

void LCD_vidWriteStr(u8* pu8Str);

void LCD_vidWriteInt(u16 Num);

void LCD_vidLoadNewChar(void);




#endif /* LCD_INTERFACE_H_ */
