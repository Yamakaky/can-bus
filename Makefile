# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

BOARD_TAG := uno
ARDMK_VENDOR := archlinux-arduino
ARDUINO_LIBS := SPI CAN_BUS
USER_LIB_PATH := $(realpath libraries)

CXXFLAGS += -Wall -Wextra

include /usr/share/arduino/Arduino.mk
