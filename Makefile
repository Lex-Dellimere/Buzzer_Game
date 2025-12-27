##
# Project Title
#
# @file
# @version 0.1

PROJECT = BuzGame
MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=%.o)

all: clean flash

flash: $(PROJECT).hex
	@echo "Flashing $(PROJECT) to $(MCU)"
	@avrdude -F -V -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -e -U flash:w:$<
	@$(MAKE) clean

$(PROJECT).hex: $(PROJECT).elf
	@echo "Generating HEX..."
	@$(OBJCOPY) -O ihex -R .eeprom $< $@

$(PROJECT).elf: $(OBJ)
	@echo "Generating ELF..."
	@$(CC) -mmcu=$(MCU) $^ -o $@

%.o: src/%.c
	@echo "Compiler source files..."
	@$(CC) -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c $< -o $@

keep: $(PROJECT).hex
	@echo "Keeping artifacts..."
	@avrdude -F -V -c arduino -p $(MCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$<

clean:
	@echo "Cleaning..."
	@rm -f *.o *.elf *.hex

.PHONY: all clean flash keep


# end
