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
* Description:	File containing implementation of PLL setup function documented in PLL.h

*/

#include "PLL.h"

// configure the system to get its clock from the PLL
void PLL_Setup(void){
  SYSCTL_RCC2_R |= SYSCTL_RCC2_USERCC2;   // deactivate  PLL while initializing
  SYSCTL_RCC2_R |= SYSCTL_RCC2_BYPASS2;   //select the crystal value and oscillator source
  SYSCTL_RCC_R &= ~SYSCTL_RCC_XTAL_M;   //clear XTAL field
  SYSCTL_RCC_R += SYSCTL_RCC_XTAL_16MHZ;// configure for 16 MHz crystal
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_OSCSRC2_M;// clear oscillator source field
  SYSCTL_RCC2_R += SYSCTL_RCC2_OSCSRC2_MO;// configure for main oscillator source
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_PWRDN2; // activate PLL by clearing PWRDN
  SYSCTL_RCC2_R |= SYSCTL_RCC2_DIV400;  // use 400 MHz PLL
  SYSCTL_RCC2_R = (SYSCTL_RCC2_R&~0x1FC00000) // clear system clock divider field
                  + (SYSDIV2<<22);      // configure for 80 MHz clock
  while((SYSCTL_RIS_R&SYSCTL_RIS_PLLLRIS)==0){};   // wait for the PLL to lock by polling PLLLRIS
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_BYPASS2;//enable use of PLL by clearing BYPASS
}
