
message(STATUS "Configuring example programs...")

set(SPI_EX_SRC spi_main.cpp)
add_executable(SPIExample ${SPI_EX_SRC})
target_link_libraries(SPIExample wpi-cpp)

# Deploy to RPi
SCP_DEPLOY(SPIExample)
