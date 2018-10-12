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
* File:			UART.c
* Author:		Shawn D'silva <https://shawn-dsilva.github.io>.
* Version:		1.0.0.
* Description:	File containing implementation of UART setup and UART text transmit and receive 
                functions documented in UART.h
*/


#include "UART.h"

void UART_Setup(void){
  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART0; // activate UART0
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA; // activate port A
  UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART for below setup
  UART0_IBRD_R = 27;                    // IBRD = int(50,000,000 / (16 * 115,200)) = int(27.1267)
  UART0_FBRD_R = 8;                     // FBRD = int(0.1267 * 64 + 0.5) = 8
  //115200 bps baudrate 
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
  UART0_CTL_R |= UART_CTL_UARTEN;       // enable UART
  GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1-0
  GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011; // configure PA1-0 as UART
  GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA
}

unsigned char RxChar(void){
  while((UART0_FR_R&UART_FR_RXFE) != 0);//while the Recieve FIFO is not empty
  return((unsigned char)(UART0_DR_R&0xFF));
}

void TxChar(unsigned char data){
  while((UART0_FR_R&UART_FR_TXFF) != 0);//while the Transmit FIFO is not full
  UART0_DR_R = data;
}


void RxString(char *bufferPt, unsigned short max) {
int length=0;
char character;
  character = RxChar();
  while(character != CR){ //CR means Enter/Return
    if(character == BS){  //if char is a backspace
      if(length){
        bufferPt--;          //decrement the buffer pointer and length
        length--;
        TxChar(BS);  //output backspace character to remove the previously typed character
      }
    }
    else if(length < max){
      *bufferPt = character; //make buffer pointer take the input from InChar()
      bufferPt++;//advance to the next character
      length++;
      TxChar(character);//print the inputted character
    }
    character = RxChar();//get value of character from InChae
  }
  *bufferPt = 0;
}


void TxString(char *pt){
  while(*pt){
    TxChar(*pt); //outputs string one char at a time
    pt++;
  }
}

void Newline(int n){
  int i = 0;
  while(i < n) {
  TxChar(CR);
  TxChar(LF);
  i++;
  }
}