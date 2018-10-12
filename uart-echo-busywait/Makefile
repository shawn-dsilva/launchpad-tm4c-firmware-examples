#
# Copyright (c) 2018, Shawn D'silva <shawn.dsilva_97@protonmail.com>
# All rights reserved.
#
#  This file is free software: you can redistribute it and/or modify
 # it under the terms of the GNU Lesser General Public License as published by
 # the Free Software Foundation, either version 3 of the License, or
 # (at your option) any later version.
 #
 # This file is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public License
 # along with this library.  If not, see <http://www.gnu.org/licenses/>.
#
# File:			Makefile
# Author:		Shawn D'silva <https://shawn-dsilva.github.io>.
# Version:		1.0.0.
# Description:	Makefile used to build files for this program


# TARGET: name of the output file
TARGET = main
# MCU: part number to build for
MCU = TM4C123GH6PM
#DEV : your TM4C123GH6PM when connected to your system,usually will be /dev/ttyACM0
DEV = /dev/ttyACM0
# SRC: all source files from src directory
SRC = $(wildcard src/*.c)
# OBJ: directory to put objects and all other intermediate files
OBJ = obj
# LD_SCRIPT: linker script
LD_SCRIPT = ld/$(MCU).ld


#PREPROCESSOR FLAGS
CPPFLAGS += -Iinc #inc folder is where header files are

#GCC FLAGS
CFLAGS = -g -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
CFLAGS +=-Os -ffunction-sections -fdata-sections -MD -std=c99     #you can add  -Wall here if you wish,that prints annoying warnings to the screen
CFLAGS += -pedantic -DPART_$(MCU) -c 
CFLAGS += -DTARGET_IS_BLIZZARD_RA1

#LINKER FLAGS
LDFLAGS = -T $(LD_SCRIPT) --entry ResetISR --gc-sections

#UTILITY VARIABLES
CC = arm-none-eabi-gcc #compiler
LD = arm-none-eabi-ld #linker
OBJCOPY = arm-none-eabi-objcopy #final executable builder
FLASHER = lm4flash #flashing utility
RM      = rm -f
MKDIR	= mkdir -p

# list of object files
OBJECTS = $(addprefix $(OBJ)/,$(notdir $(SRC:.c=.o)))

# Rules to build bin

all: $(TARGET).bin

$(OBJ)/%.o: src/%.c | $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(CFLAGS)

$(OBJ)/$(TARGET).out: $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

$(TARGET).bin: $(OBJ)/$(TARGET).out
	$(OBJCOPY) -O binary $< $@

# create directory for object files if not already present
$(OBJ):
	$(MKDIR) $(OBJ)


#Flashes bin to TM4C
flash:
	$(FLASHER) -S $(DEV) $(TARGET).bin 

#remove object files
clean:
	-$(RM) $(OBJ)/*
	-$(RM) $(TARGET).bin

.PHONY: all clean
