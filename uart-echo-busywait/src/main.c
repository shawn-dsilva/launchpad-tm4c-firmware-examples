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
* File:			main.c
* Author:		Shawn D'silva <https://shawn-dsilva.github.io>.
* Version:		1.0.0.
* Description:	Main file.
*/

#include "PLL.h"
#include "UART.h"

int main(void){
  char string[100];  

  PLL_Setup();                //initialize PLL
  UART_Setup();              // initialize UART

  Newline(1);
  TxString("+-----------------------------------------------------------------------+");
  Newline(2);
  TxString("    This is UART-Echo,type something and hit enter to see it printed on screen   ");
  Newline(2);
  TxString("+-----------------------------------------------------------------------+");
  Newline(2);


  while(1){
    TxString("You > ");
    RxString(string,100);
    Newline(1);
    TxString("Launchpad > "); 
    TxString(string); 
    Newline(2);
  }
}
