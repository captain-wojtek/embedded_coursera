#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
OBJS = $(SOURCES:.c=.o)
TARGET = main.out

# Compiler Flags and Defines

ifeq ($(PLATFORM), HOST)
	CC = gcc
	LD = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST
else
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 \
			 -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CPPFLAGS = -DMSP432
	LDFLAGS = --specs=$(SPECS) -T$(LINKER_FILE)

endif

.PHONY = compile-all build clean

build: $(TARGET)

compile-all: $(OBJS)

clean: 
	rm -f *.i *.o *.asm *.map *.out

%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $< -o $@

%.asm: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@