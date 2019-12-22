cmake_minimum_required(VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/../cmake-embedded/Toolchains/avr-gcc.cmake")

project(AVR_Blink_Example)

## Target the project to the MCU
avr_configure("atmega328p")

## Declare the clock speed project-wide
add_definitions(-DF_CPU=16000000L)

add_executable(blink
    "blink.c"
)

_avr_build_firmware(blink PRINT_SIZE)
_avr_add_upload_target(upload_blink blink
    PORT "/dev/ttyUSB0"
    BAUDRATE 57600
    PROGRAMMER arduino
)
