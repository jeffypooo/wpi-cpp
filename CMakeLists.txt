cmake_minimum_required(VERSION 3.8)
project(RPi-SPI)

# Sanity check for toolchain
message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "Sysroot: ${CMAKE_SYSROOT}")
# Misc toolchain options
set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SYSROOT}/usr/local/include)

# spihost sources
set(SPI_SRC src/io/spi.cpp src/io/spi.h src/io/logger.h src/io/logger.cpp)
add_library(rpispi ${SPI_SRC})
target_link_libraries(rpispi wiringPi pthread)

add_subdirectory(src/example)



