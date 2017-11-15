
cmake_minimum_required(VERSION 3.8)
project(wpi-cpp)

macro(PROJECT_STATUS MSG)
    message(STATUS "wpi-cpp: ${MSG}")
endmacro()

# Sanity check for toolchain
PROJECT_STATUS("sanity checking toolchain configuration...")
PROJECT_STATUS("toolchain file  = ${CMAKE_TOOLCHAIN_FILE}")
PROJECT_STATUS("sysroot         = ${CMAKE_SYSROOT}")

# Misc toolchain options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# CMake utils
include(cmake-utils/macros.cmake)
# cross platform header files (usually synced with RPi using rsync)
include_directories(${CMAKE_SYSROOT}/usr/local/include)
# project includes
include_directories(src src/wpi-cpp/common)

# wpi-cpp library
set(SPI_SRC
        src/wpi-cpp/io/spi.cpp src/wpi-cpp/io/spi.h
        src/wpi-cpp/io/digital_in.cpp
        src/wpi-cpp/io/digital_in.h
        src/wpi-cpp/io/digital_out.cpp
        src/wpi-cpp/io/digital_out.h
        src/wpi-cpp/io/io.cpp
        src/wpi-cpp/io/io.h)
add_library(wpi-cpp ${SPI_SRC})
target_link_libraries(wpi-cpp wiringPi pthread)
# export library includes
target_include_directories(wpi-cpp PUBLIC src)

# Examples
set(BUILD_EXAMPLES CACHE BOOL OFF)
if (BUILD_EXAMPLES)
    PROJECT_STATUS("adding example programs...")
    add_subdirectory(src/example)
else ()
    PROJECT_STATUS("examples disabled")
endif ()



