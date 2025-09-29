#MAKEFLAGS += --no-builtin-rules

include sources.mk

PLATFORM = MSP432
TARGET = c1m3.out
MAP = $(TARGET).map
OBJS = $(SOURCES:.c=.o)
LINKER_FILE = msp432p401r.lds  

CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16
CPPFLAGS = -DMSP432 $(INCLUDES) 
LDFLAGS = --specs=$(SPECS) -T$(LINKER_FILE) -Wl,-Map=$(MAP)

.PHONY: build clean                                   #defining required phonies

build: $(TARGET)

clean:                                                            #rule for clean phony
	rm -f *.i *.o *.asm *.map *.out *.dep *.d *.txt

%.o: %.c                                                          #rule for generating .o file
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJS)                                                #rule to build completely and generate the required files
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -o $@
	size $@