# NOTE: you must either name your main file ending in .ino
# 	or #include <Arduino.h> 
# 	for things to compile correctly.

BOARD_TAG=uno
ARDUINO_PORT=/dev/ttyACM*
ARDUINO_DIR=/usr/share/arduino
ARDMK_DIR=../Arduino-Makefile
AVRDUDE_PATH=/usr/share/arduino/hardware/tools
AVRDUDE=$(AVRDUDE_PATH)/avrdude
AVRDUDE_CONF=$(AVRDUDE_PATH)/avrdude.conf

SKETCHBOOK_DIR=~/sketchbook

include ../Arduino-Makefile/arduino-mk/Arduino.mk

install:
	mkdir -p $(SKETCHBOOK_DIR)/libraries/troika
	cp -r * $(SKETCHBOOK_DIR)/libraries/troika/

.PHONY: install

