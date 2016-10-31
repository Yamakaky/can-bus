# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

BOARD_TAG := uno
ARDMK_VENDOR := archlinux-arduino

CXXFLAGS += -Wall -Wextra

include /usr/share/arduino/Arduino.mk
