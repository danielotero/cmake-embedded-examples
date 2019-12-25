cmake_minimum_required(VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/../cmake-embedded/Toolchains/avr-gcc.cmake")

project(AVR_Blink_Example)

## Declare the clock speed project-wide
add_definitions(-DF_CPU=16000000L)

add_avr_firmware(blink
    "blink.c"
    MCU "atmega328p"
    PRINT_SIZE
)

add_avr_upload_target(upload_blink
    TARGET blink
    PORT "/dev/ttyUSB0"
    BAUDRATE 57600
    PROGRAMMER arduino
)
