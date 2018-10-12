/*
* Copyright (c) 2018, Shawn D'silva <shawn.dsilva_97@protonmail.com>
* All rights reserved.
*
*  This file is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
*
* File:			UART.h
* Author:		Shawn D'silva <https://shawn-dsilva.github.io>.
* Version:		1.0.0.
* Description:	File containing register definitions and function declarations for UART serial communications
                Implementations in UART.c
*/

#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define UART0_DR_R              (*((volatile unsigned long *)0x4000C000))
#define UART0_FR_R              (*((volatile unsigned long *)0x4000C018))
#define UART0_IBRD_R            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD_R            (*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH_R            (*((volatile unsigned long *)0x4000C02C))
#define UART0_CTL_R             (*((volatile unsigned long *)0x4000C030))
#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART_LCRH_WLEN_8        0x00000060  // 8 bit word length
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART_CTL_UARTEN         0x00000001  // UART Enable
#define SYSCTL_RCGC1_R          (*((volatile unsigned long *)0x400FE104))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC1_UART0      0x00000001  // UART0 Clock Gating Control
#define SYSCTL_RCGC2_GPIOA      0x00000001  // port A Clock Gating Control

//ASCII Non printing characters
#define CR   0x0D
#define LF   0x0A
#define BS   0x08
#define SP   0x20

void UART_Setup(void);
/* 
 * DESCRIPTION : Initialize the UART for 115,200 bps,50Mhz clock,8N1
 * PARAMS: none
 * RETURN: none
 */


unsigned char RxChar(void);
/* 
 * DESCRIPTION : Recieves PARAMS of one char from serial connection
 * PARAMS: none
 * RETURN : single byte ASCII character code
 */

void TxChar(unsigned char data);
/*
 * DESCRIPTION : Transmits single byte char to serial port
 * PARAMS: char data is a single byte ASCII character port to be transmitted
 * RETURN: none
 */

void RxString(char *bufferPt, unsigned short max);
/* 
 * DESCRIPTION :  Receives ASCII characters from serial connection
 * appends them to a string till it encounters Enter or the value of short max is reached.
 * prints characters back to the serial console output. as they are typed in.
 * if a backspace character is received the string is modified on the Launchpad and the backspaced character
   is deleted from serial console output.
 * string is 0/ null terminated
 * PARAMS : pointer to buffer,length of buffer
 * RETURN : none
 */

void TxString(char *pt);
/*
 * DESCRIPTION : Transmits string through serial connection
 * PARAMS: pointer to a null-terminated string to be transferred
 * RETURN: none
*/

void Newline(int n);
/*
 * DESCRIPTION : Prints a new line
 * PARAMS: int n,which specifies what to RETURN,1 puts out a new line,2 puts out a single empty line,3 puts out two empty lines and so on
 * RETURN: none
 */