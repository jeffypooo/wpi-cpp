cmake_minimum_required(VERSION 3.8)
set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
message("System Root: ${CMAKE_SYSROOT}")

project(spi_host)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES main.cpp)
add_executable(spi_host ${SOURCE_FILES})
target_link_libraries(spi_host)