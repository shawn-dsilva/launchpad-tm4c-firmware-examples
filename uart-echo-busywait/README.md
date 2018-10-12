
## About

Simple program that prints whatever string you send to the TM4C back to your serial console prompt
Tested to work on Ubuntu 18.04 LTS

## Usage

- Connect your board to your PC
 - Run `make`
 - Run `sudo make flash` to flash the main.bin to TM4C board
 - Use PuTTY,`minicom`,GNU `screen` or any other serial console to communicate with your TM4C board
 - Run `sudo putty` ,otherwise putty will not be ably to connect with your Launchpad
 - On PuTTY click the "Serial" circle check box under "connection type",enter `/dev/ttyACM0` as the "Serial Line" and `115200` as the baud rate and click open
 - In case `/dev/ttyACM0` is not the address of your board run `dmesg | tail`to find out.
 - Press the `RESET` button on your board
 - Type text into the prompt,and the TM4C Launchpad should print it back to the screen



 - Run `make clean` to delete all object and .bin files.
