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
include sources.mk              #including the sources.mk file

# Platform Overrides
PLATFORM = HOST                 #defining default platform and other variables
TARGET = c1m2.out
INC = $(INCLUDES)
MAP = $(TARGET).map

# Compiler Flags and Defines

ifeq ($(PLATFORM), HOST)                                         #flags and defines for host platform
	OBJS = main.o memory.o
	CC = gcc
	LD = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST $(INC) -MD -MP -MF $(@:.o=.dep)
else                                                             #flags and defines for msp432 platform
	OBJS = $(SOURCES:.c=.o)
	LINKER_FILE = ../msp432p401r.lds                             
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 \
			 -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CPPFLAGS = -DMSP432 $(INC) -MD -MP -MF $(@:.o=.dep)
	LDFLAGS = --specs=$(SPECS) -T$(LINKER_FILE) -Wl,-Map=$(MAP)

endif

.PHONY: compile-all build clean                                   #defining required phonies

build: $(TARGET)

compile-all: $(OBJS)

clean:                                                            #rule for clean phony
	rm -f *.i *.o *.asm *.map *.out *.dep *.d

%.i: %.c                                                          #rule for generating .i files
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $< -o $@

%.asm: %.c                                                        #rule for generating .asm file
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $< -o $@

%.o: %.c                                                          #rule for generating .o file
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJS)                                                #rule to build completely and generate the required files
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -o $@