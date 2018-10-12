TM4C Firmware Examples
==================

## About

This repository is a collection of firmware code written by me for the TM4C123GH6PM microcontroller evaluation board by TI.
This repository will contain code making use of UART,SPI,I2C,ADC,DAC,PWM and Interrupts


## Usage

 - Follow the instructions in [this repo's ](https://github.com/shawn-dsilva/tm4c-linux-template)README for setting up a cross-compilation toolchain on Ubuntu 18.04 LTS
 - clone this repo 
     `git clone https://github.com/shawn-dsilva/launchpad-tm4c-firmware-examples`
  - `cd` to whatever example you want to run e.g 
	     `cd launchpad-tm4c-firmware-examples/uart-echo-busywait`
 - Run `make`
 - Run `sudo make flash` to flash the main.bin to TM4C board
 - Consult the README for any example for further instructions specific to it.
 - Run `make clean` to delete all object and .bin files.
