cmake_minimum_required(VERSION 3.8)
project(wpi-cpp)

# Sanity check for toolchain
message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "Sysroot: ${CMAKE_SYSROOT}")
# Misc toolchain options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

include(cmake-utils/macros.cmake)
include_directories(${CMAKE_SYSROOT}/usr/local/include)
include_directories(src)

# wpi-cpp library
set(SPI_SRC
        src/io/spi.cpp src/io/spi.h
        src/io/logger.h src/io/logger.cpp
        src/io/digital_in.cpp
        src/io/digital_in.h
        src/io/digital_out.cpp
        src/io/digital_out.h
        src/io/io.cpp
        src/io/io.h)
add_library(wpi-cpp ${SPI_SRC})
target_link_libraries(wpi-cpp wiringPi pthread)

# Examples
set(BUILD_EXAMPLES CACHE BOOL OFF)
if (BUILD_EXAMPLES)
    message(STATUS "BUILD_EXAMPLES = ON, example programs will be built.")
    add_subdirectory(src/example)
else ()
    message(STATUS "BUILD_EXAMPLES = OFF, example programs will be skipped.")
endif ()



